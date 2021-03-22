#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int sensor=A0;
int value;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  value=analogRead(sensor);     //lm35 calculations
  float x=(value/1024.0)*5000;
  float san=x/10;
  float fahr=(san*9)/5+32;
  
  lcd.print("Temp=");           //Writing temperature to lcd as celsius
  lcd.print(san);
  lcd.print("*C");
  delay(2000);
  
  lcd.clear();                  //Writing temperature to lcd as fahrenheit
  lcd.print("Temp=");
  lcd.print(fahr);
  lcd.print("*F");
  delay(2000);
  
  lcd.clear();
  }
