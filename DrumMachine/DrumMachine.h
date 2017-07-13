//
// Created by fritz on 7/3/17.
//


#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H

#include<vector>
#include "Sample.h"
#include "AOutputController.h"

using namespace std;

class DrumMachine {
private:
    const int TOTAL_LOOPS = 4;
    const int TOTAL_BEATS = 16;

    int bpm;
    int currentBeat;
    int sixteenthNoteMillis;
    bool loopRunning;
    vector<Sample> samples;

//    LedController ledController;
    float volume;

public:
    DrumMachine();

    void loop();
    void startLoop();
    void stopLoop();
    void toggleLoop();
    bool isLoopRunning();
    void openAudio();
    void allocateChannels();

    void addSample(Sample);
    void increaseVolume(float);

    // Getters and Setters
    void setBPM(int);
    int getBPM();
    void setMasterVolume(float);
    float getMasterVolume();
};


#endif //DRUMMACHINE_DRUMMACHINE_H
