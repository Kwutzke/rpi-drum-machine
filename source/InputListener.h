    #ifndef DRUMMACHINE_INPUTLISTENER_H
#define DRUMMACHINE_INPUTLISTENER_H

#include <vector>

using namespace std;

/**
 * @brief   Interface for input listeners to register in the RaspInputController
 */
class InputListener {
public:
    /**
     * Called when new input events are detected
     * @param input the input that was detected.
     */
    virtual void inputEvent(unsigned short input) = 0;
};

#endif //DRUMMACHINE_INPUTLISTENER_H
