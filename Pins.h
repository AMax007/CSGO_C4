#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

/*=========================================================
    LCD (LM016L)
=========================================================*/

constexpr uint8_t LCD_RS = 12;
constexpr uint8_t LCD_EN = 11;
constexpr uint8_t LCD_D4 = 5;
constexpr uint8_t LCD_D5 = 4;
constexpr uint8_t LCD_D6 = 3;
constexpr uint8_t LCD_D7 = 2;

/*=========================================================
    Keypad
=========================================================*/

constexpr uint8_t ROW1_PIN = 6;
constexpr uint8_t ROW2_PIN = 7;
constexpr uint8_t ROW3_PIN = 8;
constexpr uint8_t ROW4_PIN = 9;

constexpr uint8_t COL1_PIN = A0;
constexpr uint8_t COL2_PIN = A1;
constexpr uint8_t COL3_PIN = A2;

/*=========================================================
    LED
=========================================================*/

constexpr uint8_t LED_PIN = 10;

/*=========================================================
    Speaker
=========================================================*/

constexpr uint8_t SPEAKER_PIN = 13;

#endif
