#include <wiringPi.h>
#include <iostream>
#include "RaspOutputController.h"
#include "Sample.h"
#include "DrumMachine.h"

using namespace state;
using namespace sample;

RaspOutputController::RaspOutputController() : beatBlinkDelay(0) {
    this->initializePins();
    this->switchOffAllLed();
    this->switchOnFirstBeatLed();
};

void RaspOutputController::initializePins() {
    map<unsigned short, unsigned short>::const_iterator it;
    for (it = this->outputPinMap.begin(); it != this->outputPinMap.end(); it++) {
        pinMode(it->second, OUTPUT);
    }
}

void RaspOutputController::positionChange(unsigned short newPosition) {
    thread tLed([this, newPosition]() {
        this->blink(this->outputPinMap.at(this->greenLedList.at((unsigned long) newPosition)));
    });
    tLed.detach();
};

void RaspOutputController::switchOnFirstBeatLed() {
    digitalWrite(this->outputPinMap.at(BEAT1_BLUE), 1);
    digitalWrite(this->outputPinMap.at(BEAT5_BLUE), 1);
    digitalWrite(this->outputPinMap.at(BEAT9_BLUE), 1);
    digitalWrite(this->outputPinMap.at(BEAT13_BLUE), 1);
}

void RaspOutputController::switchOffAllRedBeatLeds() {
    for (unsigned short led : this->redLedList) {
        digitalWrite(this->outputPinMap.at(led), LOW);
    }
}

void RaspOutputController::switchOffAllLed() {
    map<unsigned short, unsigned short>::const_iterator it;
    for (it = this->outputPinMap.begin(); it != this->outputPinMap.end(); it++) {
        pinMode(it->second, OUTPUT);
        this->blink(it->second);
    }
}

void RaspOutputController::blink(int ledPin) {
    digitalWrite(ledPin, HIGH);
    delay(this->beatBlinkDelay);
    digitalWrite(ledPin, LOW);
}

void RaspOutputController::activeSampleChange(unsigned short newActiveSample, unsigned short oldActiveSample) {
    if (oldActiveSample != NO_SAMPLE) {
        digitalWrite(this->outputPinMap.at(this->sampleLedList.at(oldActiveSample)), LOW);
    }
    if (newActiveSample != NO_SAMPLE) {
        digitalWrite(this->outputPinMap.at(this->sampleLedList.at(newActiveSample)), HIGH);
    }
    if (newActiveSample == NO_SAMPLE) {
        switchOffAllRedBeatLeds();
        switchOnFirstBeatLed();
    }
}

void RaspOutputController::playPositionChange(vector<unsigned short> &newPlayArray) {
    short unsigned i;
    for (i = 0; i < newPlayArray.size(); i++) {
        this->playPositionChange(i, newPlayArray.at(i));
    }
}

void RaspOutputController::playPositionChange(unsigned short position, unsigned short playState) {
    if (playState == PLAY) {
        digitalWrite(this->outputPinMap.at(this->redLedList.at(position)), HIGH);
        digitalWrite(this->outputPinMap.at(this->blueLedList.at(position)), LOW);
    } else if (playState == MUTE) {
        digitalWrite(this->outputPinMap.at(this->redLedList.at(position)), LOW);
        if (position == 0 | position == 4 | position == 8 | position == 12)
            digitalWrite(this->outputPinMap.at(this->blueLedList.at(position)), HIGH);
    }
}

void RaspOutputController::setBeatDuration(unsigned int beatDuration) {
    this->beatBlinkDelay = beatBlinkDelay;
}

void RaspOutputController::showMainScreen(unsigned int bpm) {
    display.showMainScreen(bpm);
}

void RaspOutputController::showSampleScreen(unsigned int bpm, float volume) {
    display.showSampleScreen(bpm, volume);
}
