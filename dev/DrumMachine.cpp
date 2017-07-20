
#include <chrono>
#include <iostream>
#include "DrumMachine.h"

using namespace std::chrono;
using namespace std;
using namespace sample;

DrumMachine::DrumMachine(AOutputController& raspOutputController) : loopRunning(false), currentBeat(0), volume(1),
                                                                    outputController(raspOutputController),
                                                                    loop(sixteenthNoteMillis, (int) LOOP_PRECISION_NANOS),
                                                                    activeSample(NO_SAMPLE) {
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

void DrumMachine::startLoop() {
    if (!loopRunning) {
        loopRunning = true;
        loop.setInterval(sixteenthNoteMillis);
        loop.start([this]() {
            for (size_t i = 0; i < samples.size(); i++) {
                this->samples.at(i).playSample(currentBeat);
            }

            this->outputController.positionChange(currentBeat);

            // next beat
            currentBeat++;
            if (currentBeat == 16) {
                currentBeat = 0;
            }
            cout << currentBeat << endl;
        });
    }
}

void DrumMachine::stopLoop() {
    loopRunning = false;
    loop.stop();
    this->currentBeat = 0;
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

void DrumMachine::increaseActiveSampleVolume(float volume) {
    float oldVolume = this->samples.at(this->activeSample).getVolume();
    if (oldVolume + volume >= 1) {
        this->samples.at(this->activeSample).setVolume(1.0f);
    } else if (oldVolume + volume <= 0) {
        this->samples.at(this->activeSample).setVolume(0.0f);
    } else {
        this->samples.at(this->activeSample).setVolume(oldVolume + volume);
    }
    this->outputController.showSampleScreen(getBPM(), oldVolume + volume);
}

void DrumMachine::setBPM(int bpm) {
    if (bpm >= 20 && bpm <= 220) {
        this->bpm = bpm;
        this->sixteenthNoteMillis = 60000 / bpm / 4;
        this->loop.setInterval(sixteenthNoteMillis);
        this->outputController.setBeatBlinkDelay((unsigned int) (sixteenthNoteMillis * .8f));
        this->outputController.showMainScreen(bpm);
    }
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

void DrumMachine::setActiveSample(unsigned short newActiveSample) {

    if (newActiveSample == this->activeSample) {
        newActiveSample = NO_SAMPLE;
        this->outputController.showMainScreen(getBPM());
    }

    this->outputController.activeSampleChange(newActiveSample, this->activeSample);
    this->activeSample = newActiveSample;

    if (newActiveSample >= this->samples.size()) {
        cout << "WARNING: No Sample " << newActiveSample << "found!" << endl;
    } else {
        cout << "Old active sample: " << this->activeSample << " new active sample: " << newActiveSample << endl;
        this->outputController.playPositionChange(this->samples.at(this->activeSample).getPlayArray());
        this->outputController.showSampleScreen(getBPM(), this->samples.at(this->activeSample).getVolume());
    }
}

void DrumMachine::toggleSampleAtBeat(unsigned int beat) {
    if (this->activeSample != NO_SAMPLE) {
        this->samples.at(activeSample).togglePlayAtBeat(beat);
        this->outputController.playPositionChange(beat, this->samples.at(this->activeSample).getPlayArray().at(beat));
    } else {
        if (beat >= 0 && beat < this->samples.size()) {
            this->samples.at(beat).play();
        }
    }
}

unsigned short DrumMachine::getActiveSample() {
    return this->activeSample;
}

void DrumMachine::increaseBpm(int value) {
    setBPM(getBPM() + value);
}
