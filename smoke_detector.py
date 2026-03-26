import time
import random

# 🌹 نظام كشف النقاب الذكي - وحدة مراقبة الدخان
def start_scan():
    print("--- [GARDEN SAFETY: SMOKE RADAR ACTIVE] ---")
    time.sleep(1)

    try:
        while True:
            # محاكاة لقراءة الحساس
            level = random.randint(150, 450)
            
            if level > 350:
                print(f"[!] WARNING: Smoke Detected! Level: {level} ⚠️")
            else:
                print(f"[OK] System Stable. Level: {level}")
            
            time.sleep(1.5)
    except KeyboardInterrupt:
        print("\n[OFF] Monitoring Paused. 🌹")

if __name__ == "__main__":
    start_scan()
    
