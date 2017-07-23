#include "DrumMachineInputListener.h"
#include "RaspInputController.h"

using namespace inputs;
using namespace sample;
using namespace beat;

DrumMachineInputListener::DrumMachineInputListener(DrumMachine& drumMachine): drumMachine(drumMachine) { }

void DrumMachineInputListener::inputEvent(unsigned short input) {
    // Evaluate the pressed button and call corresponding events in drum machine
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
        case SAMPLE1_BUTTON: drumMachine.setActiveSample(SAMPLE1); break;
        case SAMPLE2_BUTTON: drumMachine.setActiveSample(SAMPLE2); break;
        case SAMPLE3_BUTTON: drumMachine.setActiveSample(SAMPLE3); break;
        case SAMPLE4_BUTTON: drumMachine.setActiveSample(SAMPLE4); break;
        case SAMPLE5_BUTTON: drumMachine.setActiveSample(SAMPLE5); break;
        case SAMPLE6_BUTTON: drumMachine.setActiveSample(SAMPLE6); break;
        case SAMPLE7_BUTTON: drumMachine.setActiveSample(SAMPLE7); break;
        case SAMPLE8_BUTTON: drumMachine.setActiveSample(SAMPLE8); break;

        case BEAT1_BUTTON: drumMachine.toggleSampleAtBeat(BEAT1); break;
        case BEAT2_BUTTON: drumMachine.toggleSampleAtBeat(BEAT2); break;
        case BEAT3_BUTTON: drumMachine.toggleSampleAtBeat(BEAT3); break;
        case BEAT4_BUTTON: drumMachine.toggleSampleAtBeat(BEAT4); break;
        case BEAT5_BUTTON: drumMachine.toggleSampleAtBeat(BEAT5); break;
        case BEAT6_BUTTON: drumMachine.toggleSampleAtBeat(BEAT6); break;
        case BEAT7_BUTTON: drumMachine.toggleSampleAtBeat(BEAT7); break;
        case BEAT8_BUTTON: drumMachine.toggleSampleAtBeat(BEAT8); break;
        case BEAT9_BUTTON: drumMachine.toggleSampleAtBeat(BEAT9); break;
        case BEAT10_BUTTON: drumMachine.toggleSampleAtBeat(BEAT10); break;
        case BEAT11_BUTTON: drumMachine.toggleSampleAtBeat(BEAT11); break;
        case BEAT12_BUTTON: drumMachine.toggleSampleAtBeat(BEAT12); break;
        case BEAT13_BUTTON: drumMachine.toggleSampleAtBeat(BEAT13); break;
        case BEAT14_BUTTON: drumMachine.toggleSampleAtBeat(BEAT14); break;
        case BEAT15_BUTTON: drumMachine.toggleSampleAtBeat(BEAT15); break;
        case BEAT16_BUTTON: drumMachine.toggleSampleAtBeat(BEAT16); break;

        case VOLUME_BPM_UP_BUTTON:
            if (drumMachine.getActiveSample() == NO_SAMPLE) {
                drumMachine.increaseBpm(BPM_STEP_SIZE);
                cout << "BPM up!" << drumMachine.getBPM() << endl;
            } else {
                drumMachine.increaseActiveSampleVolume(VOLUME_STEP_SIZE);
                cout << "Volume up!" << drumMachine.getMasterVolume() << endl;
            }
            break;
        case inputs::VOLUME_BPM_DOWN_BUTTON:
            if (drumMachine.getActiveSample() == NO_SAMPLE) {
                drumMachine.increaseBpm(-BPM_STEP_SIZE);
                cout << "BPM down!" << drumMachine.getBPM() << endl;
            } else {
                drumMachine.increaseActiveSampleVolume(-VOLUME_STEP_SIZE);
                cout << "Volume down! " << drumMachine.getMasterVolume() << endl;
            }
        default:break;
    }
}
