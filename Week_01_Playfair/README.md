# Playfair Cipher Implementation (C++)

## 📌 Giới thiệu
Project này cài đặt thuật toán mã hóa cổ điển **Playfair Cipher** bằng ngôn ngữ C++.  
Đây là bài tập thực hành thuộc học phần **An toàn thông tin - E9**.

**Sinh viên thực hiện:**
- **Họ và tên:** Cao Quang Hưng
- **MSSV:** 20234012

## 🧠 Thuật toán Playfair
Playfair Cipher là thuật toán mã hóa đối xứng thay thế đa ký tự, sử dụng một ma trận khóa 5x5.

### Quy tắc xử lý trong bài:
1. **Ma trận khóa:** Sử dụng ma trận cố định `MONARCHY...` (theo yêu cầu bài tập).
2. **Ký tự đặc biệt:** Ký tự 'J' trong văn bản được quy đổi về 'I' để phù hợp với ma trận 5x5.
3. **Quy tắc mã hóa/giải mã:**
   - Nếu 2 chữ cùng hàng → thay bằng chữ bên phải (mã hóa) hoặc bên trái (giải mã).
   - Nếu 2 chữ cùng cột → thay bằng chữ bên dưới (mã hóa) hoặc bên trên (giải mã).
   - Nếu tạo thành hình chữ nhật → đổi vị trí cho hai góc còn lại trên cùng hàng.

## ⚙️ Hướng dẫn biên dịch và chạy
### Yêu cầu:
- Trình biên dịch: `g++` (MinGW/GCC).

### Các bước thực hiện:
1. Mở Terminal/Git Bash tại thư mục chứa file.
2. Biên dịch mã nguồn:
   ```bash
   g++ playfair_cipher.cpp -o playfair