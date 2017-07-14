#include <wiringPi.h>
#include <mcp23017.h>
#include <iostream>
#include "RaspOutputController.h"

RaspOutputController::RaspOutputController(){
    wiringPiSetup();
    mcp23017Setup(100, 0x20);
    mcp23017Setup(200, 0x21);
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
    if(newPosition < 8) {
        thread tLed ([this, newPosition]() {
            this->blink(this->beatPinMap.at(this->greenLedList.at((unsigned long) newPosition)));
//            cout << newPosition << endl;
        });
        tLed.detach();
    }
};

void RaspOutputController::switchOnFirstBeatLed() {
//    digitalWrite(this->beatPinMap.at(BEAT1_BLUE), 1);
//    digitalWrite(this->beatPinMap.at(BEAT5_BLUE), 1);
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

void RaspOutputController::samplePlayPositionChange(vector<int> &newPlayArray) {
    thread tLed([this, &newPlayArray]() {
        int i;
        for(i = 0; i < newPlayArray.size(); i++) {
            if (i < 8) {
                digitalWrite(this->beatPinMap.at(this->redLedList.at((unsigned long) i)), LOW);
                if (newPlayArray.at((unsigned long) i) == 1) {
                    digitalWrite(this->beatPinMap.at(this->redLedList.at((unsigned long) i)), HIGH);
                    digitalWrite(this->beatPinMap.at(this->blueLedList.at((unsigned long) i)), LOW);
                } else if (newPlayArray.at((unsigned long) i) == 0) {
                    digitalWrite(this->beatPinMap.at(this->redLedList.at((unsigned long) i)), LOW);
                    if (i == 0 | i == 4 | i == 8 | i == 12)
                        digitalWrite(this->beatPinMap.at(this->blueLedList.at((unsigned long) i)), HIGH);
                }
            }
        }
    });
    tLed.detach();
}
