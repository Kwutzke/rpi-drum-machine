//
// Created by Kilian Wutzke on 11.07.17.
//

#ifndef DRUMMACHINE_AINPUTCONTROLLER_H
#define DRUMMACHINE_AINPUTCONTROLLER_H

class AInputController {
public:
    virtual void initialize() = 0;
    template <typename Function, typename... Args>
    virtual void volumeUp(Function&& callback, Args&&... args) = 0;

    template <typename Function, typename... Args>
    virtual void volumeDown(Function&& callback, Args&&... args) = 0;
};

#endif //DRUMMACHINE_AINPUTCONTROLLER_H
