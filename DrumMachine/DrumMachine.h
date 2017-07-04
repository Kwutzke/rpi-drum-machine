//
// Created by fritz on 7/3/17.
//

#include <vector>
#include "Sample.h"

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
    vector<sample> samples;

    void initialize();
public:
    DrumMachine();

    void loop();

    void startLoop();
    void stopLoop();

    void setBPM(int);
    int getBPM();
};


#endif //DRUMMACHINE_DRUMMACHINE_H
