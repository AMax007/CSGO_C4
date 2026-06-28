#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Config.h"
#include "Pins.h"

class Display
{
public:

    Display();

    void begin();
    void update();
    void clear();

    void showBoot();
    void showIdle();
    void showInput(const char *text);
    void showGranted();
    void showDenied();
    void showTimeout();
    void animateCursor();   // For idle state (cursor)
    void animateStars();    // For armed state (bouncing star)
    void showExploded();
    void showDefused();
    void showDefusePrompt();
    void showDefuseInput(const char *text);

private:

    LiquidCrystal lcd;

    // Cursor animation (idle state)
    uint8_t cursorPosition;
    bool cursorDirection;
    unsigned long previousCursorTime;

    // Star animation (armed state)
    uint8_t starPosition;
    bool starDirection;
    unsigned long previousStarTime;

    // Cache for input line (to prevent flicker)
    char lastInputText[17];
};

#endif