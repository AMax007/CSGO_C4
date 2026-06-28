#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

/*=========================================================
    LCD
=========================================================*/

constexpr uint8_t LCD_COLUMNS = 16;
constexpr uint8_t LCD_ROWS = 2;

/*=========================================================
    Keypad
=========================================================*/

constexpr uint8_t KEYPAD_ROWS = 4;
constexpr uint8_t KEYPAD_COLS = 3;

constexpr uint8_t MAX_CODE_LENGTH = 8;

/*=========================================================
    Display
=========================================================*/

constexpr unsigned long CURSOR_SPEED = 120;
constexpr unsigned long DISPLAY_REFRESH = 50;

/*=========================================================
    LED
=========================================================*/

constexpr unsigned long LED_SLOW = 900;
constexpr unsigned long LED_MEDIUM = 500;
constexpr unsigned long LED_FAST = 200;

/*=========================================================
    Timeouts
=========================================================*/

constexpr unsigned long ENTRY_TIMEOUT = 30000;

/*=========================================================
    Puzzle
=========================================================*/

constexpr char ACCESS_CODE[] = "7355608";

// Bomb timer duration (ms)
constexpr unsigned long BOMB_TIMER_DURATION = 60000;

// Penalty for wrong code (ms)
constexpr unsigned long WRONG_CODE_PENALTY = 5000;

/*=========================================================
    States
=========================================================*/

enum class ControllerState : uint8_t
{
    BOOT,
    IDLE,
    ARMING,
    ARMED,
    DEFUSED,
    EXPLODED
};

#endif