#include <SDL2/SDL.h>
#include <chrono>
#include <iostream>
#include "DrumMachine.h"
#include "Timer.h"

using namespace std::chrono;
using namespace std;

DrumMachine::DrumMachine(RaspOutputController raspOutputController) : loopRunning(false), currentBeat(0), volume(1), outputController(raspOutputController) {
    this->openAudio();
    this->allocateChannels();
}

void DrumMachine::openAudio() {
    SDL_Init(SDL_INIT_AUDIO);

    int result = Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);
    if (result < 0) {
        fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
        exit(-1);
    }
}

void DrumMachine::allocateChannels() {
    int result = Mix_AllocateChannels(8);
    if (result < 0) {
        fprintf(stderr, "Unable to allocate mixing channels: %s\n", SDL_GetError());
        exit(-1);
    }
}

void DrumMachine::loop() {
    const long PRECISION_NANOS = 10000; // 10ms
    Timer timer(sixteenthNoteMillis, PRECISION_NANOS);
    timer.start([this] () {
        for (size_t i = 0; i < samples.size(); i++) {
            this->samples.at(i).playSample(currentBeat);
        }

        // next beat
        currentBeat++;
        if (currentBeat >= TOTAL_BEATS * TOTAL_LOOPS) {
            currentBeat = 0;
        }
    });

}

void DrumMachine::increaseVolume(float value) {
    if (volume + value >= 1) {
        setMasterVolume(1);
    } else if (volume + value <= 0) {
        setMasterVolume(0);
    } else {
        setMasterVolume(volume + value);
    }
}

void DrumMachine::toggleLoop() {
    if (isLoopRunning()) {
        stopLoop();
    } else {
        startLoop();
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
    this->sixteenthNoteMillis = 60000 / bpm / 16;
}

int DrumMachine::getBPM() {
    return this->bpm;
}

void DrumMachine::setMasterVolume(float volume) {
    if (volume >= 1) {
        this->volume = 1;
    } else if (volume <= 0) {
        this->volume = 0;
    } else {
        this->volume = volume;
    }
    for (unsigned short i = 0; i < samples.size(); i++) {
        samples.at(i).setMasterVolume(volume);
    }
}

float DrumMachine::getMasterVolume() {
    return this->volume;
}

void DrumMachine::addSample(Sample sample) {
    sample.setMasterVolume(volume);
    this->samples.push_back(sample);
}

void DrumMachine::addSamples(vector<Sample> samples) {
    for (unsigned short i = 0; samples.size(); i++) {
        addSample(samples[i]);
    }
}

bool DrumMachine::isLoopRunning() {
    return loopRunning;
}

void DrumMachine::setOutputController(RaspOutputController outputController) {
    this->outputController = outputController;
}
