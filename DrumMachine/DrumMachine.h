//
// Created by fritz on 7/3/17.
//


#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H

#include <vector>
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
    AOutputController outputController;
public:
    DrumMachine();
    void loop();
    void startLoop();
    void stopLoop();
    void setBPM(int);
    int getBPM();
    void openAudio();
    void allocateChannels();

    void volumeUp();
};


#endif //DRUMMACHINE_DRUMMACHINE_H
