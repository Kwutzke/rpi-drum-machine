#include "RaspInputController.h"

RaspInputController::RaspInputController() : pollingTimer(1000, 20000) {
    initializePins();
}

void RaspInputController::initializePins() {
    map<unsigned short, unsigned short>::iterator it;
    for (it = this->outputMap.begin(); it != this->outputMap.end(); it ++) {
        try {
            pinMode(it->second, INPUT);
            pullUpDnControl(it->second, PUD_UP);
        } catch (int e) {
            cout << "WARNING: Can't find pin " + it->second << endl;
        }
    }
}

void RaspInputController::startPolling() {
    Timer pollingTimer(10, 20000); // 2ms polling rate
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

    for (it = this->outputMap.begin(); it != this->outputMap.end(); it ++) {
        unsigned short button = it->first;
        bool state = digitalRead(it->second) == 0;
        if (this->buttonStateMap.at(button) != state) {
            this->buttonStateMap.at(button) = state;

            if (state) {
                events.push_back(button);
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
}

void RaspInputController::start() {
    startPolling();

}
