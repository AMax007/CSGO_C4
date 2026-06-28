#include "Config.h"

#include "Display.h"
#include "KeypadInput.h"
#include "Timer.h"
#include "LED.h"
#include "Audio.h"
#include "Controller.h"

//----------------------------------------------------
// Objects
//----------------------------------------------------

Display display;
KeypadInput keypad;
ControllerTimer timer;
LED led;
Audio audio;
Controller controller;   // renamed to avoid conflict with class name

//----------------------------------------------------
// Setup
//----------------------------------------------------

void setup()
{
    display.begin();
    keypad.begin();
    timer.begin();       // added empty method
    led.begin();
    audio.begin();
    
    controller.begin(
        &display,
        &keypad,
        &timer,
        &led,
        &audio);
        
}

//----------------------------------------------------
// Main Loop
//----------------------------------------------------

void loop()
{
    keypad.update();
    timer.update();
    led.update();        // removed argument
    controller.update();
    display.update();
}