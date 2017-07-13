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
    float volume;

    vector<Sample> samples;

    void allocateChannels();
    void openAudio();
    void loop();

public:
    DrumMachine();

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
};


#endif //DRUMMACHINE_DRUMMACHINE_H
