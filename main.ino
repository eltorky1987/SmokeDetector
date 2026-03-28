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
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "YourNetworkName";
const char* password = "YourPassword";
const char* serverUrl = "http://your-server.com/alert"; // ضع هنا رابط السيرفر أو Cloudflare Worker

int smokeSensorPin = A0;

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
  int sensorValue = analogRead(smokeSensorPin);

  if (sensorValue > 300) { // قيمة افتراضية للكشف عن دخان
    Serial.println("Smoke detected!");

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverUrl);
      http.addHeader("Content-Type", "application/json");

      String payload = "{\"alert\":\"Smoke detected!\"}";
      int httpResponseCode = http.POST(payload);

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      http.end();
    }
  }

  delay(5000); // فحص كل 5 ثواني
}
