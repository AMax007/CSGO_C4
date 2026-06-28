#include "LED.h"

LED::LED()
{
    enabled = false;
    state = false;
    previousToggle = 0;
    blinkInterval = 500;
}

void LED::begin()
{
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(LED_PIN, LOW);
}

void LED::on()
{
    enabled = false;
    digitalWrite(LED_PIN, HIGH);
}

void LED::off()
{
    enabled = false;
    digitalWrite(LED_PIN, LOW);
}

void LED::blink(unsigned long interval)
{
    enabled = true;
    blinkInterval = interval;
}

void LED::update()
{
    if(!enabled)
        return;

    if(millis() - previousToggle < blinkInterval)
        return;

    previousToggle = millis();

    state = !state;

    digitalWrite(LED_PIN, state);
}