#ifndef DRUMMACHINE_TIMER_H
#define DRUMMACHINE_TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

/**
 * @brief   Call a callback function in a given interval, determining the time with a given precision. Higher precision
 *          means higher demand in resources.
 */
class Timer {
private:
    unsigned int precision; ///< The precision in nanoseconds
    unsigned int interval;  ///< The interval in milliseconds
    bool running;           ///< Is the timer currently running

    long long getCurrentTimeMillis() { ///< Helper function to get the current time in milliseconds
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }

public:
    /**
     * Constructor
     * @param interval the interval in milliseconds in which the callback function is called.
     * @param precision the precision in nanoseconds with which to determine the current time. Higher precision
     *                  means higher demand in resources.
     */
    Timer(unsigned int interval, unsigned int precision);

    /**
     * Starts the timer.
     * @param callback the callback function the timer calls in the determined interval.
     * @param args arguments to pass to the callback function upon call.
     */
    template<typename Function, typename... Args>
    void start(Function &&callback, Args &&... args) {
        running = true;
        long long lastTime = getCurrentTimeMillis();

        timespec spec = {0, precision};

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

    /**
     * Stops the timer
     */
    void stop();

    /**
     * @return the interval with which the timer calls the callback function.
     */
    unsigned int getInterval() const;

    /**
     * @param interval the interval with which the timer calls the callback function.
     */
    void setInterval(unsigned int interval);
};


#endif //DRUMMACHINE_TIMER_H
