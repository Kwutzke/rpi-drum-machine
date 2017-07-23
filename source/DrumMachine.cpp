#include <SDL2/SDL.h>
#include <chrono>
#include <iostream>
#include "DrumMachine.h"

using namespace std::chrono;
using namespace std;
using namespace sample;

DrumMachine::DrumMachine(AOutputController &outputController) : loopRunning(false), currentBeat(0), volume(1),
                                                                    outputController(outputController),
                                                                    loop(beatMillis,
                                                                         (int) LOOP_PRECISION_NANOS),
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
        // Set the interval for the timer
        loop.setInterval(beatMillis);
        loop.start([this]() {
            // play samples, let them determine if they are active on the current beat
            for (size_t i = 0; i < samples.size(); i++) {
                this->samples.at(i).playSample(currentBeat);
            }

            // Fire event
            this->outputController.positionChange(currentBeat);

            // next beat
            currentBeat++;
            if (currentBeat == TOTAL_BEATS) {
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

void DrumMachine::setBPM(unsigned short bpm) {
    if (bpm >= this->MIN_BPM && bpm <= this->MAX_BPM) {
        this->bpm = bpm;
        this->beatMillis = static_cast<unsigned int>(60000 / bpm / BEATS_PER_WHOLE_BEAT);
        // The timer needs to be updated
        this->loop.setInterval(beatMillis);
        // Fire events
        this->outputController.setBeatDuration((unsigned int) (beatMillis * .8f));
        this->outputController.showMainScreen(bpm);
    }
}

unsigned short DrumMachine::getBPM() {
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

bool DrumMachine::isLoopRunning() {
    return loopRunning;
}

void DrumMachine::setActiveSample(unsigned short newActiveSample) {
    // Check if samples were deselected
    if (newActiveSample == this->activeSample) {
        newActiveSample = NO_SAMPLE;
        this->outputController.showMainScreen(getBPM());
    }

    // Fire events for the change
    this->outputController.activeSampleChange(newActiveSample, this->activeSample);
    this->activeSample = newActiveSample;

    if (newActiveSample >= this->samples.size()) {
        cout << "WARNING: No Sample " << newActiveSample << "found!" << endl;
    } else {
        // Fire more events
        cout << "Old active sample: " << this->activeSample << " new active sample: " << newActiveSample << endl;
        this->outputController.playPositionChange(this->samples.at(this->activeSample).getPlayArray());
        this->outputController.showSampleScreen(getBPM(), this->samples.at(this->activeSample).getVolume());
    }
}

void DrumMachine::toggleSampleAtBeat(unsigned short beat) {
    if (this->activeSample != NO_SAMPLE) {
        // Store the new information in the active sample
        this->samples.at(activeSample).togglePlayAtBeat(beat);
        // Fire events
        this->outputController.playPositionChange(beat, this->samples.at(this->activeSample).getPlayArray().at(beat));
    } else {
        // When no samples are active, beat buttons function as preview for each sample
        if (beat >= 0 && beat < this->samples.size()) {
            this->samples.at(beat).play();
        }
    }
}

unsigned short DrumMachine::getActiveSample() {
    return this->activeSample;
}

void DrumMachine::increaseBpm(unsigned short value) {
    setBPM(getBPM() + value);
}
