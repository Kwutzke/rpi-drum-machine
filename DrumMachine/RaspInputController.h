//
// Created by Kilian Wutzke on 11.07.17.
//

#ifndef DRUMMACHINE_PIINPUTCONTROLLER_H
#define DRUMMACHINE_PIINPUTCONTROLLER_H


#include "AInputController.h"
#include <wiringPi.h>

class PiInputController: public AInputController {
public:
    template <typename Function, typename... Args>
    void volumeUp(Function &&callback, Args &&... args) override {
        wiringPiISR()
    };

    template <typename Function, typename... Args>
    void volumeDown(Function &&callback, Args &&... args) override {

    };
};



#endif //DRUMMACHINE_PIINPUTCONTROLLER_H
