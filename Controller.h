#ifndef Controller_H
#define Controller_H

#include "Config.h"
#include "Audio.h"
#include "Display.h"
#include "KeypadInput.h"
#include "Timer.h"
#include "LED.h"

class Controller
{
public:

    Controller();

    void begin(Display* display,
               KeypadInput* keypad,
               ControllerTimer* timer,
               LED* led,
               Audio* audio);

    void update();

private:

    Display* display;
    KeypadInput* keypad;
    ControllerTimer* timer;
    LED* led;
    Audio* audio;
    ControllerState state;

    unsigned long bootTimer;

    // NEW: Track if we're waiting for the defuse code
    bool waitingForDefuse;

    void bootState();
    void idleState();
    void armingState();
    void armedState();
    void defusedState();
    void explodedState();

    void armController();
    void disarmController();
};

#endif