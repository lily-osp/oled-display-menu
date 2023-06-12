#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

Adafruit_SSD1306 lcd(128, 64, &Wire, 4);

// Define the pin number for the buttons
#define btn_Up   7
#define btn_OK   6
#define btn_DOWN 5

// Create variables to store the status of the buttons
boolean status_up   = false;
boolean status_ok   = false;
boolean status_down = false;

// Create variables to store the previous status of the buttons
boolean last_status_up   = false;
boolean last_status_ok   = false;
boolean last_status_down = false;

// Create variables to indicate if a button is pressed
boolean UP   = false;
boolean isOK = false;
boolean DOWN = false;

// Create variables to store the current page and menu item
int page  = 0;
int item  = 0;

// Total number of pages in the menu
const int TOTAL_PAGE = 5;
// Total number of menu items per page
const int MENU_PER_PAGE = 4;

void setup() {
  Serial.begin(115200);
  lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  lcd.clearDisplay();

  // Set the button pins as inputs with pull-up resistors
  pinMode(btn_Up,   INPUT_PULLUP);
  pinMode(btn_OK,   INPUT_PULLUP);
  pinMode(btn_DOWN, INPUT_PULLUP);
}

void loop() {
  // Display the current menu
  tampil();

  // Read the current status of the buttons
  status_up   = digitalRead(btn_Up);
  status_ok   = digitalRead(btn_OK);
  status_down = digitalRead(btn_DOWN);

  //Check if any of the buttons have been pressed and update the corresponding flag variables
  checkButtonPress(status_up, last_status_up, UP);
  checkButtonPress(status_ok, last_status_ok, isOK);
  checkButtonPress(status_down, last_status_down, DOWN);

  // Check if the up button is pressed and the current page is page 0
  if (UP && page == 0) {
    UP = false;
    item --;
    // Make sure the item value is within the valid range
    if (item < 0) item = MENU_PER_PAGE;
  }

  // Check if the down button is pressed and the current page is page 0
  if (DOWN && page == 0) {
    DOWN = false;
    item ++;
    // Make sure the item value is within the valid range
    if (item > MENU_PER_PAGE) item = 0;
  }

  // Check if the OK button is pressed
  if (isOK) {
    isOK = false;
    // Check if the current item is the "Back" button
    if (item == 0) {
      if (page > 0) {
        // Go to the previous page if possible
        page--;
      }
      item = MENU_PER_PAGE;
    } else {
      // Go to the next page if possible
      if (page < TOTAL_PAGE - 1) {
        page++;
        item = 0;
      }
    }
  }

  // Print the current menu item for debugging
  Serial.println(item);
  delay(100);
}

// Function to check if a button is pressed and update the corresponding flag variable
void checkButtonPress(boolean &status, boolean &lastStatus, boolean &flag) {
  if (status != lastStatus) {
    if (status == 0) {
      flag = true;
    }
    delay(50);
  }
  lastStatus = status;
}

// Function to display the current menu
void tampil() {
  lcd.clearDisplay();
  lcd.setTextSize(1);
  lcd.setTextColor(WHITE);
  lcd.setCursor(30, 0);
  lcd.print("PAGE " + String(page + 1));
  // Display the menu items
  displayMenuItem(page, item);
}

// Function to display the menu items for the current page
void displayMenuItem(int currentPage, int currentItem) {
  for (int i = 0; i <= MENU_PER_PAGE; i++) {
    lcd.setCursor(5, 17 + (i) * 10);
    if (i == currentItem) {
      if (i == 0) {
        lcd.print("> Back");
      } else {
        lcd.print("> Menu " + String(currentPage * MENU_PER_PAGE + i));
      }
    } else {
      if (i == 0) {
        lcd.print(" Back");
      } else {
        lcd.print(" Menu " + String(currentPage * MENU_PER_PAGE + i));
      }
    }
  }
}
