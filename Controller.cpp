#include "Controller.h"
#include "Config.h"

Controller::Controller()
{
    state = ControllerState::BOOT;
    waitingForDefuse = false;  // <-- NEW
}

void Controller::begin(Display* d,
                 KeypadInput* k,
                 ControllerTimer* t,
                 LED* l,
                 Audio* a)
{
    display = d;
    keypad = k;
    timer = t;
    led = l;
    audio = a;

    bootTimer = millis();

    display->showBoot();
    audio->playBoot();
}

void Controller::update()
{
    switch(state)
    {
        case ControllerState::BOOT:
            bootState();
            break;

        case ControllerState::IDLE:
            idleState();
            break;

        case ControllerState::ARMING:
            armingState();
            break;

        case ControllerState::ARMED:
            armedState();
            break;

        case ControllerState::DEFUSED:
            defusedState();
            break;

        case ControllerState::EXPLODED:
            explodedState();
            break;
    }
}

void Controller::bootState()
{
    if(millis() - bootTimer >= 2000)
    {
        display->showIdle();
        state = ControllerState::IDLE;
    }
}

void Controller::idleState()
{
    display->showInput(keypad->getBuffer());

    char key = keypad->getLastKey();
    if(key != '\0')
    {
        audio->playKey();
    }

    if(keypad->codeFinished())
    {
        if(keypad->getCode() == ACCESS_CODE)
        {
            keypad->clear();
            armController();
            state = ControllerState::ARMED;
        }
        else
        {
            keypad->clear();
            display->showIdle();
        }
    }
}

void Controller::armingState()
{
    // Reserved for future planting animation
}

void Controller::armedState()
{
    display->animateStars();

    // Check if timer expired
    if(timer->expired())
    {
        timer->stop();
        audio->playExplosion();
        state = ControllerState::EXPLODED;
        return;
    }

    // Handle keypresses
    char key = keypad->getLastKey();
    if(key != '\0')
    {
        audio->playKey();

        // If user presses #, enter defuse mode
        if(key == '#')
        {
            if(!waitingForDefuse)
            {
                waitingForDefuse = true;
                keypad->clear();
                display->showDefusePrompt();  // Need to add this to Display
            }
            else
            {
                // Already in defuse mode, pressing # again checks the code
                if(keypad->codeFinished())
                {
                    if(keypad->getCode() == ACCESS_CODE)
                    {
                        keypad->clear();
                        waitingForDefuse = false;
                        disarmController();
                        state = ControllerState::DEFUSED;
                    }
                    else
                    {
                        keypad->clear();
                        waitingForDefuse = false;
                        timer->penalty(WRONG_CODE_PENALTY);
                        audio->playError();
                        display->showIdle();  // Reset display
                    }
                }
            }
        }
        else if(waitingForDefuse)
        {
            // We're in defuse mode, just let keypad handle the buffer
        }
    }

    // If in defuse mode, show the input
    if(waitingForDefuse)
    {
        display->showDefuseInput(keypad->getBuffer());
    }
}

void Controller::defusedState()
{
    // Nothing to do
}

void Controller::explodedState()
{
    display->showExploded();
    led->on();
}

void Controller::armController()
{
    timer->start();                 // uses BOMB_TIMER_DURATION
    audio->playPlant();
    led->blink(LED_FAST);
}

void Controller::disarmController()
{
    timer->stop();
    led->off();
    display->showDefused();
    audio->playDefused();
}