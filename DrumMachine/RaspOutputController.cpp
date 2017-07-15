#include <wiringPi.h>
#include <mcp23017.h>
#include <iostream>
#include "RaspOutputController.h"
#include "Sample.h"

using namespace state;

RaspOutputController::RaspOutputController(){
    this->initializePins();
    this->switchOnFirstBeatLed();

};

void RaspOutputController::initializePins() {
    map<unsigned short, unsigned short>::const_iterator it;
    for (it = this->beatPinMap.begin(); it != this->beatPinMap.end(); it++) {
        pinMode(it->second, OUTPUT);
    }
}

void RaspOutputController::positionChange(unsigned short newPosition) {
    thread tLed ([this, newPosition]() {
        this->blink(this->beatPinMap.at(this->greenLedList.at((unsigned long) newPosition)));
    });
    tLed.detach();
};

void RaspOutputController::switchOnFirstBeatLed() {
    digitalWrite(this->beatPinMap.at(BEAT1_BLUE), 1);
    digitalWrite(this->beatPinMap.at(BEAT5_BLUE), 1);
}

void RaspOutputController::switchOfAllLed() {
    map<unsigned short, unsigned short>::const_iterator it;
    for (it = this->beatPinMap.begin(); it != this->beatPinMap.end(); it++) {
        thread tLed([this, it]() {
            pinMode(it->second, OUTPUT);
            this->blink(it->second);
        });
        tLed.detach();
    }
}

void RaspOutputController::blink(int ledPin) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
}

void RaspOutputController::ledOff(int ledPin){

}

void RaspOutputController::bpmChange(int newBpm) {

}

void RaspOutputController::volumeChange(int newVolume) {

}

void RaspOutputController::activeSampleChange(int newActiveSample) {

}

void RaspOutputController::playPositionChange(vector<unsigned short> &newPlayArray) {
    thread tLed([this, &newPlayArray]() {
    short unsigned i;
        for(i = 0; i < newPlayArray.size(); i++) {
            this->playPositionChange(i, newPlayArray.at(i));
        }
    });
    tLed.detach();
}

void RaspOutputController::playPositionChange(unsigned short position, unsigned short playState) {
    if (playState == PLAY) {
        digitalWrite(position, HIGH);
        digitalWrite(position, LOW);
    } else if (playState == MUTE) {
        digitalWrite(position, LOW);
        if (position == 0 | position == 4 | i == 8 | i == 12)
            digitalWrite(position, HIGH);
    }
}
