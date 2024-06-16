#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
                #define RESET   "\033[0m"
                #define RED     "\033[31m"
                #define GREEN   "\033[32m"
                #define YELLOW  "\033[33m"
                #define BLUE    "\033[34m"
                #define MAGENTA "\033[35m"
                #define CYAN    "\033[36m"
using namespace std; //để tạm đỡ phải gõ std::, sau nhớ xoá đi
struct mathang{
    char tenhang[100];
    int soluong;
    double giathanh;
    char codeitem;
    string code;
};
typedef struct mathang mathang;
std::vector<mathang> kho(100);

string generateCode(const string& name) { // hàm lấy code từ tên sản phẩm
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
void nhap2(std::vector<mathang>& kho, int n) {
    std::cin.ignore();
    std::cout << "Name: ";
    std::cin.getline(kho[n].tenhang, 100);
    std::cout << "Sl: ";
    std::cin >> kho[n].soluong;
    std::cin.ignore();
    std::cout << "Cost/item: ";
    std::cin >> kho[n].giathanh;
    kho[n].code = generateCode(kho[n].tenhang);
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

    strcpy(kho[8].tenhang, "Xa phong");
    kho[8].soluong = 1000;
    kho[8].giathanh = 150000;
    kho[8].code = generateCode(kho[8].tenhang);

    strcpy(kho[9].tenhang, "Serum");
    kho[9].soluong = 20000;
    kho[9].giathanh = 100000;
    kho[9].code = generateCode(kho[9].tenhang);
}

int somathang(){// tính số mặt hàng trong kho
    int cnt = 0;
    for(int i = 0; i < 100; i++){
        if(strlen(kho[i].tenhang) != 0){
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
    std::cout << CYAN;
    std::cout << "$_____$_______________________$________________$___________________$"<< std::endl;
    std::cout << "| STT |" <<"    THE PRODUCT NAME   |" << "  THE QUANTITY  |" << "   COST/1item($)   |"<<std::endl;
    for(int i = 0; i < n; i++){
        if(strlen(kho[i].tenhang) == 0) continue; // Chỉ hiển thị mặt hàng có tên
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
        std::cout << kho[i].tenhang << std::setw(24 - a) << "|";
        int b = cnt(kho[i].soluong);
        std::cout << kho[i].soluong << std::setw(18 - b) << "|";
        int c = cnt(kho[i].giathanh);
        std::cout << std::fixed << kho[i].giathanh << " " << std::setw(13 - c) << "|"<<std::endl;
    }
    std::cout << "$-----$-----------------------$----------------$-------------------$\n" << std::endl;
    std::cout << RESET;
    std::cout << YELLOW << "Tong so tien hang co trong kho bay gio la:" << costofwh() << RESET << std::endl;
    for(int i = 0; i < n; i++){
        if(kho[i].soluong < 20 && strlen(kho[i].tenhang) != 0){
            std::cout << RED << "INFORM: Mat hang " << kho[i].tenhang << " trong kho qua it de duy tri nhu cau" << std::endl << RESET;
        }
    }
}
void logOperation(const std::string& operation) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << operation << std::endl;
    }
    logFile.close();
}
void xuatkho() {// hàm xuất kho bằng code
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
    std::cout << "So mat hang co trong kho la: ";
    std::cout << somathang() << std::endl;
    std::cout << "SO LUONG MAT HANG MUON THEM VAO KHO: ";
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        printf("NHAP THONG TIN MAT HANG SO %d:\n", somathang());
        nhap2(kho, somathang());
    }
    std::cout << "CAP NHAT KHO HANG HIEN TAI"<<std::endl;
    hienthikho(somathang());
}

void baomat(){
    std::cout << RED;
    std::string a = "alester";
    std::string b = "top1thaibinh";
    std::cout << "LOG IN(Use the English keyboard to type.)"<<std::endl;
    while(1){
        std::cout << "User name:";
        std::string tk;
        std::cin >> tk;
        if(a.compare(tk) != 0){
            std::cout << "Wrong account, please enter again." << std::endl;
            continue;
        }
        else{
            std::cout << "Password:";
            std::string mk;
            std::cin >> mk;
            if(mk.compare(b) != 0){
                std::cout << "Wrong password, please re-enter." << std::endl;
                continue;
            }
            else{
                break;
            }
        }
    }
    std::cout << RESET;
}
void timee(){
    time_t now = time(0);
 tm *ltm = localtime(&now);
 cout << "Ngày: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " Lúc: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << endl;
}




void deletefile() {
    std::ofstream logFile("log.txt", std::ios::trunc);
    logFile.close();
}
void timee(std::string& timeStr) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::stringstream ss;
    ss << "Ngày: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year
       << " Lúc: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec;

    timeStr = ss.str();
    
}
void clearLogFile() {
    std::ofstream logFile("log.txt", std::ios::trunc);
    logFile.close();
}
void log(){

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
int main() {
    while(1){
        std::cout << MAGENTA << "______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______" << std::endl;
        std::cout << "|  1.XEM THONG TIN MAT HANG TON KHO                  |" << std::endl;
        std::cout << "|  2.XUAT KHO                                        |" << std::endl;
        std::cout << "|  3.NHAP HANG VAO KHO                               |" << std::endl;
        std::cout << "|  4.SAP XEP                                         |" << std::endl;
        std::cout << "|  5.KIEM TRA HANG THEO MA SAN PHAM                  |" << endl;
        std::cout << "|  0.THOAT HE THONG                                  |" << std::endl;
        std::cout << "|  10.XEM LOG                                        |" << std::endl;
        std::cout << "!____________________________________________________!" << std::endl;
        std::cout << "SELECT OPTION: " << RESET;
        int lc;
        std::cin >> lc;
        if(lc == 1){
            taokho();
            hienthikho(10);
            //FINISHED
        }
        else if(lc == 2){
            std::string timeMsg;
            timee(timeMsg);
            logOperation(timeMsg);
            //FINISHED
            xuatkho();
        }
        else if(lc == 3){
            nhapkho();
        }
        else if(lc == 4){
        cout << "Chon 1 de sap xep theo gia tien giam dan, chon 2 de sap xep theo gia tien tang dan, chon 3 de sap xep theo so luong giam dan, chon 4 de sap xep theo so luong tang dan"<< endl;
        cout << "________________LUA CHON CACH SAP XEP_________________" << endl;
        cout << "|  1.SAP XEP THEO GIA TIEN GIAM DAN                  |" << endl;
        cout << "|  2.SAP XEP THEO GIA TIEN TANG DAN                  |" << endl;
        cout << "|  3.SAP XEP THEO SO LUONG GIAM DAN                  |" << endl;
        cout << "|  4.SAP XEP THEO SO LUONG TANG DAN                  |" << endl;
        cout << "|  5.THOAT                                           |" << endl;
        cout << "!____________________________________________________!" << endl;
        cout << "SELECT OPTION: ";
			int check ;
            cin >> check;
            if(check ==1) check1();
			else if (check == 2) check2();
			else if (check == 3) check3();
			else if (check == 4) check4();
			else if (check == 5){
				cout<< "MOI BAN CHON CAC CHUC NANG KHAC"<<endl;
			}
    }   
        else if (lc == 5) {
            taokho();
            string code;
            cout << "Nhap ma san pham: ";
            cin >> code;
            laythongtinsanpham(code);
        }
        else if(lc == 10){
            log();
        }
        else if(lc == 0){
            deletefile();
            //FINISHED
            std::cout << "*************   HE THONG DA DONG   *************"<<std::endl;
            return 0;
        }
    }
    return 0;
}
