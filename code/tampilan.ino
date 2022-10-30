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
