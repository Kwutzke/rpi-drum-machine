#include "RaspInputController.h"

RaspInputController::RaspInputController() : pollingTimer(1000, 20000) {
    initializePins();
}

void RaspInputController::initializePins() {
    // ToDo initialize pins
}

void RaspInputController::startPolling() {
    Timer pollingTimer(1000, 20000); // 2ms polling rate
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
    // ToDo poll inputs from pi

    vector<unsigned short> events;
    events.push_back(inputs::START_STOP_BUTTON);
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
