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
int item  = 1;

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
    if (item < 1)item = 4;
  }
  //FOR button down
  if (DOWN && page == 0) {
    DOWN = false;
    item ++;
    if (item > 4)item = 1;
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

//--------------------------------------------------------------------------------
void btn_up_pressed() {
  if (status_up != last_status_up) {
    if (status_up == 0) {
      UP = true;
    }
    delay(50);
  }
  last_status_up = status_up;
}

void btn_ok_pressed() {
  if (status_ok != last_status_ok) {
    if (status_ok == 0) {
      OK = true;
    }
    delay(50);
  }
  last_status_ok = status_ok;
}

void btn_down_pressed() {
  if (status_down != last_status_down) {
    if (status_down == 0) {
      DOWN = true;
    }
    delay(50);
  }
  last_status_down = status_down;
}

//----------------------------------------------------------------------------

//semua yang tampil di lcd ada di fungsi ini
void tampil() {
  if (page == 0) {
    lcd.clearDisplay();
    lcd.setTextSize(1);
    lcd.setTextColor(WHITE);
    lcd.setCursor(30, 0);
    lcd.print("DAFTAR MENU");

    if (item == 1) {
      lcd.setCursor(5, 17);
      lcd.setTextColor(WHITE);
      lcd.print("> item 1");
    } else {
      lcd.setCursor(5, 17);
      lcd.setTextColor(WHITE);
      lcd.print("  item 1");
    }

    if (item == 2) {
      lcd.setCursor(5, 27);
      lcd.setTextColor(WHITE);
      lcd.print("> item 2");
    } else {
      lcd.setCursor(5, 27);
      lcd.setTextColor(WHITE);
      lcd.print("  item 2");
    }

    if (item == 3) {
      lcd.setCursor(5, 37);
      lcd.setTextColor(WHITE);
      lcd.print("> item 3");
    } else {
      lcd.setCursor(5, 37);
      lcd.setTextColor(WHITE);
      lcd.print("  item 3");
    }

    if (item == 4) {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("> item 4");
    } else {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("  item 4");
    }

  } else if (page == 1) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("page 2");

    if (item == 1)
    {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("> back  ");
    } else {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("  back  ");
    }

  } else if (page == 2) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("page 3");
    item = 1;

    if (item == 1)
    {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("> back  ");
    } else {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("  back  ");
    }

  } else if (page == 3) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("page 4");
    item = 1;

    if (item == 1)
    {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("> back  ");
    } else {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("  back  ");
    }

  } else if (page == 4) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("page 5");
    item = 1;

    if (item == 1)
    {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("> back  ");
    } else {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("  back  ");
    }

  }
  lcd.display();
}
//--------------------------------------------------------------------------------