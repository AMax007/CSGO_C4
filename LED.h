#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include "Pins.h"

class LED
{
public:

    LED();

    void begin();

    void on();

    void off();

    void blink(unsigned long interval);

    void update();

private:

    bool enabled;

    bool state;

    unsigned long previousToggle;

    unsigned long blinkInterval;
};

#endif