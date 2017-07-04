//
// Created by fritz on 7/3/17.
//

#include <vector>
#include "Sample.h"

#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H


class DrumMachine {
private:
    int bpm;
    int currentBeat;
    int sixteenthNoteMillis;
    bool loopRunning;
//    vector<sample> samples; ??

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
