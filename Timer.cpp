#include "Timer.h"

ControllerTimer::ControllerTimer()
{
    active = false;
    startTime = 0;
    durationMs = 0;
}

void ControllerTimer::begin()
{
    // nothing to initialize
}

void ControllerTimer::start(unsigned long duration)
{
    durationMs = duration;
    startTime = millis();
    active = true;
}

void ControllerTimer::start()
{
    start(BOMB_TIMER_DURATION);
}

void ControllerTimer::stop()
{
    active = false;
}

void ControllerTimer::reset()
{
    startTime = millis();
}

void ControllerTimer::penalty(unsigned long extra)
{
    if(active)
        durationMs += extra;
}

void ControllerTimer::update()
{
    // nothing needed
}

bool ControllerTimer::running() const
{
    return active;
}

bool ControllerTimer::expired() const
{
    if(!active)
        return false;
    return millis() - startTime >= durationMs;
}

unsigned long ControllerTimer::remaining() const
{
    if(!active)
        return 0;
    unsigned long elapsed = millis() - startTime;
    if(elapsed >= durationMs)
        return 0;
    return durationMs - elapsed;
}