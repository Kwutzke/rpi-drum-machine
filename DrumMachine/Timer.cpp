//
// Created by fritz on 7/10/17.
//

#include "Timer.h"
#include <thread>

using namespace std;

Timer::Timer(int interval, int precision)
        : interval(interval), precision(precision) { }

void Timer::stop() {
    this->running = false;
};