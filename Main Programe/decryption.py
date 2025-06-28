# filepath: c:\Users\sdb46\Desktop\Main Programe\decrypt_data.py
from cryptography.fernet import Fernet

# File paths
KEY_FILE = 'encryption.key'
DATA_FILE = 'encrypted_data.txt'

# Load the encryption key
def load_key():
    with open(KEY_FILE, 'rb') as key_file:
        return key_file.read()

# Decrypt the data
def decrypt_data():
    key = load_key()
    cipher = Fernet(key)

    with open(DATA_FILE, 'rb') as file:
        encrypted_lines = file.readlines()

    for encrypted_line in encrypted_lines:
        decrypted_data = cipher.decrypt(encrypted_line.strip())
        print(decrypted_data.decode())

if __name__ == '__main__':
    decrypt_data()