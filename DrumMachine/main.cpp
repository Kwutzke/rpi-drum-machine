#include <mcp23017.h>
<<<<<<< HEAD
#include <wiringPi.h>
=======
>>>>>>> parent of 7e2d26a... cleaned up dev folder
#include "DrumMachine.h"
#include "InputListener.h"
#include "RaspInputController.h"
#include "DrumMachineInputListener.h"

using namespace std;
<<<<<<< HEAD
using namespace sample;
=======
>>>>>>> parent of 7e2d26a... cleaned up dev folder

void setup(DrumMachine& drumMachine) {
    drumMachine.setBPM(120);

    Sample baseDrum("./audio_files/tr909_16bit/bd01.wav");
    Sample clap("./audio_files/tr909_16bit/cp01.wav");
    Sample highHat("./audio_files/tr909_16bit/oh01.wav");
<<<<<<< HEAD
    Sample closedHighHat("./audio_files/tr909_16bit/hh01.wav");
    Sample snareDrum("./audio_files/tr909_16bit/sd02.wav");
    Sample tom("./audio_files/tr909_16bit/ht01.wav");
    Sample rimShot("./audio_files/tr909_16bit/rs01.wav");
=======

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
>>>>>>> parent of 7e2d26a... cleaned up dev folder

    drumMachine.addSample(baseDrum);
    drumMachine.addSample(clap);
    drumMachine.addSample(highHat);
<<<<<<< HEAD
    drumMachine.addSample(closedHighHat);
    drumMachine.addSample(snareDrum);
    drumMachine.addSample(tom);
    drumMachine.addSample(rimShot);
=======
    drumMachine.setActiveSample(1);
>>>>>>> parent of 7e2d26a... cleaned up dev folder
}


int main() {
    cout << "Initializing wiring pi ...";
    wiringPiSetup();
    mcp23017Setup(100, 0x20);
    mcp23017Setup(200, 0x21);
<<<<<<< HEAD
    mcp23017Setup(300, 0x24);
    mcp23017Setup(400, 0x23);
=======
    mcp23017Setup(300, 0x23);
    mcp23017Setup(400, 0x24);
>>>>>>> parent of 7e2d26a... cleaned up dev folder
    mcp23017Setup(500, 0x26);
    cout << " done." << endl;

    cout << "Initializing output controller ...";
    RaspOutputController raspOutputController;
    cout << " done." << endl;

    cout << "Initializing drum machine ...";
    DrumMachine drumMachine(raspOutputController);
    cout << " done." << endl;

<<<<<<< HEAD
=======
    // Development
>>>>>>> parent of 7e2d26a... cleaned up dev folder
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
