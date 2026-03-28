# 🔥 Smart Smoke Detector | نظام كاشف الدخان الذكي 🚀  

## 📖 الوصف | Description  
مشروع إنذار ذكي يعتمد على تقنيات **IoT** للكشف عن الدخان والغازات باستخدام مستشعر **MQ-2**، مع تنبيهات فورية وشاشة عرض **LCD I2C**.  
يهدف المشروع إلى تعزيز السلامة المنزلية والمكتبية عبر نظام إنذار بسيط وفعال.  


---

## 🛠️ المكونات | Components  
- Arduino Board (Uno/Nano)  
- MQ-2 Gas Sensor  
- LCD I2C Display  
- Buzzer للتنبيه الصوتي  
- أسلاك توصيل + Breadboard  

---

## 💻 الملفات | Files  
- `main.ino` → كود Arduino للتحكم بالمستشعرات والعرض.  
- `smoke_detector.py` → سكربت Python للتكامل مع أنظمة خارجية أو تحليل البيانات.  

---

## ⚙️ طريقة التشغيل | How to Run  
1. وصل المستشعرات بالـ Arduino حسب المخطط.  
2. ارفع كود `main.ino` باستخدام Arduino IDE.  
3. شغل سكربت `smoke_detector.py` إذا كنت عايز تكامل مع الكمبيوتر أو السحابة.  
4. عند الكشف عن دخان/غاز، سيظهر تنبيه على الشاشة مع صوت إنذار.  

---

## 📡 التوسع المستقبلي | Future Expansion  
- ربط النظام مع **ESP8266/ESP32** لإرسال إشعارات عبر الإنترنت.  
- إضافة دعم لتطبيقات الهاتف المحمول.  
- تحسين دقة الكشف عبر معايرة المستشعر.  

---
# 🔌 Wiring Diagram | مخطط التوصيلات

## 🛠️ المكونات
- Arduino Uno
- MQ-2 Gas Sensor
- LCD I2C Display
- Buzzer
- Jumper Wires

## ⚙️ التوصيلات
- MQ-2 → Arduino
  - VCC → 5V
  - GND → GND
  - AO → A0

- LCD I2C → Arduino
  - VCC → 5V
  - GND → GND
  - SDA → A4
  - SCL → A5

- Buzzer → Arduino
  - + → D8
  - - → GND


## 📜 الترخيص | License  
MIT License – مفتوح المصدر للاستخدام والتطوير.

Added basic code to connect to Wi-Fi.
Prepared structure for sending alerts via HTTP.
