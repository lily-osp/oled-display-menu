# OLED Display Control

This code is for controlling an OLED display using the Adafruit SSD1306 library and buttons for navigation. 

## Hardware
- OLED Display with a resolution of 128x64
- 3 buttons for Up, OK, and Down navigation
- Arduino board

## Libraries
- `Wire.h`
- `Adafruit_SSD1306.h`
- `Adafruit_GFX.h`

## Variables
- `lcd`: An instance of the OLED display with a resolution of 128x64, using the `Wire` library and a pin of 4.
- `btn_Up`, `btn_OK`, `btn_DOWN`: Constants for the Up, OK, and Down buttons respectively.
- `status_up`, `status_ok`, `status_down`: Booleans for the current status of the Up, OK, and Down buttons.
- `last_status_up`, `last_status_ok`, `last_status_down`: Booleans for the previous status of the Up, OK, and Down buttons.
- `UP`, `OK`, `DOWN`: Booleans for detecting when the Up, OK, and Down buttons have been pressed.
- `page`: Integer for keeping track of the current page being displayed on the OLED.
- `item`: Integer for keeping track of the current item being highlighted on the OLED.

## Functions
- `setup()`: Initializes the serial communication, OLED display, and buttons.
- `loop()`: Continuously runs the code and calls the following functions:
	- `tampil()`: Displays the current page and highlighted item on the OLED.
	- `btn_up_pressed()`: Detects when the Up button is pressed.
	- `btn_ok_pressed()`: Detects when the OK button is pressed.
	- `btn_down_pressed()`: Detects when the Down button is pressed.

## Usage
Upload the code to your Arduino board, and connect the OLED display and buttons as per the defined constants in the code. The OLED display should display a menu with different items that can be navigated using the Up and Down buttons, and selected using the OK button.
