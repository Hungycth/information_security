# Thuật toán mã hóa dòng RC4 (Rivest Cipher 4)
**Môn học:** An toàn thông tin  
**Giảng viên hướng dẫn:** TS. Tạ Thị Kim Huệ  
**Sinh viên thực hiện:** Cao Quang Hưng (MSSV: 20234012)

---

## 📖 Mô tả bài tập
Chương trình thực hiện mô phỏng thuật toán mã hóa dòng RC4 với hai kịch bản:
1. **Câu 1:** Sinh dòng khóa (Keystream) gồm 13 bytes với vector trạng thái rút gọn $S_{len} = 10$ để minh họa logic bước nhảy.
2. **Câu 2:** Ứng dụng mã hóa chuỗi văn bản thực tế `'cybersecurity'`.

## ⚙️ Đặc điểm kỹ thuật
- **Ngôn ngữ:** C++17.
- **Tham số hóa:** Hàm `rc4_encrypt` và `ksa` được thiết kế linh hoạt, cho phép thay đổi độ dài vector trạng thái $S$ (mặc định 256, trong bài tập này sử dụng 10 theo yêu cầu).
- **Định dạng đầu ra:** Hiển thị kết quả dưới dạng số Thập phân (Dec), số Thập lục phân (Hex) và ký tự ASCII để tiện đối soát.
- **Xác minh:** Tích hợp tính năng tự động giải mã để kiểm tra tính đối xứng của thuật toán.

## 💻 Hướng dẫn thực thi
Cô có thể sử dụng file thực thi tĩnh đã được build sẵn tại thư mục `bin/` bằng cách:
- Click đúp vào file **`Click_To_Run.bat`**.
- Hoặc chạy lệnh: `./bin/rc4_demo.exe` trong Terminal.

---