#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// إعدادات الشاشة (العنوان غالباً 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int mq2Pin = A0;    // دبوس المستشعر
const int buzzerPin = 8;  // دبوس الجرس
const int threshold = 400; // مستوى التنبيه (يمكنك تعديله)

void setup() {
  pinMode(mq2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  // رسالة ترحيب عند التشغيل
  lcd.setCursor(0, 0);
  lcd.print("System Starting");
  lcd.setCursor(0, 1);
  lcd.print("Smart Smoke Det.");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(mq2Pin);
  
  // عرض القيمة على الشاشة
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(sensorValue);
  
  lcd.setCursor(0, 1);
  if (sensorValue > threshold) {
    lcd.print("Status: DANGER! ");
    digitalWrite(buzzerPin, HIGH); // تشغيل الإنذار
    delay(200);
    digitalWrite(buzzerPin, LOW);
  } else {
    lcd.print("Status: SAFE    ");
    digitalWrite(buzzerPin, LOW); // إيقاف الإنذار
  }
  
  delay(500); // تحديث كل نصف ثانية
}
