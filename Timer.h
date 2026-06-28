#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include "Config.h"

class ControllerTimer
{
public:

    ControllerTimer();

    void begin();                // added for consistency

    void start();                // uses BOMB_TIMER_DURATION
    void start(unsigned long duration);
    void stop();
    void reset();
    void penalty(unsigned long extra); // adds extra time
    void update();

    bool expired() const;
    bool running() const;
    unsigned long remaining() const;

private:

    unsigned long startTime;
    unsigned long durationMs;
    bool active;
};

#endif