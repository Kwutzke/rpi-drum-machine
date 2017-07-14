//
// Created by Kilian Wutzke on 11.07.17.
//


#ifndef DRUMMACHINE_AOUTPUTCONTROLLER_H
#define DRUMMACHINE_AOUTPUTCONTROLLER_H

#include <vector>

using namespace std;

class AOutputController {
public:
    virtual void positionChange(int newPosition) = 0;
    virtual void bpmChange(int newBpm) = 0;
    virtual void volumeChange(int newVolume) = 0;
    virtual void activeSampleChange(int newActiveSample) = 0;
    virtual void samplePlayPositionChange(vector<int> &newPlayArray) = 0;
};


#endif //DRUMMACHINE_AOUTPUTCONTROLLER_H
