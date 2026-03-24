// Smoke Detector System by Mahamed Eltorky
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int smokePin = A0; // Sensor connected to Analog Pin A0
const int buzzerPin = 9; // Buzzer connected to Digital Pin 9
const int threshold = 400; // Smoke sensitivity level

void setup() {
  pinMode(smokePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Active");
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(smokePin);
  
  lcd.clear();
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
    lcd.print("Status: Safe");
  }
  
  delay(500);
}

