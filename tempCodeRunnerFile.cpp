#include <iostream>
#include <limits>

int main() {
    int n;
    while (true) {
        std::cout << "Nhap mot so nguyen: ";
        std::cin >> n;

        // Kiểm tra nếu cin thất bại (người dùng nhập không phải số)
        if (std::cin.fail()) {
            std::cin.clear(); // Xóa cờ lỗi của cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua phần nhập không hợp lệ
            std::cout << "Gia tri nhap khong hop le. Vui long nhap lai." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua phần nhập còn lại (nếu có)
            break; // Thoát vòng lặp nếu nhập thành công
        }
    }

    std::cout << "So ban da nhap la: " << n << std::endl;

    return 0;
}
