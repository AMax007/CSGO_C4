#ifndef KEYPADINPUT_H
#define KEYPADINPUT_H

#include <Arduino.h>
#include "Config.h"

class KeypadInput
{
public:

    void begin();

    void update();

    // Returns the last key pressed and clears it (consumed)
    char getLastKey();

    // Returns current buffer contents
    const char* getBuffer() const;

    // Returns true if code entry is finished ('#' pressed or buffer full)
    bool codeFinished() const;

    // Returns the entered code as a String
    String getCode() const;

    // Clears the input buffer
    void clear();

private:

    const byte rowPins[4] = {6,7,8,9};
    const byte colPins[3] = {A0,A1,A2};

    const char keymap[4][3] =
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
        {'*','0','#'}
    };

    char buffer[MAX_CODE_LENGTH + 1];
    uint8_t bufferIndex;
    char lastKey;          // last key detected, to be consumed
    bool keyHeld;          // prevents repeated processing while key is held
    bool finished;         // true when '#' entered
    unsigned long debounceTime;
};

#endif