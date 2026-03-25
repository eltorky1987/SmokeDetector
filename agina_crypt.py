import os
from cryptography.fernet import Fernet
def get_key():
    if not os.path.exists("secret.key"): 
        key = Fernet.generate_key()
        with open("secret.key", "wb") as kf: kf.write(key)
    return open("secret.key", "rb").read()
key = get_key()
f = Fernet(key)
print("\n--- 🔐 سرداب أجينا الشغال ---")
print("1.تشفير كلمة\n2. فك التشفير")
choice = input("\nاختار: ")
if choice == "1":
    text = input("اكتب الكلمة: ")
    token = f.encrypt(text.encode())
    with open("last_token.txt", "wb") as tf: tf.write(token)
    print(f"\n✅ الكود السري:{token.decode()}")
elif choice == "2":
    if os.path.exists("last_token.txt"):
        token = open("last_token.txt", "rb").read()
        print(f"\n🔓 الكلمة: {f.decrypt(token).decode()}")
    else: print("\n❌ مفيش كلمات!")