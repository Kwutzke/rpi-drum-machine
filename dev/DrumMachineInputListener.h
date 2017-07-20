#ifndef DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H
#define DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H


#include "DrumMachine.h"
#include "InputListener.h"

class DrumMachineInputListener: public InputListener {
private:
    const float VOLUME_STEP_SIZE = 0.1f;

    DrumMachine& drumMachine;

public:
    DrumMachineInputListener(DrumMachine& drumMachine);

    void inputEvent(unsigned short event) override;
};


#endif //DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H
