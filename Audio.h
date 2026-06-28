#ifndef AUDIO_H
#define AUDIO_H

#include <Arduino.h>

class Audio
{
public:

    void begin();

    void play(uint8_t soundID);

    // Convenience wrappers
    void playBoot();
    void playKey();
    void playPlant();
    void playExplosion();
    void playError();
    void playDefused();

private:

    void beep(uint16_t frequency, uint16_t duration);
};

#endif