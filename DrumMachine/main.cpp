//
// Created by fritz on 7/3/17.
//

#include "DrumMachine.h"
#include "Timer.h"
#include <iostream>

using namespace std;

void testFunction() {
    cout << "Hello World!" << endl;
}

int main() {
    DrumMachine drumMachine;
    drumMachine.setMasterVolume(.6f);

    Sample baseDrum("../audio_files/tr909_16bit/bd01.wav");
    baseDrum.preFillKickDrumArray();
    baseDrum.setVolume(0.1f);
    drumMachine.addSample(baseDrum);

    Sample clap("../audio_files/tr909_16bit/cp01.wav");
    clap.preFillClapArray();
    clap.setVolume(.3f);
    drumMachine.addSample(clap);

    Sample highHat("../audio_files/tr909_16bit/oh01.wav");
    highHat.preFillHighHatArray();
    drumMachine.addSample(highHat);

    drumMachine.startLoop();

    Timer timer(1000, 100000000); // precision in nanoseconds
    timer.start(testFunction);

    return 0;
}