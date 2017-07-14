#include "DrumMachine.h"
#include "RaspOutputController.h"

using namespace std;

void setup(DrumMachine& drumMachine) {
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

//    drumMachine.addSamples({ baseDrum, clap, highHat });
    drumMachine.addSample(baseDrum);
    drumMachine.addSample(clap);
    drumMachine.addSample(highHat);
    drumMachine.setActiveSample(1);
}


int main() {
    RaspOutputController raspOutputController;
    DrumMachine drumMachine(raspOutputController);
    drumMachine.setBPM(120);


    // Development
    setup(drumMachine);

    drumMachine.startLoop();
    return 0;
}
