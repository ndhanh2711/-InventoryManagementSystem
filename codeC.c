#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc mathang
typedef struct {
    char tenhang[100];
    int soluong;
    double giathanh;
    char codeitem[100];
} mathang;

mathang kho[100];

void taokho() {
    // khởi tạo các mặt hàng có sẵn trong kho 
    strcpy(kho[0].tenhang, "kem danh rang");
    kho[0].soluong = 10;  // Ví dụ về việc khởi tạo số lượng
    kho[0].giathanh = 20000.0;  // Ví dụ về việc khởi tạo giá thành
    strcpy(kho[0].codeitem, "KDR001");  // Ví dụ về việc khởi tạo mã sản phẩm
}

int main() {
    taokho();
    printf("Ten hang: %s\n", kho[0].tenhang);
    printf("So luong: %d\n", kho[0].soluong);
    printf("Gia thanh: %.2f\n", kho[0].giathanh);
    printf("Ma san pham: %s\n", kho[0].codeitem);
    return 0;
}
