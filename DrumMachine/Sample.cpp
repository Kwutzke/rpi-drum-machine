//
// Created by Kilian Wutzke on 27.06.17.
//
#include "Sample.h"

Sample::Sample(const char *samplePath) : playArray(64, 0), volume(1), masterVolume(1) {
    this->sampleFile = Mix_LoadWAV(samplePath);
    if (this->sampleFile == NULL) {
        fprintf(stderr, "Unable to load wave file: %s\n", samplePath);
    }
}

void Sample::playSample(int currentBeat) {
    if (this->playArray.at((unsigned long) currentBeat) == 1) {
        thread t([this]() {
            Mix_PlayChannel(-1, this->sampleFile, 0);
//            cout << "play" << endl;
        });
        t.detach();
    }
}

void Sample::preFillKickDrumArray() {
    for (int i = 0; i < 64; ++i) {
        if (i % 16 == 0)
            this->playArray.at((unsigned long) i) = 1;
    }
}

void Sample::preFillClapArray() {
    for (int i = 0; i < 64; ++i) {
        if (i % 32 == 0)
            this->playArray.at((unsigned long) i + 16) = 1;
    }
}

void Sample::preFillHighHatArray() {
    for (int i = 0; i < 64; ++i) {
        if (i % 16 == 0)
            if (i != 64)
                this->playArray.at((unsigned long) i + 8) = 1;
    }
}

void Sample::setMixVolume() {
    int volume = 100;
    volume *= this->masterVolume * this->volume;
    Mix_VolumeChunk(this->sampleFile, volume);
//    cout << "Master: " << this->getMasterVolume() << " Sample: " << this->getVolume() << " Result: " << volume << endl;
}

void Sample::setVolume(float volume) {
    if (volume >= 1) {
        this->volume = 1;
    } else if (volume <= 0) {
        this->volume = 0;
    } else {
        this->volume = volume;
    }
    setMixVolume();
}

float Sample::getVolume() {
    return this->volume;
}

void Sample::setMasterVolume(float volume) {
    if (volume >= 1) {
        this->masterVolume = 1;
    } else if (volume <= 0) {
        this->masterVolume = 0;
    } else {
        this->masterVolume = volume;
    }
    setMixVolume();
}

float Sample::getMasterVolume() {
    return this->masterVolume;
}


