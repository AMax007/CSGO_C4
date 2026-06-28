#include "KeypadInput.h"

void KeypadInput::begin()
{
    // Rows as outputs
    for(int i = 0; i < 4; i++)
    {
        pinMode(rowPins[i], OUTPUT);
        digitalWrite(rowPins[i], HIGH);
    }

    // Columns as inputs with pullups
    for(int i = 0; i < 3; i++)
    {
        pinMode(colPins[i], INPUT_PULLUP);
    }

    bufferIndex = 0;
    buffer[0] = '\0';
    lastKey = 0;
    keyHeld = false;
    finished = false;
    debounceTime = 0;
}

void KeypadInput::update()
{
    if(millis() - debounceTime < 40)
        return;

    for(int r = 0; r < 4; r++)
    {
        // Set all rows HIGH
        for(int i = 0; i < 4; i++)
            digitalWrite(rowPins[i], HIGH);

        // Activate current row
        digitalWrite(rowPins[r], LOW);

        for(int c = 0; c < 3; c++)
        {
            if(digitalRead(colPins[c]) == LOW)
            {
                char key = keymap[r][c];

                if(keyHeld)
                {
                    // Key still held – ignore
                    return;
                }

                // New key press
                lastKey = key;
                debounceTime = millis();

                // Process key
                if(key == '#')
                {
                    finished = true;
                }
                else if(key == '*')
                {
                    clear();
                }
                else if(bufferIndex < MAX_CODE_LENGTH)
                {
                    buffer[bufferIndex++] = key;
                    buffer[bufferIndex] = '\0';
                }

                keyHeld = true;
                return;
            }
        }
    }

    // No key pressed
    keyHeld = false;
}

char KeypadInput::getLastKey()
{
    char key = lastKey;
    lastKey = 0; // consume
    return key;
}

const char* KeypadInput::getBuffer() const
{
    return buffer;
}

bool KeypadInput::codeFinished() const
{
    return finished;
}

String KeypadInput::getCode() const
{
    return String(buffer);
}

void KeypadInput::clear()
{
    bufferIndex = 0;
    buffer[0] = '\0';
    finished = false;
}