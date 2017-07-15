#include <mcp23017.h>
#include "DrumMachine.h"
#include "InputListener.h"
#include "RaspInputController.h"
#include "DrumMachineInputListener.h"

using namespace std;

void setup(DrumMachine& drumMachine) {
    drumMachine.setBPM(120);

    Sample baseDrum("./audio_files/tr909_16bit/bd01.wav");
    Sample clap("./audio_files/tr909_16bit/cp01.wav");
    Sample highHat("./audio_files/tr909_16bit/oh01.wav");

    for (unsigned short i = 0; i < 16; ++i) {
        if (i % 4 == 0) {
            baseDrum.playAtBeat(i);
            highHat.playAtBeat(i + 2);
        }
        if (i % 4 == 0) {
            if (i != 0 & i != 8)
                clap.playAtBeat(i);
        }
    }

    drumMachine.addSample(baseDrum);
    drumMachine.addSample(clap);
    drumMachine.addSample(highHat);
    drumMachine.setActiveSample(1);
}


int main() {

    cout << "Initializing output controller ..." << endl;
    RaspOutputController raspOutputController;
    cout << "Intitializing drum machine ..." << endl;
    DrumMachine drumMachine(raspOutputController);
    // Development
    setup(drumMachine);

    DrumMachineInputListener listener(drumMachine);

    RaspInputController controller;
    controller.addInputListener(listener);
    controller.start();
    return 0;
}
