# Tìm Nghịch Đảo Trong Trường Hữu Hạn GF(2^10)
**Môn học:** An toàn thông tin - E9  
**Giảng viên hướng dẫn:** ThS. Tạ Thị Kim Huệ  
**Sinh viên thực hiện:** Cao Quang Hưng  
**MSSV:** 20234012 - **Lớp:** IoT 01-K68

---

> **Gửi cô Huệ:** Để tiết kiệm thời gian cho cô trong quá trình chấm bài, em đã đóng gói sẵn mã nguồn kèm theo file thực thi tĩnh (static binary). Cô có thể chạy trực tiếp trên máy Windows mà không cần cài đặt thêm thư viện hay trình biên dịch.
> - **Cách chạy nhanh:** Cô chỉ cần click đúp vào file `Click_To_Run.bat` ngay tại thư mục này.

---

## 📂 Cấu trúc dự án
Dự án được quy hoạch theo chuẩn để tách biệt mã nguồn và sản phẩm thực thi:
* `src/`: Chứa mã nguồn chính (`GF2.cpp`).
* `bin/`: Chứa file thực thi tĩnh `GF2_Windows.exe` đã được build sẵn.
* `Click_To_Run.bat`: File script giúp khởi chạy chương trình ngay lập tức.
* `README.md`: Tài liệu hướng dẫn này.

## 🧮 Cơ sở toán học
Chương trình cài đặt thuật toán **Euclidean mở rộng (Extended Euclidean Algorithm)** để tìm nghịch đảo nhân:
- **Trường hữu hạn:** $GF(2^{10})$
- **Đa thức tối giản:** $m(x) = x^{10} + x^3 + 1$ (Số nguyên tương ứng: `1033`).
- **Phép toán:** Sử dụng các phép toán trên bit (`XOR`, `shift`) để mô phỏng tính toán đa thức trên trường nhị phân, đảm bảo tốc độ và độ chính xác.

## 🚀 Chức năng chính
1. **Tính nghịch đảo:** Tìm đa thức $a^{-1}$ sao cho $(a \cdot a^{-1}) \pmod{m(x)} = 1$.
2. **Báo cáo chi tiết:** In ra bảng giá trị trung gian qua từng bước lặp (`Step`, `Quotient`, `Remainder`, `s`) để cô dễ dàng theo dõi logic thuật toán.
3. **Xác minh kết quả:** Chương trình tự động nhân ngược kết quả với số ban đầu và kiểm tra số dư để khẳng định tính đúng đắn trước khi kết thúc.

## 🛠 Hướng dẫn biên dịch (Dành cho Dev)
Nếu cần biên dịch lại từ mã nguồn, yêu cầu trình biên dịch hỗ trợ chuẩn **C++17** trở lên. 

Lệnh biên dịch tĩnh (để file `.exe` có thể chạy độc lập trên các máy Windows khác):
```bash
g++ -std=c++17 -static src/GF2.cpp -o bin/GF2.exe