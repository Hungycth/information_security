#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Thuật toán lập lịch khóa (Key Scheduling Algorithm)
vector<int> ksa(const vector<int>& key, int S_len = 256) {
    vector<int> S(S_len);
    for (int i = 0; i < S_len; ++i) {
        S[i] = i;
    }
    
    int j = 0;
    for (int i = 0; i < S_len; ++i) {
        j = (j + S[i] + key[i % key.size()]) % S_len;
        swap(S[i], S[j]);
    }
    return S;
}

// Thuật toán sinh dòng giả ngẫu nhiên (Pseudo-Random Generation Algorithm)
vector<int> prga(const vector<int>& S_in, int n) {
    vector<int> S = S_in; // Tạo một bản sao để không làm thay đổi trạng thái S ban đầu
    vector<int> keystream;
    int i = 0;
    int j = 0;
    
    for (int k = 0; k < n; ++k) {
        i = (i + 1) % S.size();
        j = (j + S[i]) % S.size();
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % S.size();
        keystream.push_back(S[t]);
    }
    return keystream;
}

int main() {
    cout << "--------------------------------------------------\n";
    cout << "Cau 1: Tinh cac gia tri cua dong khoa duoc tao ra boi RC4\n";
    cout << "--------------------------------------------------\n";
    
    vector<int> K_1 = {2, 4, 1, 7};
    cout << "Khoa K: [";
    for (size_t i = 0; i < K_1.size(); ++i) {
        cout << K_1[i] << (i == K_1.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
    
    int S_len_1 = 10;
    vector<int> S_after_ksa = ksa(K_1, S_len_1);
    
    cout << "Vector trang thai S sau khi khoi tao (KSA): [";
    for (size_t i = 0; i < S_after_ksa.size(); ++i) {
        cout << S_after_ksa[i] << (i == S_after_ksa.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
    
    int n_bytes_to_generate = 10;
    vector<int> keystream_1 = prga(S_after_ksa, n_bytes_to_generate);
    
    cout << "Dong khoa (Keystream) duoc tao ra (" << n_bytes_to_generate << " bytes): [";
    for (size_t i = 0; i < keystream_1.size(); ++i) {
        cout << keystream_1[i] << (i == keystream_1.size() - 1 ? "" : ", ");
    }
    cout << "]\n\n";
    
    cout << "==================================================\n\n";
    cout << "--------------------------------------------------\n";
    cout << "Cau 2: Tim ban ma m(t) = 'cybersecurity'\n";
    cout << "--------------------------------------------------\n";
    
    string message = "cybersecurity";
    vector<int> key_2 = {2, 4, 1, 7};
    cout << "Ban ro m(t): '" << message << "'\n";
    
    vector<int> m_ascii;
    cout << "Ban ro (ASCII): [";
    for (size_t i = 0; i < message.length(); ++i) {
        m_ascii.push_back((unsigned char)message[i]);
        cout << m_ascii[i] << (i == message.length() - 1 ? "" : ", ");
    }
    cout << "]\n";
    
    vector<int> S_after_ksa_2 = ksa(key_2, 256);
    vector<int> keystream_2 = prga(S_after_ksa_2, message.length());
    
    cout << "Dong khoa (Keystream) he co so 10: [";
    for (size_t i = 0; i < keystream_2.size(); ++i) {
        cout << keystream_2[i] << (i == keystream_2.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
    
    cout << "Dong khoa (Keystream) dang HEX: [";
    for (size_t i = 0; i < keystream_2.size(); ++i) {
        cout << "0x" << hex << keystream_2[i] << dec << (i == keystream_2.size() - 1 ? "" : ", ");
    }
    cout << "]\n\n";
    
    vector<int> ciphertext;
    cout << "Ban ma C(t) he co so 10: [";
    for (size_t i = 0; i < message.length(); ++i) {
        ciphertext.push_back(m_ascii[i] ^ keystream_2[i]);
        cout << ciphertext[i] << (i == message.length() - 1 ? "" : ", ");
    }
    cout << "]\n";
    
    cout << "Ban ma C(t) dang HEX: [";
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        cout << "0x" << hex << ciphertext[i] << dec << (i == ciphertext.size() - 1 ? "" : ", ");
    }
    cout << "]\n\n";
    
    cout << "Kiem tra lai viec giai ma: '";
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        cout << (char)(ciphertext[i] ^ keystream_2[i]);
    }
    cout << "' (Thanh cong)\n";
    
    return 0;
}
