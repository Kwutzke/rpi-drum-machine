#ifndef DRUMMACHINE_RASPINPUTCONTROLLER_H
#define DRUMMACHINE_RASPINPUTCONTROLLER_H

#include "DrumMachine.h"
#include "InputListener.h"
#include <wiringPi.h>

namespace inputs {
        const unsigned short
        VOLUME_UP_BUTTON            = 1,    VOLUME_DOWN_BUTTON  = 2,    BPM_UP_BUTTON   = 3,    BPM_DOWN_BUTTON = 4,
        BPM_VOLUME_SWITCH_BUTTON    = 5,    SAMPLE1_BUTTON      = 6,    SAMPLE2_BUTTON  = 7,    SAMPLE3_BUTTON  = 8,
        SAMPLE4_BUTTON              = 9,    SAMPLE5_BUTTON      = 10,   SAMPLE6_BUTTON  = 11,   SAMPLE7_BUTTON  = 12,
        SAMPLE8_BUTTON              = 13,   BEAT1_BUTTON        = 14,   BEAT2_BUTTON    = 15,   BEAT3_BUTTON    = 16,
        BEAT4_BUTTON                = 17,   BEAT5_BUTTON        = 18,   BEAT6_BUTTON    = 19,   BEAT7_BUTTON    = 20,
        BEAT8_BUTTON                = 21,   BEAT9_BUTTON        = 22,   BEAT10_BUTTON   = 23,   BEAT11_BUTTON   = 24,
        BEAT12_BUTTON               = 25,   BEAT13_BUTTON       = 26,   BEAT14_BUTTON   = 27,   BEAT15_BUTTON   = 28,
        BEAT16_BUTTON               = 29,   START_STOP_BUTTON   = 30;
}

class RaspInputController {
private:
    // Input Pins
    static const unsigned short
            VOLUME_UP_BUTTON_PIN            = 1,    VOLUME_DOWN_BUTTON_PIN          = 2,    BPM_UP_BUTTON_PIN       = 3,
            BPM_DOWN_BUTTON_PIN             = 4,    BPM_VOLUME_SWITCH_BUTTON_PIN    = 5,    SAMPLE1_BUTTON_PIN      = 6,
            SAMPLE2_BUTTON_PIN              = 7,    SAMPLE3_BUTTON_PIN              = 8,    SAMPLE4_BUTTON_PIN      = 9,
            SAMPLE5_BUTTON_PIN              = 10,   SAMPLE6_BUTTON_PIN              = 11,   SAMPLE7_BUTTON_PIN      = 12,
            SAMPLE8_BUTTON_PIN              = 13,   BEAT1_BUTTON_PIN                = 14,   BEAT2_BUTTON_PIN        = 15,
            BEAT3_BUTTON_PIN                = 16,   BEAT4_BUTTON_PIN                = 17,   BEAT5_BUTTON_PIN        = 18,
            BEAT6_BUTTON_PIN                = 19,   BEAT7_BUTTON_PIN                = 20,   BEAT8_BUTTON_PIN        = 21,
            BEAT9_BUTTON_PIN                = 22,   BEAT10_BUTTON_PIN               = 23,   BEAT11_BUTTON_PIN       = 24,
            BEAT12_BUTTON_PIN               = 25,   BEAT13_BUTTON_PIN               = 26,   BEAT14_BUTTON_PIN       = 27,
            BEAT15_BUTTON_PIN               = 28,   BEAT16_BUTTON_PIN               = 29,   START_STOP_BUTTON_PIN   = 100;

    vector<InputListener*> inputListenerList;
    Timer pollingTimer;

    void startPolling();

    vector<unsigned short> getInputEvents();

    void initializePins();
public:

    RaspInputController();

    void addInputListener(InputListener& listener);
    void stop();
    void start();
};

#endif //DRUMMACHINE_RASPINPUTCONTROLLER_H
