#include <wiringPi.h>
#include "RaspInputController.h"

RaspInputController::RaspInputController() : pollingTimer(1000, 20000), rotaryPollingTimer(10, 20000) {
    initializePins();
}

void RaspInputController::initializePins() {
    map<unsigned short, unsigned short>::iterator it;
    for (it = this->outputMap.begin(); it != this->outputMap.end(); it++) {
        try {
            pinMode(it->second, INPUT);
            pullUpDnControl(it->second, PUD_UP);
        } catch (int e) {
            cout << "WARNING: Can't find pin " + it->second << endl;
        }
    }
}

void RaspInputController::startPolling() {
    Timer pollingTimer(100, 20000); // 100ms polling rate, 2ms precision
    cout << "Starting to poll input events ..." << endl;

    Timer rotaryPollingTimer(10, 20000);
    thread th([this]() {
        this->rotaryPollingTimer.start([this]() {
            bool volumeBpmUpButtonState = digitalRead(this->outputMap.at(VOLUME_BPM_UP_BUTTON)) == 0;
            if (volumeBpmUpButtonState != this->buttonStateMap.at(VOLUME_BPM_UP_BUTTON) && volumeBpmUpButtonState) {
                this->buttonStateMap.at(VOLUME_BPM_UP_BUTTON) = true;

                thread thu([this] () {
                    delay(200);
                    this->buttonStateMap.at(VOLUME_BPM_UP_BUTTON) = false;
                });
                thu.detach();

                for (unsigned short i = 0; i < inputListenerList.size(); i++) {
                    if (this->buttonStateMap.at(VOLUME_BPM_UP_BUTTON)) {
                        inputListenerList[i]->inputEvent(VOLUME_BPM_UP_BUTTON);
                    }
                }
            }

            bool volumeBpmDownButtonState = digitalRead(this->outputMap.at(VOLUME_BPM_DOWN_BUTTON)) == 0;
            if (volumeBpmDownButtonState != this->buttonStateMap.at(VOLUME_BPM_DOWN_BUTTON) &&
                volumeBpmDownButtonState) {
                this->buttonStateMap.at(VOLUME_BPM_DOWN_BUTTON) = true;

                thread thd([this] () {
                    delay(200);
                    this->buttonStateMap.at((VOLUME_BPM_DOWN_BUTTON)) = false;
                });
                thd.detach();

                for (unsigned short i = 0; i < inputListenerList.size(); i++) {
                    if (this->buttonStateMap.at(VOLUME_BPM_DOWN_BUTTON)) {
                        inputListenerList[i]->inputEvent(VOLUME_BPM_DOWN_BUTTON);
                    }
                }
            }
        });
    });
    th.detach();

    pollingTimer.start([this]() {
        vector<unsigned short> inputEvents = getInputEvents();
        if (inputEvents.size() > 0) {
            for (unsigned short i = 0; i < inputListenerList.size(); i++) {
                for (unsigned short j = 0; j < inputEvents.size(); j++) {
                    inputListenerList[i]->inputEvent(inputEvents[j]);
                }
            }
        }
    });
}

vector<unsigned short> RaspInputController::getInputEvents() {
    vector<unsigned short> events;
    map<unsigned short, unsigned short>::iterator it;

    for (it = this->outputMap.begin(); it != this->outputMap.end(); it++) {
        unsigned short button = it->first;
        if (button != VOLUME_BPM_UP_BUTTON && button != VOLUME_BPM_DOWN_BUTTON) {
            bool state = digitalRead(it->second) == 0;
            if (this->buttonStateMap.at(button) != state) {
                cout << "Input detected! (" << button << ")" << endl;
                this->buttonStateMap.at(button) = state;

                if (state) {
                    events.push_back(button);
                }
            }
        }
    }
    return move(events);
}

void RaspInputController::addInputListener(InputListener &listener) {
    this->inputListenerList.push_back(&listener);
}

void RaspInputController::stop() {
    pollingTimer.stop();
    rotaryPollingTimer.stop();
}

void RaspInputController::start() {
    startPolling();
}
