#include "DrumMachineInputListener.h"
#include "RaspInputController.h"

using namespace inputs;

DrumMachineInputListener::DrumMachineInputListener(DrumMachine& drumMachine): drumMachine(drumMachine) { }

void DrumMachineInputListener::inputEvent(unsigned short input) {
    switch (input) {
        case START_STOP_BUTTON:
            if (drumMachine.isLoopRunning()) {
                drumMachine.stopLoop();
            } else {
                thread th([this] () {
                    drumMachine.startLoop();
                });
                th.detach();
            }
            cout << "Toggle loop!" << endl;
            break;
        case SAMPLE1_BUTTON: drumMachine.setActiveSample(1); break;
        case SAMPLE2_BUTTON: drumMachine.setActiveSample(2); break;
        case SAMPLE3_BUTTON: drumMachine.setActiveSample(3); break;
        case SAMPLE4_BUTTON: drumMachine.setActiveSample(4); break;
        case SAMPLE5_BUTTON: drumMachine.setActiveSample(5); break;
        case SAMPLE6_BUTTON: drumMachine.setActiveSample(6); break;
        case SAMPLE7_BUTTON: drumMachine.setActiveSample(7); break;
        case SAMPLE8_BUTTON: drumMachine.setActiveSample(8); break;

        case BEAT1_BUTTON: drumMachine.toggleActiveSampleAtBeat(0); break;
        case BEAT2_BUTTON: drumMachine.toggleActiveSampleAtBeat(1); break;
        case BEAT3_BUTTON: drumMachine.toggleActiveSampleAtBeat(2); break;
        case BEAT4_BUTTON: drumMachine.toggleActiveSampleAtBeat(3); break;
        case BEAT5_BUTTON: drumMachine.toggleActiveSampleAtBeat(4); break;
        case BEAT6_BUTTON: drumMachine.toggleActiveSampleAtBeat(5); break;
        case BEAT7_BUTTON: drumMachine.toggleActiveSampleAtBeat(6); break;
        case BEAT8_BUTTON: drumMachine.toggleActiveSampleAtBeat(7); break;
        case BEAT9_BUTTON: drumMachine.toggleActiveSampleAtBeat(8); break;
        case BEAT10_BUTTON: drumMachine.toggleActiveSampleAtBeat(9); break;
        case BEAT11_BUTTON: drumMachine.toggleActiveSampleAtBeat(10); break;
        case BEAT12_BUTTON: drumMachine.toggleActiveSampleAtBeat(11); break;
        case BEAT13_BUTTON: drumMachine.toggleActiveSampleAtBeat(12); break;
        case BEAT14_BUTTON: drumMachine.toggleActiveSampleAtBeat(13); break;
        case BEAT15_BUTTON: drumMachine.toggleActiveSampleAtBeat(14); break;
        case BEAT16_BUTTON: drumMachine.toggleActiveSampleAtBeat(15); break;

        case VOLUME_UP_BUTTON:
            drumMachine.increaseVolume(VOLUME_STEP_SIZE);
                cout << "Volume up!" << endl;
            break;
        case inputs::VOLUME_DOWN_BUTTON:
            drumMachine.increaseVolume(-VOLUME_STEP_SIZE);
                cout << "Volume down! " << drumMachine.getMasterVolume() << endl;
        default:break;
    }
}
