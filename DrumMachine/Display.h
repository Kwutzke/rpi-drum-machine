#ifndef DRUMMACHINE_DISPLAY_H
#define DRUMMACHINE_DISPLAY_H

#include <ArduiPi_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Display {
public:
    Display();

    void showMainScreen(unsigned int bpm);
    void showSampleScreen(unsigned int bpm, float volume);
private:
    Adafruit_SSD1306 display;
};


#endif //DRUMMACHINE_DISPLAY_H
