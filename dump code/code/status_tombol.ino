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
