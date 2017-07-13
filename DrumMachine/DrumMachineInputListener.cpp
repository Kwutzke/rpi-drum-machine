//
// Created by fritz on 7/13/17.
//

#include "DrumMachineInputListener.h"
#include "RaspInputController.h"

using namespace inputs;

DrumMachineInputListener::DrumMachineInputListener(DrumMachine& drumMachine): drumMachine(drumMachine) {

}

void DrumMachineInputListener::inputEvent(unsigned short input) {
    switch (input) {
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
