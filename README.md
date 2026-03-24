#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int mq2Pin = A0;
const int buzzerPin = 8;
const int threshold = 400;

void setup() {
  pinMode(mq2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(mq2Pin);
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(sensorValue);
  lcd.setCursor(0, 1);
  if (sensorValue > threshold) {
    lcd.print("Status: DANGER! ");
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
  } else {
    lcd.print("Status: SAFE    ");
    digitalWrite(buzzerPin, LOW);
  }
  delay(500);
}
