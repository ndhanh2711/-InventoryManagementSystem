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
    printf("$______$_________________________$________________$________________$\n");
    printf("| STT  |       TEN SAN PHAM      |    SO LUONG    |    GIA/1 SP    |\n");
    printf("|------|-------------------------|----------------|----------------|\n");
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
void xuatkho(){
    int a;
    printf("So mat hang muon xuat kho: ");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int xuat;
        printf("Nhap ma san pham %d: ",i+1);
        scanf("%d",&xuat);
        if(xuat<0||xuat>somathang()){
            printf("Ma san pham khong hop le vui long nhap lai ");
            i--;
            continue;
        }
        int soluong=0;

        while(1){
        printf("Nhap so luong: ");
        scanf("%d",&soluong);
        if(soluong > 0 && soluong<=kho[xuat-1].soluong){
            break; // số lượng hợp lệ thoát vòng while
        }
        else printf("So luong khong hop le vui long nhap lai: ");
        }
        kho[xuat-1].soluong=kho[xuat-1].soluong-soluong;
        if(kho[xuat-1].soluong==0){
            for(int i=xuat-1;i<=somathang();i++){
                kho[i]=kho[i+1];
            }
            demhang--;
        }
    }
    hienthi(somathang());
}
void nhapkho(){
    int n;
    printf("So mat hang dang co trong kho: %d\n",somathang());
    printf("So mat hang muon them vao kho: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap thong tin mat hang so %d:\n", somathang() + i + 1);
        nhap(&kho[demhang + i]);
    }
    demhang+=n;
    printf("Cap nhat thong tin hien tai\n");
    hienthi(somathang());
}
void sapxep(mathang *kho,int n){
    int luachon;
    printf("Sap xep san pham\n");
    printf("Chon 1: xap xep theo gia thanh\n");
    printf("Chon 2: xap sep theo so luong\n");
    while (true){
    scanf("%d",&luachon);
    if(luachon==1){
        int chon;
        printf("1. Tang dan\n");
        printf("2. Giam dan\n");
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
        else printf("Lua chon khong hop le vui long nhap lai\n");
        }
        break;
    }
    if(luachon==2){
        int chon;
        printf("1. Tang dan\n");
        printf("2. Giam dan\n");
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
     while(1){
        printf("______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______\n");
        printf("|  1.XEM THONG TIN MAT HANG TON KHO                  |\n");
        printf("|  2.XUAT KHO                                        |\n");
        printf("|  3.NHAP HANG VAO KHO                               |\n");
        printf("|  4.SAP XEP THEO YEU CAU                            |\n");
        printf("|  0.EXIT THE SYSTEM.                                |\n");
        printf("!____________________________________________________!\n");
        printf("SELECT OPTION: ");
        int lc;
        scanf("%d",&lc);
        if(lc == 1){
            hienthi(somathang());
            //FINISHED
        }
        else if(lc == 2){
            //FINISHED
            xuatkho();
        }
        else if(lc == 3){
            nhapkho();
        }
        else if(lc == 4){
            // Implement sorting functionality here
            sapxep(kho,somathang());
        }
        else if(lc == 0){
            //FINISHED
            printf("*************   HE THONG DA DONG   *************\n");
            return 0;
        }
        else {
            printf("Lua chon khong họp le vui long nhap lai ");
        }
    }
    return 0;
}