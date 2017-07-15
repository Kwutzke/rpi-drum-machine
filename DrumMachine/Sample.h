#ifndef DRUMMACHINE_SAMPLE_H
#define DRUMMACHINE_SAMPLE_H

#ifdef __APPLE__
#include "SDL2/SDL.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_image/SDL_image.h"
#else
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL.h"
#endif

#include <vector>
#include <string>
#include <thread>
#include <iostream>

using namespace std;

namespace state {
    const unsigned short PLAY = 1, MUTE = 0;
}

class Sample {
public:

    Sample(const char* samplePath);
    void playSample(int currentBeat);
    void playAtBeat(unsigned int);
    void muteAtBeat(unsigned int);

    void togglePlayAtBeat(unsigned int);
    // Getters and Setters
    void setVolume(float);
    float getVolume();
    void setMasterVolume(float);

    float getMasterVolume();


    vector<unsigned short> &getPlayArray();
private:

    Mix_Chunk* sampleFile;
    vector<unsigned short> playArray;
    bool active;
    int loopLength;
    bool playing;
    float volume;
    float masterVolume;

    void setMixVolume();

};


#endif //DRUMMACHINE_SAMPLE_H
