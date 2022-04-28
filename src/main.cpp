#include "LiquidCrystal.h"
#include <pigpio.h>


int main()
{
    if (gpioInitialise() < 0)
        return -1;

    const int rs = 22;
    const int en = 23;
    const int d0 = 24;
    const int d1 = 10;
    const int d2 = 9;
    const int d3 = 25;
    const int d4 = 11;
    const int d5 = 8;
    const int d6 = 5;
    const int d7 = 6;

    LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.write("Hello");
    return 0;
}
