// 🌹 كود الأردوينو للحساس MQ-2
int sensorPin = A0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(sensorPin);
  Serial.println(value); 
  delay(1000);
}
#include <ESP8266WiFi.h>

const char* ssid = "YourNetworkName";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");
}

void loop() {
  // هنا تضيف كود الكشف عن الدخان
  // لو فيه دخان، ابعت تنبيه عبر HTTP أو MQTT
}
