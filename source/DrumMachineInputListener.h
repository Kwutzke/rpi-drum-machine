#ifndef DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H
#define DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H


#include "DrumMachine.h"
#include "InputListener.h"

/**
 * @brief   InputListener implementation for the drum machine to handle input events.
 */
class DrumMachineInputListener : public InputListener {
private:
    const float VOLUME_STEP_SIZE = 0.05f;       ///< Value to increase the volume in one step
    const unsigned short BPM_STEP_SIZE = 1;     ///< Value to increase the bpm in one step

    DrumMachine &drumMachine;                   ///< Reference to the drum machine thats used by the listener

public:
    /**
     * Constructor
     * @param drumMachine the drum machine to be used by the listener
     */
    explicit DrumMachineInputListener(DrumMachine &drumMachine);

    void inputEvent(unsigned short event) override;
};


#endif //DRUMMACHINE_DRUMMACHINEINPUTLISTENER_H
