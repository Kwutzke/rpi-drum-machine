#ifndef DRUMMACHINE_AOUTPUTCONTROLLER_H
#define DRUMMACHINE_AOUTPUTCONTROLLER_H

#include <vector>

using namespace std;

class AOutputController {
public:
    virtual void positionChange(unsigned short newPosition) = 0;
    virtual void bpmChange(int newBpm) = 0;
    virtual void volumeChange(int newVolume) = 0;
    virtual void activeSampleChange(unsigned short newActiveSample, unsigned short oldActiveSample) = 0;
    virtual void playPositionChange(vector<unsigned short> &newPlayArray) = 0;
    virtual void playPositionChange(unsigned short, unsigned short) = 0;
    virtual void setBeatBlinkDelay(unsigned int beatBlinkDelay) = 0;
    virtual void showMainScreen(unsigned int bpm) = 0;
    virtual void showSampleScreen(unsigned int bpm, float volume) = 0;
};


#endif //DRUMMACHINE_AOUTPUTCONTROLLER_H
