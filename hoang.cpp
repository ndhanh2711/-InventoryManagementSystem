#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>
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
    string code;
};
string generateCode(const string& name) {
    string code = "";
    bool isNewWord = true;
    for (size_t i = 0; i < name.length(); ++i) {
        char c = name[i];
        if (isNewWord && isalpha(c)) {
            code += tolower(c);
            isNewWord = false;
        }
        if (isspace(c)) {
            isNewWord = true;
        }
    }
    return code;
}

typedef struct mathang mathang;
std::vector<mathang> kho(100);
void nhap2(std::vector<mathang>& kho, int n) {
    cin.ignore();
    std::cout << "Name: ";
    std::cin.getline(kho[n].tenhang, 100);
    std::cout << "Sl: ";
    std::cin >> kho[n].soluong;
    std::cin.ignore();
    std::cout << "Cost/item: ";
    std::cin >> kho[n].giathanh;
    kho[n].code = generateCode(kho[n].tenhang);
}
int cnt(int n){ //Hàm tính d? dài c?a 1 s? d? can l? b?ng s?n ph?m
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
    
    // Kh?i t?o các giá tr? cho m?i m?t hàng trong kho
    strcpy(kho[0].tenhang, "Kem danh rang");
    kho[0].soluong = 10;
    kho[0].giathanh = 35000;
    kho[0].code = generateCode(kho[0].tenhang);
    
    
    strcpy(kho[1].tenhang, "Sua tam");
    kho[1].soluong = 20;
    kho[1].giathanh = 75000;
    kho[1].code = generateCode(kho[1].tenhang);
    
    strcpy(kho[2].tenhang, "Ban chai");
    kho[2].soluong = 100;
    kho[2].giathanh = 45000;
    kho[2].code = generateCode(kho[2].tenhang);
    
    strcpy(kho[3].tenhang, "Khau trang");
    kho[3].soluong = 2000;
    kho[3].giathanh = 100000;
    kho[3].code = generateCode(kho[3].tenhang);
    
    strcpy(kho[4].tenhang, "My pham");
    kho[4].soluong = 250;
    kho[4].giathanh = 500000;
    kho[4].code = generateCode(kho[4].tenhang);
    
    strcpy(kho[5].tenhang, "Dau goi dau");
    kho[5].soluong = 200;
    kho[5].giathanh = 180000;
    kho[5].code = generateCode(kho[5].tenhang);
    
    strcpy(kho[6].tenhang, "Kem chong nang");
    kho[6].soluong = 150;
    kho[6].giathanh = 250000;
    kho[6].code = generateCode(kho[6].tenhang);
    
    strcpy(kho[7].tenhang, "Sua rua mat");
    kho[7].soluong = 100;
    kho[7].giathanh = 180000;
    kho[7].code = generateCode(kho[7].tenhang);
    
    strcpy(kho[8].tenhang, "Sena");
    kho[8].soluong = 1000;
    kho[8].giathanh = 150000;
    kho[8].code = generateCode(kho[8].tenhang);
    
    strcpy(kho[9].tenhang, "Serum");
    kho[9].soluong = 20000;
    kho[9].giathanh = 100000;
    kho[9].code = generateCode(kho[9].tenhang);
    
}

int somathang(){
    int cnt = 0;
    for(int i = 0; i < 100; i++){
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
void hienthikho(int n){ //Hàm hi?n th? kho hàng v?i các m?t hàng s?n có
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
void xuatkho() {
    taokho();
    string code;
    cout << "Nhap ma san pham: ";
    cin >> code;

    bool found = false;
    for (int i = 0; i < somathang(); i++) {
        if (kho[i].code == code) {
            found = true;
            if (i > 0 && kho[i].code == kho[i - 1].code) {
                continue;
            }

            if (i < somathang() - 1 && kho[i].code == kho[i + 1].code) {
                cout << "Co nhieu mat hang cung ma code, vui long nhap day du ten mat hang: ";
                string Name;
                cin.ignore();
                getline(cin, Name);
                
                
                bool checkname = false;
                for (int j = i; j < somathang(); j++) {
                    if (strcmp(kho[j].tenhang, Name.c_str()) == 0 && kho[j].code == code) {
                        checkname = true;
                        cout<<"Ten hang: "<<kho[j].tenhang<<endl<<"So Luong: "<<kho[j].soluong<<endl<<"Gia: "<<kho[j].giathanh<<endl;
                        cout << "Nhap so luong can xuat: ";
                        int quantity;
                        cin >> quantity;
                        
                        
                        if (quantity > 0 && quantity <= kho[j].soluong) {
                            kho[j].soluong -= quantity;
                            cout << "Da xuat " << quantity << " san pham." << endl;
                        } else {
                            cout << "So luong nhap vao khong hop le hoac khong du so luong trong kho." << endl;
                        }
                        break; 
                    }
                }
                if (!checkname) {
                    cout << "Khong tim thay mat hang voi ten da nhap." << endl;
                }
            } else {
               
                cout << "Ten hang: " << kho[i].tenhang << endl;
                cout << "So luong: " << kho[i].soluong << endl;
                cout << "Gia thanh: " << kho[i].giathanh << endl;

                int quantity;
                cout << "Nhap so luong can xuat: ";
                cin >> quantity;

            
                if (quantity > 0 && quantity <= kho[i].soluong) {
                    kho[i].soluong -= quantity;
                    cout << "Da xuat " << quantity << " san pham." << endl;
                } else {
                    cout << "So luong nhap vao khong hop le hoac khong du so luong trong kho." << endl;
                }
            }
        }
    }

    if (!found) {
        cout << "Khong tim thay san pham voi ma nay." << endl;
    }

    cout << "CAP NHAT KHO HANG HIEN TAI" << endl;
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
        printf("NHAP THONG TIN MAT HANG SO %d:\n", somathang() );
        nhap2(kho, somathang() );
    }
    cout << "CAP NHAT KHO HANG HIEN TAI"<<endl;
    hienthikho(somathang() );
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
void check1() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].giathanh < kho[j].giathanh) {
                swap(kho[i], kho[j]);
            }
        }
    }
    cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO GIA GIAM DAN:" << endl;
    hienthikho(somathang());
}
void check2() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].giathanh > kho[j].giathanh) {
                swap(kho[i], kho[j]);
            }
        }
    }
    cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO GIA TANG DAN:" << endl;
    hienthikho(somathang());
}
void check3() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].soluong < kho[j].soluong) {
                swap(kho[i], kho[j]);
            }
        }
    }
    cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO SO LUONG GIAM DAN:" << endl;
    hienthikho(somathang());
}
void check4() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].soluong > kho[j].soluong) {
                swap(kho[i], kho[j]);
            }
        }
    }
    cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO SO LUONG TANG DAN:" << endl;
    hienthikho(somathang());
}
void laythongtinsanpham(const string& code) {
    bool found = false;
    for (int i = 0; i < somathang(); i++) {
        if (kho[i].code == code) {
            found = true;
            cout << "Ten hang: " << kho[i].tenhang << endl;
            cout << "So luong: " << kho[i].soluong << endl;
            cout << "Gia thanh: " << kho[i].giathanh << endl;
            
        }
    }
    if (!found) {
        cout << "Khong tim thay san pham voi ma nay." << endl;
    }
}
ofstream logFile; // Ð?i tu?ng d? ghi file log

void logActivity(const string& activity) {
    logFile.open("nghich.txt", ios::app); // M? file log d? ghi thêm n?i dung

    if (!logFile.is_open()) {
        cerr << "Khong the mo file log." << endl;
        return;
    }

    logFile << activity << endl; // Ghi ho?t d?ng vào file log
    logFile.close(); // Ðóng file log sau khi ghi
}

int main() {
    logFile.open("nghich.txt", ios::app); // M? file log d? ghi thêm n?i dung

    if (!logFile.is_open()) {
        cerr << "Khong the mo file log." << endl;
        return 1;
    }

    while (true) {
        cout << MAGENTA << "______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______" << endl;
        cout << "|  1.XEM THONG TIN MAT HANG TON KHO                  |" << endl;
        cout << "|  2.XUAT KHO                                        |" << endl;
        cout << "|  3.NHAP HANG VAO KHO                               |" << endl;
        cout << "|  4.SAP XEP                                         |" << endl;
        cout << "|  5.KIEM TRA HANG THEO MA SAN PHAM                  |" << endl;
        cout << "|  6.EXIT THE SYSTEM.                                |" << endl;
        cout << "!____________________________________________________!" << endl;
        cout << "SELECT OPTION: " << RESET;
        int lc;
        cin >> lc;
         if (cin.fail()) {
            cerr << "L?i khi nh?p l?a ch?n. Vui lòng nh?p l?i." << endl;
            cin.clear(); // Xóa tr?ng thái l?i c?a cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa b? d? li?u còn th?a trong b? d?m d?u vào
            continue; // Quay l?i vòng l?p d? yêu c?u nh?p l?i
        }
                cin.ignore(); // Xóa b? ký t? newline còn th?a trong b? d?m d?u vào

        if (lc == 1) {
            logActivity("Nguoi dung da chon xem thong tin mat hang ton kho.");
            taokho();
            hienthikho(somathang());
        } else if (lc == 2) {
            logActivity("Nguoi dung da chon xuat kho.");
            xuatkho();
        } else if (lc == 3) {
            logActivity("Nguoi dung da chon nhap hang vao kho.");
            nhapkho();
        } else if (lc == 4) {
            	cout << "Chon 1 de sap xep theo gia tien giam dan, chon 2 de sap xep theo gia tien tang dan, chon 3 de sap xep theo so luong giam dan, chon 4 de sap xep theo so luong tang dan"<< endl;
            int check ;
            cin >> check;
            if(check ==1){
			 check1();
            logActivity("Nguoi dung da sap xep theo gia tien giam dan");}
			else if (check == 2) {
			check2();
			logActivity("Nguoi dung da sap xep theo gia tien tang dan");}
			else if (check == 3) check3();
			else if (check == 4) check4();
    }
        else if (lc == 5) {
            logActivity("Nguoi dung da kiem tra hang theo ma san pham.");
            string code;
            cout << "Nhap ma san pham: ";
            cin >> code;
            laythongtinsanpham(code);
        } else if (lc == 6) {
            cout << "*************   HE THONG DA DONG   *************" << endl;
            break;
        }
    }
    logFile.close(); // Ðóng file log khi k?t thúc chuong trình

    return 0;
}
