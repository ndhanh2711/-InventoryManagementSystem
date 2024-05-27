#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Định nghĩa cấu trúc mathang
typedef struct {
    char tenhang[100];
    int soluong;
    double giathanh;
    char codeitem[100];
} mathang;

mathang kho[100];
int demhang=0;
void taokho() {
    // khởi tạo các mặt hàng có sẵn trong kho 
     strcpy(kho[0].tenhang, "Kem danh rang");
    kho[0].soluong = 10;
    kho[0].giathanh = 35000;

    strcpy(kho[1].tenhang, "Sua tam");
    kho[1].soluong = 20;
    kho[1].giathanh = 75000;

    strcpy(kho[2].tenhang, "Ban chai");
    kho[2].soluong = 100;
    kho[2].giathanh = 45000;

    strcpy(kho[3].tenhang, "Khau trang");
    kho[3].soluong = 2000;
    kho[3].giathanh = 100000;

    strcpy(kho[4].tenhang, "My pham");
    kho[4].soluong = 250;
    kho[4].giathanh = 500000;

    strcpy(kho[5].tenhang, "Dau goi dau");
    kho[5].soluong = 200;
    kho[5].giathanh = 180000;

    strcpy(kho[6].tenhang, "Kem chong nang");
    kho[6].soluong = 150;
    kho[6].giathanh = 250000;

    strcpy(kho[7].tenhang, "Sua rua mat");
    kho[7].soluong = 100;
    kho[7].giathanh = 180000;

    strcpy(kho[8].tenhang, "Xa phong");
    kho[8].soluong = 1000;
    kho[8].giathanh = 150000;

    strcpy(kho[9].tenhang, "Serum");
    kho[9].soluong = 20000;
    kho[9].giathanh = 100000; 
    demhang = 10;
}
int somathang(){
    return demhang;
}
void hienthi(int n){
    printf("$_____$_________________________$________________$________________$\n");
    printf("| STT |       TÊN SẢN PHẨM      |    SỐ LƯỢNG    |    GIÁ/1 SP    |\n");
    printf("|-----|-------------------------|----------------|----------------|\n");
    for(int i = 0; i < n; i++){
        if(strlen(kho[i].tenhang) == 0) continue;  // Chỉ hiển thị mặt hàng có tên
        printf("| %-3d  | %-23s | %-14d | %-14.2f |\n", i+1, kho[i].tenhang, kho[i].soluong, kho[i].giathanh);
    }
    printf("|______$_________________________$________________$________________$\n");
}
void nhap(mathang *a){
// Xóa bộ đệm đầu vào để tránh vấn đề với hàm fgets
    while(getchar() != '\n');
    
    printf("Nhap ten loai mat hang: ");
    fgets(a->tenhang, 100, stdin);
    // Loại bỏ ký tự newline nếu có
    size_t len = strlen(a->tenhang);
    if (len > 0 && a->tenhang[len-1] == '\n') {
        a->tenhang[len-1] = '\0';
    }

    printf("Nhap so luong san pham nhap vao kho: ");
    scanf("%d", &(a->soluong));
    
    printf("Nhap gia tien tren mot san pham: ");
    scanf("%lf", &(a->giathanh));
}

void sapxep(mathang *kho,int n){
    int luachon;
    printf("Sắp xếp sản phẩm\n");
    printf("Chọn 1: xắp xếp theo giá thành\n");
    printf("Chọn 2: xắp sếp theo số lượng\n");
    while (true){
    scanf("%d",&luachon);
    if(luachon==1){
        int chon;
        printf("1. Tăng dần\n");
        printf("2. Giảm dần\n");
        while (true){
        scanf("%d",&chon);
        if(chon==1){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].giathanh>kho[j].giathanh){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        if(chon==2){
             for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].giathanh<kho[j].giathanh){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        else printf("Lựa chọn không hợp lệ vui lòng nhập lại\n");
        }
        break;
    }
    if(luachon==2){
        int chon;
        printf("1. Tăng dần\n");
        printf("2. Giảm dần\n");
        while(true){
        scanf("%d",&chon);
        if(chon==1){
             for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].soluong>kho[j].soluong){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        if(chon==2){
             for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].soluong<kho[j].soluong){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        else printf("Lựa chọn không hợp lệ vui lòng nhập lại\n");
        break;
        }
    }
    else {
        printf("Lựa chọn không hợp lệ vui lòng nhập lại\n");
    }
   }

}
int main() {
    taokho();
    hienthi(somathang());
    sapxep(kho,somathang());
    return 0;
}