/*
 * مشروع كاشف الدخان الذكي (Smart Smoke Detector)
 * المبرمج: Mahamed Eltorky
 * الوصف: نظام إنذار مبكر يستخدم حساس MQ-2 وجرس تنبيه.
 */

// تعريف الأطراف (Pins)
const int smokeSensorPin = A0;  // طرف الحساس (Analog)
const int buzzerPin = 13;       // طرف الجرس (Digital)

// إعدادات الحساسية
int sensorThreshold = 400;      // القيمة التي يبدأ عندها الإنذار

void setup() {
  pinMode(buzzerPin, OUTPUT);     // ضبط الجرس كمخرج
  pinMode(smokeSensorPin, INPUT);  // ضبط الحساس كمدخل
  
  Serial.begin(9600);             // بدء الاتصال مع الكمبيوتر (Serial Monitor)
  Serial.println("--- نظام كاشف الدخان يعمل الآن ---");
}

void loop() {
  // قراءة مستوى الدخان أو الغاز
  int smokeLevel = analogRead(smokeSensorPin); 

  // طباعة النتائج لمتابعتها
  Serial.print("Smoke Level: ");
  Serial.print(smokeLevel);

  // التحقق من وجود خطر
  if (smokeLevel > sensorThreshold) {
    Serial.println(" [!!!] خطر: تم كشف دخان!");
    
    // نغمة إنذار متقطعة
    digitalWrite(buzzerPin, HIGH);
    delay(150);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  } 
  else {
    Serial.println(" [OK] الحالة مستقرة");
    digitalWrite(buzzerPin, LOW); // إيقاف الجرس
  }
  
  delay(500); // تحديث القراءة كل نصف ثانية
}
