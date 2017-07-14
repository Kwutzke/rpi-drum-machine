//
// Created by Kilian Wutzke on 10.07.17.
//
#include "LedController.h"

LedController::LedController() {
    wiringPiSetup();
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);
    pinMode(1, OUTPUT);
    digitalWrite(1, LOW);
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
    pinMode(3, OUTPUT);
    digitalWrite(3, LOW);
};

void LedController::positionChange(int newPosition){
    thread tLed ([this, newPosition]() {
        int shortedPosition = newPosition%32;
        switch(shortedPosition) {
            case 0:
                this->blink(0);
                break;
            case 8:
                this->blink(1);
                break;
            case 16:
                this->blink(2);
                break;
            case 24:
                this->blink(3);
                break;
            default:
                return;
        }
    });

    tLed.detach();
};

void LedController::blink(int ledPosition) {
    digitalWrite(ledPosition, HIGH);
    delay(500);
    digitalWrite(ledPosition, LOW);
}

void LedController::bpmChange(int newBpm) {

}

void LedController::volumeChange(int newVolume) {

}

void LedController::activeSampleChange(int newActiveSample) {

}

void LedController::samplePlayPositionChange(vector<int> &newPlayArray) {

}
