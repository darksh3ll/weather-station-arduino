#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int age = 42;
String name = "stephane";

void setup()
{
  lcd.begin(16, 2);
  lcd.print(age);
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print("stephane");
}