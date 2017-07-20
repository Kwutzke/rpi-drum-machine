#ifndef DRUMMACHINE_DRUMMACHINE_H
#define DRUMMACHINE_DRUMMACHINE_H

#include <vector>
#include "Sample.h"
#include "AOutputController.h"
#include "RaspOutputController.h"
#include "Timer.h"

using namespace std;

namespace sample {
    const unsigned short
            SAMPLE1 = 0, SAMPLE2 = 1, SAMPLE3 = 2, SAMPLE4 = 3,
            SAMPLE5 = 4, SAMPLE6 = 5, SAMPLE7 = 6, SAMPLE8 = 7,
            NO_SAMPLE = 8;
}

namespace beat {
    const unsigned short
            BEAT1 = 0, BEAT2  = 1, BEAT3  = 2,  BEAT4 =  3,  BEAT5 =  4,  BEAT6  = 5,  BEAT7  = 6,  BEAT8  = 7,
            BEAT9 = 8, BEAT10 = 9, BEAT11 = 10, BEAT12 = 11, BEAT13 = 12, BEAT14 = 13, BEAT15 = 14, BEAT16 = 15;
}

class DrumMachine {
private:
    const int TOTAL_BEATS = 16;
    const long LOOP_PRECISION_NANOS = 10000; // 10ms

    unsigned short bpm;
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
    explicit DrumMachine(AOutputController&);

    void startLoop();
    void stopLoop();
    void addSample(Sample);
    void addSamples(vector<Sample>);
    void increaseVolume(float);
    void increaseActiveSampleVolume(float);
    void increaseBpm(unsigned short);
    void toggleSampleAtBeat(unsigned short beat);

    // Getters and Setters
    bool isLoopRunning();

    void setBPM(unsigned short);

    unsigned short getBPM();

    void setMasterVolume(float);
    float getMasterVolume();

    void setActiveSample(unsigned short);
    unsigned short getActiveSample();
};


#endif //DRUMMACHINE_DRUMMACHINE_H
