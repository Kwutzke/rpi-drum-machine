#ifndef DRUMMACHINE_DISPLAY_H
#define DRUMMACHINE_DISPLAY_H

#include <ArduiPi_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


/**
 * A class that holds information an maintains the functionalaty of an Adafruit SSD1306 Display
 */
class Display {
public:
    /**
     * Constructor
     */
    Display();

    /**
     * Activates the main screen
     * @param bpm the speed of the loop, is shown in the display
     */
    void showMainScreen(unsigned short bpm);

    /**
     * Activates the sample screen
     * @param bpm the speed of the loop, is shown in the display
     * @param volume the volume of the active sample
     */
    void showSampleScreen(unsigned short bpm, float volume);

private:
    Adafruit_SSD1306 display; //< The display
};


#endif //DRUMMACHINE_DISPLAY_H
