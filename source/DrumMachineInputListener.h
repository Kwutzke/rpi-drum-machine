#ifndef DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H
#define DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H


#include "DrumMachine.h"
#include "InputListener.h"

class DrumMachineInputListener: public InputListener {
private:
    const float VOLUME_STEP_SIZE = 0.05f;
    const unsigned short BPM_STEP_SIZE = 1;

    DrumMachine& drumMachine;

public:
    explicit DrumMachineInputListener(DrumMachine& drumMachine);

    void inputEvent(unsigned short event) override;
};


#endif //DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H
