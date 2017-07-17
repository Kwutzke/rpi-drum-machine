#include "Display.h"

Display::Display() {
    display.init(OLED_I2C_RESET, OLED_ADAFRUIT_I2C_128x64);
    display.begin();
}

void Display::showMainScreen(unsigned int bpm) {
    display.clearDisplay();

    display.setTextColor(WHITE);
    display.setTextSize(3);
    display.setCursor(1, 1);
    display.printf("BPM:%d", bpm);
    display.display();
}

void Display::showSampleScreen(unsigned int bpm, float volume) {
    display.clearDisplay();

    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(1, 1);
    display.printf("BPM:%d", bpm);
    display.setTextSize(3);
    display.setCursor(1, 30);
    display.printf("VOL:%d", (int)(volume * 100));
    display.display();
}
