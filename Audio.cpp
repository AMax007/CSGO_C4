#include "Audio.h"
#include "Sounds.h"
#include "Pins.h"

void Audio::begin()
{
    pinMode(SPEAKER_PIN, OUTPUT);
}

void Audio::play(uint8_t soundID)
{
    switch(soundID)
    {
        case SOUND_BOOT:
            beep(1000, 300);
            break;

        case SOUND_KEY:
            beep(1200, 40);
            break;

        case SOUND_READY:
            beep(1800, 200);
            break;

        case SOUND_NOTIFICATION:
            beep(900, 100);
            break;

        case SOUND_ERROR:
            beep(400, 250);
            break;

        case SOUND_SUCCESS:
            beep(2000, 400);
            break;

        case SOUND_TIMEOUT:
            beep(200, 800);
            break;

        case SOUND_COMPLETE:
            beep(1500, 500);
            break;
    }
}

void Audio::beep(uint16_t frequency, uint16_t duration)
{
    tone(SPEAKER_PIN, frequency, duration);
}

void Audio::playBoot()       { play(SOUND_BOOT); }
void Audio::playKey()        { play(SOUND_KEY); }
void Audio::playPlant()      { play(SOUND_NOTIFICATION); }
void Audio::playExplosion()  { play(SOUND_ERROR); }
void Audio::playError()      { play(SOUND_ERROR); }
void Audio::playDefused()    { play(SOUND_SUCCESS); }