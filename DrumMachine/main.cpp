//
// Created by fritz on 7/3/17.
//

#include <functional>
#include "DrumMachine.h"
#include "RaspInputController.h"
#include "DrumMachineInputListener.h"

using namespace std;

int main() {
    DrumMachine drumMachine;

    DrumMachineInputListener listener(drumMachine);

    RaspInputController controller;
    controller.addInputListener(listener);


    // Development
    Sample baseDrum("./audio_files/tr909_16bit/bd01.wav");
    baseDrum.preFillKickDrumArray();
    drumMachine.addSample(baseDrum);

    Sample clap("./audio_files/tr909_16bit/cp01.wav");
    clap.preFillClapArray();
    drumMachine.addSample(clap);

    Sample highHat("./audio_files/tr909_16bit/oh01.wav");
    highHat.preFillHighHatArray();
    drumMachine.addSample(highHat);


    drumMachine.startLoop();
    return 0;
}