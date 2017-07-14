//
// Created by Kilian Wutzke on 11.07.17.
//

#ifndef DRUMMACHINE_PIINPUTCONTROLLER_H
#define DRUMMACHINE_PIINPUTCONTROLLER_H


class PiInputController {
public:
    template <typename Function, typename... Args>
    void volumeUp(Function &&callback, Args &&... args) {
    };

    template <typename Function, typename... Args>
    void volumeDown(Function &&callback, Args &&... args) {
    };
};



#endif //DRUMMACHINE_PIINPUTCONTROLLER_H
