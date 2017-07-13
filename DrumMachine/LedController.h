#ifndef DRUMMACHINE_LEDCONTROLLER_H
#define DRUMMACHINE_LEDCONTROLLER_H

#include <thread>
#include "AOutputController.h"

using namespace std;

class LedController : public AOutputController {
public:
    LedController();

    void positionChange(int newPosition) override;

    void bpmChange(int newBpm) override;

    void volumeChange(int newVolume) override;

    void activeSampleChange(int newActiveSample) override;

    void samplePlayPositionChange(vector<int> &newPlayArray) override;

    void blink(int ledPosition);
};


#endif //DRUMMACHINE_LEDCONTROLLER_H
