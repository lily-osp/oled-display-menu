#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

Adafruit_SSD1306 lcd(128, 64, &Wire, 4);

#define btn_Up   7
#define btn_OK   6
#define btn_DOWN 5

boolean status_up   = false;
boolean status_ok   = false;
boolean status_down = false;

boolean last_status_up   = false;
boolean last_status_ok   = false;
boolean last_status_down = false;

boolean UP   = false;
boolean OK   = false;
boolean DOWN = false;

int page  = 0;
int item  = 0;
