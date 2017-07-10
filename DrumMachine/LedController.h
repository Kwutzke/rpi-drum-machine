//
// Created by Kilian Wutzke on 10.07.17.
//

#include <thread>

#ifndef DRUMMACHINE_LEDCONTROLLER_H
#define DRUMMACHINE_LEDCONTROLLER_H

using namespace std;

class LedController {
public:
    LedController();
    void blinkRhythmLed(int position);

    void blink(int ledPosition);
};


#endif //DRUMMACHINE_LEDCONTROLLER_H
