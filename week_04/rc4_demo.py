import sys
import codecs
if sys.stdout.encoding.lower() != 'utf-8':
    sys.stdout.reconfigure(encoding='utf-8')

def ksa(key, S_len=256):
    """Key Scheduling Algorithm (KSA)"""
    S = list(range(S_len))
    j = 0
    for i in range(S_len):
        j = (j + S[i] + key[i % len(key)]) % S_len
        S[i], S[j] = S[j], S[i]
    return S

def prga(S, n):
    """Pseudo-Random Generation Algorithm (PRGA)"""
    i = 0
    j = 0
    keystream = []
    S = S[:] # Make a copy so we don't modify the original state during generation
    for _ in range(n):
        i = (i + 1) % len(S)
        j = (j + S[i]) % len(S)
        S[i], S[j] = S[j], S[i]
        t = (S[i] + S[j]) % len(S)
        keystream.append(S[t])
    return keystream

def rc4_encrypt(plaintext_ascii, key):
    """Encrypts plaintext using RC4 algorithm"""
    S = ksa(key, 256)
    keystream = prga(S, len(plaintext_ascii))
    ciphertext = [p ^ k for p, k in zip(plaintext_ascii, keystream)]
    return ciphertext, keystream

def rc4_decrypt(ciphertext, key):
    """Decrypts ciphertext using RC4. Since RC4 is symmetric, encryption and decryption are the same."""
    S = ksa(key, 256)
    keystream = prga(S, len(ciphertext))
    plaintext_ascii = [c ^ k for c, k in zip(ciphertext, keystream)]
    return plaintext_ascii

if __name__ == "__main__":
    print("-" * 50)
    print("Câu 1: Tính các giá trị của dòng khoá được tạo ra bởi RC4")
    print("-" * 50)
    S_initial = list(range(10))
    K_1 = [2, 4, 1, 7]
    print(f"Vector trạng thái ban đầu S: {S_initial}")
    print(f"Khóa K: {K_1}")
    
    # Số lượng byte dòng khóa cần sinh ra (ví dụ: sinh ra 10 byte)
    n_bytes_to_generate = 10 
    
    S_after_ksa = ksa(K_1, 10)
    print(f"Vector trạng thái S sau khi khởi tạo (KSA): {S_after_ksa}")
    
    keystream_1 = prga(S_after_ksa, n_bytes_to_generate)
    print(f"Dòng khóa (Keystream) được tạo ra ({n_bytes_to_generate} bytes): {keystream_1}")
    print("\n" + "=" * 50 + "\n")

    print("-" * 50)
    print("Câu 2: Tìm bản mã m(t) = 'cybersecurity'")
    print("-" * 50)
    
    message = "cybersecurity"
    key_2 = [2, 4, 1, 7]
    print(f"Bản rõ m(t): '{message}'")
    print(f"Khóa K: {key_2}")
    
    # Chuyển đổi bản rõ sang ASCII
    m_ascii = [ord(c) for c in message]
    print(f"Bản rõ (ASCII): {m_ascii}")
    
    # Vector trạng thái S mặc định là 256 phần tử vì biểu diễn bằng 1 byte
    ciphertext, keystream_2 = rc4_encrypt(m_ascii, key_2)
    
    print(f"Dòng khóa (Keystream) hệ cơ số 10: {keystream_2}")
    print(f"Dòng khóa (Keystream) dạng HEX: {[hex(k) for k in keystream_2]}")
    
    print(f"\nBản mã C(t) hệ cơ số 10: {ciphertext}")
    print(f"Bản mã C(t) dạng HEX: {[hex(c) for c in ciphertext]}")
    
    # Giải mã để kiểm tra
    decrypted_ascii = rc4_decrypt(ciphertext, key_2)
    decrypted_message = "".join(chr(c) for c in decrypted_ascii)
    print(f"\nKiểm tra lại việc giải mã: '{decrypted_message}' {'(Thành công)' if decrypted_message == message else '(Thất bại)'}")
