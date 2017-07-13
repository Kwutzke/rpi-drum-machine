#ifndef DRUMMACHINE_INPUTLISTENER_H
#define DRUMMACHINE_INPUTLISTENER_H

#include <vector>

using namespace std;

class InputListener {
public:
    virtual void inputEvent(unsigned short input) = 0;
};

#endif //DRUMMACHINE_INPUTLISTENER_H
