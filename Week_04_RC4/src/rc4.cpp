#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
using byte = unsigned char;

// Hàm in vector dưới dạng thập phân
void print_vector_dec(const vector<unsigned char>& vec, const string& label) {
    cout << label << " [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << static_cast<int>(vec[i]) << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

// Hàm in vector dưới dạng hex
void print_vector_hex(const vector<unsigned char>& vec, const string& label) {
    cout << label << " [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "0x" << hex << static_cast<int>(vec[i]) << dec << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

// Thuật toán lập lịch khóa (Key Scheduling Algorithm)
vector<unsigned char> ksa(const vector<unsigned char>& key, size_t S_len = 256) {
    vector<unsigned char> S(S_len);
    for (size_t i = 0; i < S_len; ++i) {
        S[i] = static_cast<unsigned char>(i);
    }

    size_t j = 0;
    for (size_t i = 0; i < S_len; ++i) {
        j = (j + S[i] + key[i % key.size()]) % S_len;
        swap(S[i], S[j]);
    }
    return S;
}

// Thuật toán sinh dòng giả ngẫu nhiên (Pseudo-Random Generation Algorithm)
vector<unsigned char> prga(vector<unsigned char> S, size_t n) {
    vector<unsigned char> keystream;
    keystream.reserve(n);
    size_t i = 0;
    size_t j = 0;

    for (size_t k = 0; k < n; ++k) {
        i = (i + 1) % S.size();
        j = (j + S[i]) % S.size();
        swap(S[i], S[j]);
        size_t t = (S[i] + S[j]) % S.size();
        keystream.push_back(S[t]);
    }
    return keystream;
}

// Hàm mã hóa RC4
vector<unsigned char> rc4_encrypt(const vector<unsigned char>& plaintext, const vector<unsigned char>& key, size_t S_len = 256) {
    vector<unsigned char> S = ksa(key, S_len);
    vector<unsigned char> keystream = prga(S, plaintext.size());
    vector<unsigned char> ciphertext(plaintext.size());
    for (size_t i = 0; i < plaintext.size(); ++i) {
        ciphertext[i] = plaintext[i] ^ keystream[i];
    }
    return ciphertext;
}

int main() {
    cout << "--------------------------------------------------\n";
    cout << "Cau 1: Tinh cac gia tri cua dong khoa duoc tao ra boi RC4\n";
    cout << "--------------------------------------------------\n";

    vector<unsigned char> K_1 = {2, 4, 1, 7};
    print_vector_dec(K_1, "Khoa K:");

    size_t S_len_1 = 10;
    vector<unsigned char> S_after_ksa = ksa(K_1, S_len_1);
    print_vector_dec(S_after_ksa, "Vector trang thai S sau khi khoi tao (KSA):");

    size_t n_bytes_to_generate = 13;
    vector<unsigned char> keystream_1 = prga(S_after_ksa, n_bytes_to_generate);
    print_vector_dec(keystream_1, "Dong khoa (Keystream) duoc tao ra (" + to_string(n_bytes_to_generate) + " bytes):");

    cout << "\n==================================================\n\n";
    cout << "--------------------------------------------------\n";
    cout << "Cau 2: Tim ban ma m(t) = 'cybersecurity'\n";
    cout << "--------------------------------------------------\n";

    string message = "cybersecurity";
    vector<unsigned char> key_2 = {2, 4, 1, 7};
    cout << "Ban ro m(t): '" << message << "'\n";

    vector<unsigned char> m_ascii(message.begin(), message.end());
    print_vector_dec(m_ascii, "Ban ro (ASCII):");

    vector<unsigned char> ciphertext = rc4_encrypt(m_ascii, key_2, 10);
    vector<unsigned char> keystream_2 = prga(ksa(key_2, 10), message.length()); // Tái tạo keystream để in

    print_vector_dec(keystream_2, "Dong khoa (Keystream) he co so 10:");
    print_vector_hex(keystream_2, "Dong khoa (Keystream) dang HEX:");

    print_vector_dec(ciphertext, "Ban ma C(t) he co so 10:");
    print_vector_hex(ciphertext, "Ban ma C(t) dang HEX:");

    cout << "Ban ma (Ky tu): '";
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        cout << static_cast<char>(ciphertext[i]);
    }
    cout << "'\n";

    cout << "\nKiem tra lai viec giai ma: '";
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        cout << static_cast<char>(ciphertext[i] ^ keystream_2[i]);
    }
    cout << "' (Thanh cong)\n";

    return 0;
}
