//
// Created by Kilian Wutzke on 27.06.17.
//

#include "Sample.h"

Sample::Sample(const char* samplePath) {
    this->sampleFile = Mix_LoadWAV(samplePath);
    if (this->sampleFile == NULL) {
        fprintf(stderr, "Unable to load wave file: %s\n", samplePath);
    }
}

void Sample::playSample(int currentBeat) {
    Mix_PlayChannel(-1, this->sampleFile, 0);
}

void Sample::prefillKickDrumArray() {
    fill(this->playArray->begin(), this->playArray->end(), 0);
    for (int i = 0; i < 64; ++i) {
        if(i%8 == 0)
            this->playArray->at((unsigned long) i) = 1;
    }
}


