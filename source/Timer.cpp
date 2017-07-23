#include "Timer.h"

using namespace std;

Timer::Timer(unsigned int interval, unsigned int precision) : interval(interval), precision(precision) {}

void Timer::stop() {
    this->running = false;
}

unsigned int Timer::getInterval() const {
    return interval;
}

void Timer::setInterval(unsigned int interval) {
    Timer::interval = interval;
};