#include "Sample.h"

using namespace state;

Sample::Sample(const char *samplePath) : playArray(16, 0), volume(1), masterVolume(1) {
    this->sampleFile = Mix_LoadWAV(samplePath);
    if (this->sampleFile == nullptr) {
        fprintf(stderr, "Unable to load wave file: %s\n", samplePath);
    }
}

void Sample::playSample(int currentBeat) {
    if (this->playArray.at((unsigned long) currentBeat) == 1) {
        thread t([this]() {
            this->play();
        });
        t.detach();
    }
}

void Sample::play() {
    Mix_PlayChannel(-1, this->sampleFile, 0);
}

void Sample::setMixVolume() {
    int volume = 100;
    volume *= this->masterVolume * this->volume;
    Mix_VolumeChunk(this->sampleFile, volume);
}

void Sample::playAtBeat(unsigned int beatPosition) {
    playArray.at(beatPosition) = 1;
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

vector<unsigned short, allocator<unsigned short>> &Sample::getPlayArray() {
    return playArray;
}

void Sample::togglePlayAtBeat(unsigned short beat) {
    if (playArray.at(beat) == PLAY) {
        playArray.at(beat) = MUTE;
    } else {
        playArray.at(beat) = PLAY;
    }
}
