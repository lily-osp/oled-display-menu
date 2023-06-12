# OLED Menu Navigation

This code demonstrates a simple menu navigation system using an OLED display and three buttons (Up, OK, and Down).

## Hardware Components

- OLED display (128x64)
- Arduino board
- Three buttons (Up, OK, and Down)
- Wires

## Pin Connections

The OLED display and buttons should be connected to the Arduino board as follows:

- OLED SDA to Arduino pin 4
- OLED SCL to Arduino pin 5
- Up button to Arduino pin 7
- OK button to Arduino pin 6
- Down button to Arduino pin 5

## Features

- Five pages of menu
- Four menu items per page
- One "Back" button to navigate to the previous page
- Current page and menu item are displayed on the OLED display

## Usage

1. Upload the code to the Arduino board using the Arduino IDE.
2. Connect the OLED display and buttons to the Arduino board according to the pin connections mentioned above.
3. Open the serial monitor to see the current menu item for debugging purposes.
4. Use the Up and Down buttons to navigate through the menu items on the current page.
5. Press the OK button to select a menu item.
6. Press the "Back" button to navigate to the previous page.
