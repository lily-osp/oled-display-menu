#include "config.h"
void setup() {
  Serial.begin(115200);
  lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  lcd.clearDisplay();

  pinMode(btn_Up,   INPUT_PULLUP);
  pinMode(btn_OK,   INPUT_PULLUP);
  pinMode(btn_DOWN, INPUT_PULLUP);
}

void loop() {
  tampil();

  status_up   = digitalRead(btn_Up);
  status_ok   = digitalRead(btn_OK);
  status_down = digitalRead(btn_DOWN);

  btn_up_pressed();
  btn_ok_pressed();
  btn_down_pressed();

  //FOR button up
  if (UP && page == 0) {
    UP = false;
    item --;
    if (item < 0)item = 4;
  }
  //FOR button down
  if (DOWN && page == 0) {
    DOWN = false;
    item ++;
    if (item > 4)item = 0;
  }

  //FOR button ok
  if (OK) {
    OK = false;
    if (page == 0 && item == 1) {
      page = 1;
    } else if (page == 0 && item == 2) {
      page = 2;
    } else if (page == 0 && item == 3) {
      page = 3;
    } else if (page == 0 && item == 4) {
      page = 4;
    } else if (page == 1 && item == 1) {
      page = 0;
    } else if (page == 2 && item == 1) {
      page = 0;
    } else if (page == 3 && item == 1) {
      page = 0;
    } else if (page == 4 && item == 1) {
      page = 0;
    }
  }

  Serial.println(item);
  delay(100);
}
