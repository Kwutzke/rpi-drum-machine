//
// Created by fritz on 7/3/17.
//

#include "DrumMachine.h"
#include "Timer.h"
#include <iostream>

using namespace std;

void testFunction() {
    cout << "Hello World!" << endl;
}

int main() {
//    DrumMachine drumMachine;
//    drumMachine.startLoop();

    Timer timer(1000, 100000000);
    timer.start(testFunction);

    return 0;
}