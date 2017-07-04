//
// Created by Kilian Wutzke on 27.06.17.
//

#ifdef __APPLE__
    #include "SDL2/SDL.h"
    #include "SDL2_mixer/SDL_mixer.h"
    #include "SDL2_image/SDL_image.h"
#else
    #include "SDL2/SDL_mixer.h"
    #include "SDL2/SDL_image.h"
    #include "SDL2/SDL.h"
#endif

#include <vector>
#include <string>

#ifndef DRUMMACHINE_SAMPLE_H
#define DRUMMACHINE_SAMPLE_H



using namespace std;

class Sample {
public:
    Sample(const char* samplePath);
    void playSample(int currentBeat);
    void preFillKickDrumArray();
    void preFillClapArray();
    void preFillHighHatArray();
private:
    Mix_Chunk* sampleFile;
    bool active;
    int loopLength;
    vector<int> playArray;
    bool playing;
};


#endif //DRUMMACHINE_SAMPLE_H
