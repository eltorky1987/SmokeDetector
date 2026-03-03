// كود كاشف الدخان (Smoke Detector Code)
int smokePin = A0; // توصيل الحساس بمدخل A0
int buzzer = 13;   // توصيل جرس الإنذار بمدخل 13

void setup() {
  pinMode(smokePin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); // لبدء مراقبة البيانات على الكمبيوتر
}

void loop() {
  int data = analogRead(smokePin); // قراءة نسبة الدخان
  Serial.print("Smoke Level: ");
  Serial.println(data);

  if (data > 400) { // إذا زادت النسبة عن 400 (يمكن تعديلها)
    digitalWrite(buzzer, HIGH); // تشغيل الإنذار
  } else {
    digitalWrite(buzzer, LOW);  // إيقاف الإنذار
  }
  delay(500); // انتظر نصف ثانية قبل القراءة التالية
}
