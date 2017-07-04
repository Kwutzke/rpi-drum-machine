//
// Created by fritz on 7/3/17.
//

#include <SDL2/SDL.h>
#include <chrono>
#include <iostream>

#include "DrumMachine.h"

using namespace std::chrono;
using namespace std;

DrumMachine::DrumMachine() : loopRunning(false) {
    SDL_Init(SDL_INIT_AUDIO);
    setBPM(60);
}

int getCurrentTimeMillis() {
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void DrumMachine::loop() {
    int timeElapsed;
    int lastTime = 0;
    while (loopRunning) {
        timeElapsed = getCurrentTimeMillis() - lastTime;

        if (timeElapsed >= sixteenthNoteMillis*16) {
            cout << "Beat!" << endl;
            lastTime = getCurrentTimeMillis();
        }
    }
}

void DrumMachine::startLoop() {
    loopRunning = true;
    loop();
}

void DrumMachine::stopLoop() {
    loopRunning = false;
}

void DrumMachine::setBPM(int bpm) {
    this->bpm = bpm;
    this->sixteenthNoteMillis = 60000/bpm/16;
}

int DrumMachine::getBPM() {
    return this->bpm;
}