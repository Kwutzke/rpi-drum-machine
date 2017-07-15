#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H

#include <vector>
#include "Sample.h"
#include "AOutputController.h"
#include "RaspOutputController.h"
#include "Timer.h"

using namespace std;

class DrumMachine {
private:
    const int TOTAL_BEATS = 16;
    const long LOOP_PRECISION_NANOS = 10000; // 10ms

    int bpm;
    unsigned short currentBeat;
    int sixteenthNoteMillis;
    bool loopRunning;
    float volume;
    AOutputController& outputController;
    unsigned short activeSample;

    Timer loop;
    vector<Sample> samples;

    void allocateChannels();
    void openAudio();

public:
    DrumMachine(AOutputController&);

    void startLoop();
    void stopLoop();
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
