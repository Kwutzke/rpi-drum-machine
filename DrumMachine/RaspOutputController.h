#ifndef DRUMMACHINE_LEDCONTROLLER_H
#define DRUMMACHINE_LEDCONTROLLER_H

#include <thread>
#include <map>
#include <list>
#include <vector>

using namespace std;

namespace outputs {
    const unsigned short
        BEAT1_RED = 1,  BEAT1_GREEN =    2, BEAT1_BLUE =     3,     BEAT2_RED = 4,  BEAT2_GREEN =    5, BEAT2_BLUE =    6,
        BEAT3_RED = 7,  BEAT3_GREEN =    8, BEAT3_BLUE =     9,     BEAT4_RED = 10, BEAT4_GREEN =   11, BEAT4_BLUE =   12,
        BEAT5_RED = 13, BEAT5_GREEN =   14, BEAT5_BLUE =    15,     BEAT6_RED = 16, BEAT6_GREEN =   17, BEAT6_BLUE =   18,
        BEAT7_RED = 19, BEAT7_GREEN =   20, BEAT7_BLUE =    21,     BEAT8_RED = 22, BEAT8_GREEN =   23, BEAT8_BLUE =   24;
}

using namespace outputs;


class RaspOutputController {
public:
    RaspOutputController();

    void positionChange(unsigned short newPosition) ;

    void bpmChange(int newBpm) ;

    void volumeChange(int newVolume) ;

    void activeSampleChange(int newActiveSample) ;

    void samplePlayPositionChange(vector<int>&) ;

    void blink(int);


private:
    const map<unsigned short, unsigned short> beatPinMap = {
            {BEAT1_RED, 115}, {BEAT1_GREEN, 114}, {BEAT1_BLUE, 112},
            {BEAT2_RED, 111}, {BEAT2_GREEN, 110}, {BEAT2_BLUE, 108},
            {BEAT3_RED, 215}, {BEAT3_GREEN, 214}, {BEAT3_BLUE, 212},
            {BEAT4_RED, 211}, {BEAT4_GREEN, 210}, {BEAT4_BLUE, 208},
            {BEAT5_RED, 100}, {BEAT5_GREEN, 101}, {BEAT5_BLUE, 103},
            {BEAT6_RED, 104}, {BEAT6_GREEN, 105}, {BEAT6_BLUE, 107},
            {BEAT7_RED, 200}, {BEAT7_GREEN, 201}, {BEAT7_BLUE, 203},
            {BEAT8_RED, 204}, {BEAT8_GREEN, 205}, {BEAT8_BLUE, 207}
    };

    const vector<unsigned short> redLedList = {
            BEAT1_RED, BEAT2_RED, BEAT3_RED, BEAT4_RED, BEAT5_RED, BEAT6_RED, BEAT7_RED, BEAT8_RED
    };

    const vector<unsigned short> greenLedList = {
            BEAT1_GREEN, BEAT2_GREEN, BEAT3_GREEN, BEAT4_GREEN, BEAT5_GREEN, BEAT6_GREEN, BEAT7_GREEN, BEAT8_GREEN
    };

    const vector<unsigned short> blueLedList = {
            BEAT1_BLUE, BEAT2_BLUE, BEAT3_BLUE, BEAT4_BLUE, BEAT5_BLUE, BEAT6_BLUE, BEAT7_BLUE, BEAT8_BLUE
    };

    void initializePins();

    void switchOfAllLed();

    void ledOff(int ledPin);

    void switchOnFirstBeatLed();

};



#endif //DRUMMACHINE_LEDCONTROLLER_H
