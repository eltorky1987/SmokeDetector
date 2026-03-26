// 🌹 كود الأردوينو للحساس MQ-2
int sensorPin = A0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(sensorPin);
  Serial.println(value); // بيبعت القراءة للبايثون
  delay(1000);
}
