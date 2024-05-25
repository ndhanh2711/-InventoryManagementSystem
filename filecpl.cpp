#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
                #define RESET   "\033[0m"
                #define RED     "\033[31m"
                #define GREEN   "\033[32m"
                #define YELLOW  "\033[33m"
                #define BLUE    "\033[34m"
                #define MAGENTA "\033[35m"
                #define CYAN    "\033[36m"
using namespace std;
struct mathang{
    char tenhang[100];
    int soluong;
    double giathanh;
    char codeitem;
};
typedef struct mathang mathang;
std::vector<mathang> kho(100);
void nhap2(std::vector<mathang>& kho, int n) {
    std::cin.ignore();
    std::cout << "Name: ";
    std::cin.getline(kho[n].tenhang, 100);
    std::cout << "Sl: ";
    std::cin >> kho[n].soluong;
    std::cin.ignore();
    std::cout << "Cost/item: ";
    std::cin >> kho[n].giathanh;
}
int cnt(int n){ //Hàm tính độ dài của 1 số để căn lề bẳng sản phẩm
    int count = 1;
    if(n == 0){
        return 2;
    }
    while(n){
        count++;
        n /= 10;
    }
    return count;
}

void taokho() {
    
    // Khởi tạo các giá trị cho mỗi mặt hàng trong kho
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
    
    
}

int somathang(){
    int cnt = 0;
    for(int i = 0; i < kho.size(); i++){
        if(strlen(kho[i].tenhang)){
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt;
}


long long costofwh(){
    long long cost = 0;
    for(int i = 0; i < somathang(); i++){
        cost += kho[i].soluong * kho[i].giathanh;
    }
    return cost;
}
void hienthikho(int n){ //Hàm hiển thị kho hàng với các mặt hàng sẵn có
    cout << CYAN;
    cout << "$_____$_______________________$________________$___________________$"<< endl;
    cout << "| STT |" <<"    THE PRODUCT NAME   |" << "  THE QUANTITY  |" << "   COST/1item($)   |"<<endl;
    for(int i = 0; i < n; i++){
        if(i < 10){
            printf("|  %d  |", i);
        }
        else if(i >= 10 && i < 100){
            printf("|  %d |", i);
        }
        else if(i == 100){
            printf("|%d|", i);
        }
        int a = strlen(kho[i].tenhang);
        cout << kho[i].tenhang << setw(24 - a) << "|";
        int b = cnt(kho[i].soluong);
        cout << kho[i].soluong << setw(18 - b) << "|";
        int c = cnt(kho[i].giathanh);
            cout << fixed <<kho[i].giathanh << " " << setw(12 - c) << "|"<<endl;
    }
    cout << "$-----$-----------------------$----------------$-------------------$\n" << endl;
    cout << RESET;
    cout << YELLOW << "Tong so tien hang co trong kho bay gio la:" << costofwh() << RESET << endl;
    for(int i = 0; i < n; i++){
        if(kho[i].soluong < 20){
            cout << RED << "INFORM: Mat hang" << kho[i].tenhang << "trong kho qua it de duy tri nhu cau" << endl << RESET;
        }
    }
}
void xuatkho(){
    taokho();
            int xuat;
            cout << "SO MAT HANG MUON XUAT KHO: ";
            cin >> xuat;
            for(int i = 0; i < xuat; i++){
                int x;
                printf("NHAP MA SAN PHAM %d: ", i + 1); //hiện tại vẫn đang chọn số, sau đó sẽ cải tiến lên thành mã đơn hàng
                cout << "SO LUONG: ";
                while(1){
                    int a;
                    cin >> a;
                    if( a > kho[x].soluong ){
                        cout << "So luong mat hang trong kho khong du so voi yeu cau" << endl;
                        cout << "Yeu cau nhap lai: ";
                        continue;
                    }
                    else{
                        kho[x].soluong -= a;
                    }
                }
            }
            cout << "CAP NHAT KHO HANG HIEN TAI"<< endl;
            hienthikho(somathang());
    }
void nhapkho(){
    taokho();
    cout << "So mat hang co trong kho la: ";
    cout << somathang() << endl;
    cout << "SO LUONG MAT HANG MUON THEM VAO KHO: ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        printf("NHAO THONG TIN MAT HANG SO %d:\n", somathang() + i);
        nhap2(kho, somathang() + i);
    }
    cout << "CAP NHAT KHO HANG HIEN TAI"<<endl;
    hienthikho(somathang() + n);
}
void baomat(){
    cout << RED;
    string a = "alester";
    string b = "top1thaibinh";
    cout << "LOG IN(Use the English keyboard to type.)"<<endl;
    while(1){
        cout << "User name:";
        string tk;
        cin >> tk;
        if(a.compare(tk) != 0){
            cout << "Wrong account, please enter again." << endl;
            continue;
        }
        else{
            cout << "Password:";
            string mk;
            cin >> mk;
            if(mk.compare(b) != 0){
                cout << "Wrong password, please re-enter." << endl;
                continue;
            }
            else{
                break;
            }
        }
    }
    cout << RESET;
}
int main() {
    while(1){
        cout << MAGENTA << "______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______" << endl;
        cout << "|  1.XEM THONG TIN MAT HANG TON KHO                  |" << endl;
        cout << "|  2.XUAT KHO                                        |" << endl;
        cout << "|  3.NHAP HANG VAO KHO                               |" << endl;
        cout << "|  4.SAP XEP THEO YEU CAU                            |" << endl;
        cout << "|  0.EXIT THE SYSTEM.                                |" << endl;
        cout << "!____________________________________________________!" << endl;
        cout << "SELECT OPTION: " << RESET;
        int lc;
        cin >> lc;
        if(lc == 1){
            taokho();
            hienthikho(10);
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
            
        }
        else if(lc == 0){
            //FINISHED
            cout << "*************   HE THONG DA DONG   *************"<<endl;
            return 0;
        }
    }
    return 0;
}
