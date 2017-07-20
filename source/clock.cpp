#include <ArduiPi_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>
#include <time.h>
#include <sys/statvfs.h>
 
Adafruit_SSD1306 display;
 
int main(int argc, char **argv) {
  if ( !display.init(OLED_I2C_RESET,OLED_ADAFRUIT_I2C_128x32) )
    exit(EXIT_FAILURE);
 
  display.begin();
 
  display.clearDisplay();

  display.fillRect(1, 1, 54, 8,BLACK);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1, 1);
  display.print("Hello World!");
  display.display();


 
  while (1) {
    delay(30);
  }
  display.close();
}
