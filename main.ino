// Smoke Detector System by Mahamed Eltorky
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int smokePin = A0; 
const int buzzerPin = 9; 
const int threshold = 400; 

void setup() {
  pinMode(smokePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Active");
}

void loop() {
  int sensorValue = analogRead(smokePin);
  lcd.setCursor(0, 0);
  lcd.print("Value: ");
  lcd.print(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("!!! DANGER !!!");
  } else {
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: Safe  ");
  }
  delay(500);
}
