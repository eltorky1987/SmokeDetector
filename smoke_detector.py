import time
import random

# 🌹 نظام كشف النقاب الذكي | وحدة مراقبة الدخان
def start_monitoring():
    print("--- [GARDEN SAFETY: SMOKE RADAR ACTIVE] ---")
    print("Scanning for carbon particles...")
    time.sleep(1.5)

    try:
        while True:
            # محاكاة لقراءة الحساس (MQ-2)
            smoke_level = random.randint(100, 500)
            
            if smoke_level > 350:
                print(f"[!] ALERT: High Smoke Density! Value: {smoke_level} ⚠️")
            else:
                print(f"[OK] Air Quality: Normal ({smoke_level})")
            
            time.sleep(2)
    except KeyboardInterrupt:
        print("\n[STOP] Monitoring deactivated by user. 🌹")

if __name__ == "__main__":
    start_monitoring()
  
