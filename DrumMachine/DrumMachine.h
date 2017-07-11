//
// Created by fritz on 7/3/17.
//

#include <vector>
#include "Sample.h"
#include "LedController.h"

#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H

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

    void initialize();
public:
    DrumMachine();
    void loop();
    void startLoop();
    void stopLoop();
    void setBPM(int);
    int getBPM();
    void openAudio();
    void allocateChannels();
};


#endif //DRUMMACHINE_DRUMMACHINE_H
