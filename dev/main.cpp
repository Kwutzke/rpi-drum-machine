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
    cout << "Initializing wiring pi ...";
    wiringPiSetup();
    mcp23017Setup(100, 0x20);
    mcp23017Setup(200, 0x21);
    mcp23017Setup(300, 0x23);
    mcp23017Setup(400, 0x24);
    mcp23017Setup(500, 0x26);
    cout << " done." << endl;

    cout << "Initializing output controller ...";
    RaspOutputController raspOutputController;
    cout << " done." << endl;

    cout << "Initializing drum machine ...";
    DrumMachine drumMachine(raspOutputController);
    cout << " done." << endl;

    // Development
    cout << "Filling samples ...";
    setup(drumMachine);
    cout << " done." << endl;

//    drumMachine.startLoop();

    cout << "Initializing input listener ...";
    DrumMachineInputListener listener(drumMachine);
    cout << " done." << endl;

    cout << "Initializing input controller ...";
    RaspInputController controller;
    cout << " done." << endl;

    cout << "Registering input listener ...";
    controller.addInputListener(listener);
    cout << " done." << endl;

    controller.start();
    return 0;
}
