#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H

#include <vector>
#include "Sample.h"
#include "AOutputController.h"
#include "RaspOutputController.h"

using namespace std;

class DrumMachine {
private:
    const int TOTAL_LOOPS = 1;
    const int TOTAL_BEATS = 16;

    int bpm;
    unsigned short currentBeat;
    int sixteenthNoteMillis;
    bool loopRunning;
    float volume;
    RaspOutputController outputController;
    unsigned short activeSample;

    vector<Sample> samples;

    void allocateChannels();
    void openAudio();
    void loop();

public:
    DrumMachine(RaspOutputController);

    void startLoop();
    void stopLoop();
    void toggleLoop();
    void addSample(Sample);
    void addSamples(vector<Sample>);
    void increaseVolume(float);

    // Getters and Setters
    bool isLoopRunning();

    void setBPM(int);
    int getBPM();

    void setMasterVolume(float);
    float getMasterVolume();

    void setActiveSample(unsigned short);
};


#endif //DRUMMACHINE_DRUMMACHINE_H
