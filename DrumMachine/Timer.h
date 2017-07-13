#ifndef DRUMMACHINE_TIMER_H
#define DRUMMACHINE_TIMER_H

#include <iostream>
#include <chrono>
#include <time.h>
#include <thread>

using namespace std;
using namespace std::chrono;

class Timer {
private:
    int precision;
    int interval;
    bool running;

    long long getCurrentTimeMillis() {
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
public:
    Timer(int, int);

    template <typename Function, typename... Args>
    void start(Function&& callback, Args&&... args) {
        running = true;
        long long lastTime = getCurrentTimeMillis();

        timespec spec = { 0, precision };

        while (running) {
            long long now = getCurrentTimeMillis();
            if (lastTime + interval <= now) {
                thread th(callback);
                th.detach();
                lastTime = now;
            }
            nanosleep(&spec, nullptr);
        }
    }

    void stop();
};


#endif //DRUMMACHINE_TIMER_H
