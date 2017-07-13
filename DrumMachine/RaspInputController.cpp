//
// Created by Kilian Wutzke on 11.07.17.
//

#include "RaspInputController.h"
#include "Timer.h"

RaspInputController::RaspInputController() {
    initializePins();
    startPolling();
}

void RaspInputController::initializePins() {
    // ToDo initialize pins
}

void RaspInputController::startPolling() {
    thread th([this] () {
        Timer timer(1000, 20000); // 2ms polling rate
        timer.start([this] () {
            vector<unsigned short> inputEvents = getInputEvents();
            if (inputEvents.size() > 0) {
                for (unsigned short i = 0; i < inputListenerList.size(); i ++) {
                    for (unsigned short j = 0; j < inputEvents.size(); j++) {
                        inputListenerList[i]->inputEvent(inputEvents[j]);
                    }
                }
            }
        });
    });
    th.detach();
}

vector<unsigned short> RaspInputController::getInputEvents() {
    // ToDo poll inputs from pi

    vector<unsigned short> events;
    events.push_back(inputs::VOLUME_DOWN_BUTTON);
    return move(events);
}

void RaspInputController::addInputListener(InputListener &listener) {
    this->inputListenerList.push_back(&listener);
}

