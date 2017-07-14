#include "Timer.h"

using namespace std;

Timer::Timer(int interval, int precision) : interval(interval), precision(precision) { }

void Timer::stop() {
    this->running = false;
};