//
// Created by Kilian Wutzke on 10.07.17.
//
#include <wiringPi.h>
#include "LedController.h"

LedController::LedController(){
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

void LedController::blinkRhythmLed(int position) {
    thread tLed ([this, position]() {
        int shortedPosition = position%4;
        this->blink(shortedPosition);
    });
    tLed.detach();
};

void LedController::blink(int ledPosition) {
    digitalWrite(ledPosition, HIGH);
    delay(500);
    digitalWrite(ledPosition, LOW);
}
