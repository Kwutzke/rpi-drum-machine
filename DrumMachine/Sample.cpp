#include "Sample.h"

Sample::Sample(const char *samplePath) : playArray(16, 0), volume(1), masterVolume(1) {
    this->sampleFile = Mix_LoadWAV(samplePath);
    if (this->sampleFile == NULL) {
        fprintf(stderr, "Unable to load wave file: %s\n", samplePath);
    }
}

void Sample::playSample(int currentBeat) {
    if (this->playArray.at((unsigned long) currentBeat) == 1) {
        thread t([this]() {
            Mix_PlayChannel(-1, this->sampleFile, 0);
        });
        t.detach();
    }
}

void Sample::setMixVolume() {
    int volume = 100;
    volume *= this->masterVolume * this->volume;
    Mix_VolumeChunk(this->sampleFile, volume);
//    cout << "Master: " << this->getMasterVolume() << " Sample: " << this->getVolume() << " Result: " << volume << endl;
}

void Sample::playAtBeat(unsigned int beatPosition) {
    playArray.at(beatPosition) = 1;
}

void Sample::muteAtBeat(unsigned int beatPosition) {
    playArray.at(beatPosition) = 0;
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

vector<int, allocator<int>> &Sample::getPlayArray() {
    return playArray;
}
