/*
 * مشروع كاشف الدخان الذكي (Smoke Detector)
 * Hardware: Arduino Uno, MQ-2 Sensor, Buzzer
 */

// تعريف الأطراف (Pins)
const int smokeSensorPin = A0;  // طرف الحساس متوصل بـ A0
const int buzzerPin = 13;       // طرف الجرس متوصل بـ 13
int sensorThreshold = 400;      // مستوى الحساسية (ممكن تغيره حسب التجربة)

void setup() {
  pinMode(buzzerPin, OUTPUT);    // تعيين طرف الجرس كمخرج
  pinMode(smokeSensorPin, INPUT); // تعيين طرف الحساس كمدخل
  Serial.begin(9600);            // فتح شاشة المراقبة لمتابعة القراءات
}

void loop() {
  int analogSensorValue = analogRead(smokeSensorPin); // قراءة قيمة الحساس

  Serial.print("Smoke Level: ");
  Serial.println(analogSensorValue);

  // إذا تجاوزت القراءة الحد المسموح (دخان موجود)
  if (analogSensorValue > sensorThreshold) {
    digitalWrite(buzzerPin, HIGH); // تشغيل الجرس
    delay(100);                    // نغمة متقطعة
    digitalWrite(buzzerPin, LOW);
    delay(100);
  } else {
    digitalWrite(buzzerPin, LOW);  // إيقاف الجرس في الحالة العادية
  }
  
  delay(500); // انتظر نصف ثانية قبل القراءة التالية
}
