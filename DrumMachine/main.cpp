#include "DrumMachine.h"

using namespace std;

void setup(DrumMachine& drumMachine) {
    Sample baseDrum("./audio_files/tr909_16bit/bd01.wav");
    Sample clap("./audio_files/tr909_16bit/cp01.wav");
    Sample highHat("./audio_files/tr909_16bit/oh01.wav");

    for (unsigned short i = 0; i < 64; ++i) {
        if (i % 16 == 0) {
            baseDrum.playAtBeat(i);
            if (i != 64)
                highHat.playAtBeat(i + 8);
        }
        if (i % 32 == 0) {
            clap.playAtBeat(i + 16);
        }
    }

//    drumMachine.addSamples({ baseDrum, clap, highHat });
    drumMachine.addSample(baseDrum);
    drumMachine.addSample(clap);
    drumMachine.addSample(highHat);
}


int main() {
    DrumMachine drumMachine;
    drumMachine.setBPM(120);

    // Development
    setup(drumMachine);

    drumMachine.startLoop();
    return 0;
}
