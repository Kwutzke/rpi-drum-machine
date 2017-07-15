#ifndef DRUMMACHINE_RASPINPUTCONTROLLER_H
#define DRUMMACHINE_RASPINPUTCONTROLLER_H

#include "DrumMachine.h"
#include "InputListener.h"
#include <wiringPi.h>

namespace inputs {
        const unsigned short
        VOLUME_UP_BUTTON    = 1,    VOLUME_DOWN_BUTTON  = 2,    BPM_UP_BUTTON   = 3,    BPM_DOWN_BUTTON = 4,
        MUTE_BUTTON         = 5,    SAMPLE1_BUTTON      = 6,    SAMPLE2_BUTTON  = 7,    SAMPLE3_BUTTON  = 8,
        SAMPLE4_BUTTON      = 9,    SAMPLE5_BUTTON      = 10,   SAMPLE6_BUTTON  = 11,   SAMPLE7_BUTTON  = 12,
        SAMPLE8_BUTTON      = 13,   BEAT1_BUTTON        = 14,   BEAT2_BUTTON    = 15,   BEAT3_BUTTON    = 16,
        BEAT4_BUTTON        = 17,   BEAT5_BUTTON        = 18,   BEAT6_BUTTON    = 19,   BEAT7_BUTTON    = 20,
        BEAT8_BUTTON        = 21,   BEAT9_BUTTON        = 22,   BEAT10_BUTTON   = 23,   BEAT11_BUTTON   = 24,
        BEAT12_BUTTON       = 25,   BEAT13_BUTTON       = 26,   BEAT14_BUTTON   = 27,   BEAT15_BUTTON   = 28,
        BEAT16_BUTTON       = 29,   START_STOP_BUTTON   = 30;
}

using namespace inputs;

class RaspInputController {
private:
    map<unsigned short, unsigned short> outputMap = {
//            { VOLUME_UP_BUTTON, -1  }, { VOLUME_DOWN_BUTTON, 2  }, { BPM_UP_BUTTON,  3  }, { BPM_DOWN_BUTTON,    4  },
//            { MUTE_BUTTON,      -1  }, { SAMPLE1_BUTTON,     6  }, { SAMPLE2_BUTTON, 7  }, { SAMPLE3_BUTTON,     8  },
//            { SAMPLE4_BUTTON,   9  }, { SAMPLE5_BUTTON,     10 }, { SAMPLE6_BUTTON, 11 }, { SAMPLE7_BUTTON,     12 },
//            { SAMPLE8_BUTTON,   13 },
            { BEAT1_BUTTON,     113 }, { BEAT2_BUTTON,      109 }, { BEAT3_BUTTON,  213 },
            { BEAT4_BUTTON,     209 }, { BEAT5_BUTTON,      102 }, { BEAT6_BUTTON,  106 }, { BEAT7_BUTTON,       202 },
            { BEAT8_BUTTON,     206 }, { BEAT9_BUTTON,      313 }, { BEAT10_BUTTON, 309 }, { BEAT11_BUTTON,      413 },
            { BEAT12_BUTTON,    409 }, { BEAT13_BUTTON,     302 }, { BEAT14_BUTTON, 306 }, { BEAT15_BUTTON,      402 },
            { BEAT16_BUTTON,    406 },
            { START_STOP_BUTTON,  0  }
    };

    map<unsigned short, bool> buttonStateMap = {
            { VOLUME_UP_BUTTON, false }, { VOLUME_DOWN_BUTTON, false }, { BPM_UP_BUTTON,  false }, { BPM_DOWN_BUTTON, false },
            { MUTE_BUTTON,      false }, { SAMPLE1_BUTTON,     false }, { SAMPLE2_BUTTON, false }, { SAMPLE3_BUTTON,  false },
            { SAMPLE4_BUTTON,   false }, { SAMPLE5_BUTTON,     false }, { SAMPLE6_BUTTON, false }, { SAMPLE7_BUTTON,  false },
            { SAMPLE8_BUTTON,   false }, { BEAT1_BUTTON,       false }, { BEAT2_BUTTON,   false }, { BEAT3_BUTTON,    false },
            { BEAT4_BUTTON,     false }, { BEAT5_BUTTON,       false }, { BEAT6_BUTTON,   false }, { BEAT7_BUTTON,    false },
            { BEAT8_BUTTON,     false }, { BEAT9_BUTTON,       false }, { BEAT10_BUTTON,  false }, { BEAT11_BUTTON,   false },
            { BEAT12_BUTTON,    false }, { BEAT13_BUTTON,      false }, { BEAT14_BUTTON,  false }, { BEAT15_BUTTON,   false },
            { BEAT16_BUTTON,    false }, { START_STOP_BUTTON,  false }
    };

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
