#include "game.h"

Game::Game() {}

#ifdef ARDUINO

LedControl _lc(DATA_PIN, CLOCK_PIN, CS_PIN, 1);

void Game::setup() {
    _lc.shutdown(0,false);
    _lc.setIntensity(0,8);
    _lc.clearDisplay(0);

    pinMode(2, INPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}


// Check if this is correct
float Game::get_axis_x() {
    return analogRead(A0);
    //return ((float)(analogRead(A0)-512))/512.f;
}

float Game::get_axis_y() {
    return analogRead(A1);
    //return ((float)(analogRead(A1)-512))/512.f;
}

bool Game::button_pressed() {
    return digitalRead(2) == HIGH;
}

void Game::set_led(int x, int y, bool state) {
    _lc.setLed(0, x, y, state);
}

#else

void Game::setup() {}

#endif
