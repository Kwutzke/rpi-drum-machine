#include <wiringPi.h>
#include <mcp23017.h>
#include "RaspOutputController.h"

RaspOutputController::RaspOutputController(){
    wiringPiSetup();
    mcp23017Setup(0x20, 100);
    mcp23017Setup(0x21, 200);
    initializePins();
};

void RaspOutputController::initializePins() {
    map<unsigned short, unsigned short>::const_iterator it;
    for(it = this->beatPinMap.begin(); it != this->beatPinMap.end(); it++) {
        pinMode(it->second, OUTPUT);
        this->blink(it->second);
    }
}

void RaspOutputController::positionChange(unsigned short newPosition){
    thread tLed ([this, newPosition]() {
        blink(this->beatPinMap.at(newPosition));
    });

    tLed.detach();
};

void RaspOutputController::blink(int ledPosition) {
    digitalWrite(ledPosition, HIGH);
    delay(500);
    digitalWrite(ledPosition, LOW);
}

void RaspOutputController::bpmChange(int newBpm) {

}

void RaspOutputController::volumeChange(int newVolume) {

}

void RaspOutputController::activeSampleChange(int newActiveSample) {

}

//void RaspOutputController::samplePlayPositionChange(vector<int> &newPlayArray) {

//}
