#include "Display.h"

Display::Display()
    : lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7)
{
    cursorPosition = 0;
    cursorDirection = true;
    previousCursorTime = 0;

    starPosition = 0;
    starDirection = true;
    previousStarTime = 0;

    lastInputText[0] = '\0';
}

void Display::begin()
{
    lcd.begin(LCD_COLUMNS, LCD_ROWS);
    lcd.clear();
    showBoot();
}

void Display::update()
{
    // nothing needed
}

void Display::clear()
{
    lcd.clear();
}

void Display::showBoot()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Puzzle System");
    lcd.setCursor(0,1);
    lcd.print("Initializing");
    lastInputText[0] = '\0';  // Reset cache
}

void Display::showIdle()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Code:");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lastInputText[0] = '\0';  // <-- Reset cache
}

void Display::showInput(const char *text)
{
    // If the text hasn't changed, do nothing (no redraw = no flicker)
    if (strcmp(text, lastInputText) == 0)
        return;

    // Text changed – update the LCD
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(text);

    // Save the new text to cache
    strcpy(lastInputText, text);
}

void Display::showGranted()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ACCESS");
    lcd.setCursor(0,1);
    lcd.print("GRANTED");
    lastInputText[0] = '\0';
}

void Display::showDenied()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ACCESS");
    lcd.setCursor(0,1);
    lcd.print("DENIED");
    lastInputText[0] = '\0';
}

void Display::showTimeout()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SESSION");
    lcd.setCursor(0,1);
    lcd.print("TIMEOUT");
    lastInputText[0] = '\0';
}

void Display::animateCursor()
{
    if (millis() - previousCursorTime < CURSOR_SPEED)
        return;

    previousCursorTime = millis();

    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(cursorPosition, 0);
    lcd.print('*');

    if (cursorDirection) {
        if (cursorPosition < 15) cursorPosition++;
        else cursorDirection = false;
    } else {
        if (cursorPosition > 0) cursorPosition--;
        else cursorDirection = true;
    }
}

void Display::animateStars()
{
    // Update every 150ms for smooth animation
    if (millis() - previousStarTime < 150)
        return;

    previousStarTime = millis();

    // Build the second line with spaces
    char line[17];
    for (int i = 0; i < 16; i++) line[i] = ' ';
    line[16] = '\0';

    // Place the main star at current position
    line[starPosition] = '*';

    // Add fading trail behind the star (depending on direction)
    // Trail characters: 'o' (bright), '.' (dim), ',' (very dim)
    for (int i = 1; i <= 3; i++) {
        int trailPos;
        if (starDirection) { // moving right → trail is to the left
            trailPos = starPosition - i;
        } else {             // moving left → trail is to the right
            trailPos = starPosition + i;
        }
        if (trailPos >= 0 && trailPos < 16) {
            if (i == 1) line[trailPos] = 'o';   // bright trail
            else if (i == 2) line[trailPos] = '.'; // dimmer
            else if (i == 3) line[trailPos] = ','; // very dim
        }
    }

    // Write the line to the LCD
    lcd.setCursor(0, 1);
    lcd.print(line);

    // Bounce the star position
    if (starDirection) {
        if (starPosition < 15) starPosition++;
        else starDirection = false;
    } else {
        if (starPosition > 0) starPosition--;
        else starDirection = true;
    }
}



void Display::showExploded()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   EXPLODED!   ");
    starPosition = 0;
    starDirection = true;
    lastInputText[0] = '\0';
}

void Display::showDefused()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   DEFUSED!    ");
    lcd.setCursor(0, 1);
    lcd.print("  ACCESS GRANTED");
    starPosition = 0;
    starDirection = true;
    lastInputText[0] = '\0';
}

void Display::showDefusePrompt()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Defuse:");
    lcd.setCursor(0, 1);
    lcd.print("                ");
}

void Display::showDefuseInput(const char *text)
{
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(text);
}