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
struct mathang{
    char tenhang[100];
    int soluong;
    double giathanh;
    char codeitem;
    std::string code;
};
typedef struct mathang mathang;
std::vector<mathang> kho(100);

std::string generateCode(const std::string& name) { // hàm lấy code từ tên sản phẩm
    std::string code = "";
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
void logOperation(const std::string& operation) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << operation << std::endl;
    }
    logFile.close();
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
    std::ostringstream oss;
    oss << GREEN << "Nhap    Mat hang: " << kho[n].tenhang << " So luong: " << kho[n].soluong << " Gia tien: " << kho[n].giathanh << RESET;
    logOperation(oss.str());
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
int somathang(){
    // tính số mặt hàng trong kho
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
    std::cout << "$_____$______$_______________________$________________$___________________$"<< std::endl;
    std::cout << "| STT |" << " CODE |" << "    THE PRODUCT NAME   |" << "  THE QUANTITY  |" << "   COST/1item($)   |"<<std::endl;
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
        int ma = kho[i].code.length();
        std::cout << " " << kho[i].code << std::setw(6 - ma) << "|";
        int a = strlen(kho[i].tenhang);
        std::cout << kho[i].tenhang << std::setw(24 - a) << "|";
        int b = cnt(kho[i].soluong);
        std::cout << kho[i].soluong << std::setw(18 - b) << "|";
        int c = cnt(kho[i].giathanh);
        std::cout << std::fixed << kho[i].giathanh << " " << std::setw(13 - c) << "|"<<std::endl;
    }
    std::cout << "$-----$------$-----------------------$----------------$-------------------$\n" << std::endl;
    std::cout << RESET;
    std::cout << YELLOW << "Tong so tien hang co trong kho bay gio la: " << costofwh() << RESET << std::endl << std::endl;
    for(int i = 0; i < n; i++){
        if(kho[i].soluong < 20 && strlen(kho[i].tenhang) != 0){
            std::cout << RED << "INFORM: Mat hang ' " << kho[i].tenhang << " ' trong kho qua it de duy tri nhu cau\n" << std::endl << RESET;
        }
    }
}
void xuatkho() {
    taokho();
    std::string code;
    int n;
    std::cout << "Nhap so luong mat hang can xuat kho: ";
    std::cin >> n;
    std::cin.ignore(); 

    for (int i = 0; i < n; i++) {
        std::cout << "Nhap ma san pham " << i+1 <<":";
        std::cin >> code;
        std::cin.ignore(); 

        bool found = false;
        for (int j = 0; j < somathang(); j++) {
            if (kho[j].code == code) {
                found = true;
                bool checkname = false;

                if (j > 0 && kho[j].code == kho[j - 1].code) {
                    continue;
                }

                if (j < somathang() - 1 && kho[j].code == kho[j + 1].code) {
                    std::cout << "Co nhieu mat hang cung ma code, vui long nhap day du ten mat hang: ";
                    std::string Name;
                    getline(std::cin, Name);

                    for (int k = j; k < somathang(); k++) {
                        if (kho[k].tenhang == Name && kho[k].code == code) {
                            checkname = true;
                            std::cout << "Ten hang: " << kho[k].tenhang << std::endl;
                            std::cout << "So Luong: " << kho[k].soluong << std::endl;
                            std::cout << "Gia: " << kho[k].giathanh << std::endl;

                            int quantity;
                            do {
                                std::cout << "Nhap so luong can xuat: ";
                                std::cin >> quantity;
                                std::cin.ignore();

                                if (quantity > 0 && quantity <= kho[k].soluong) {
                                    kho[k].soluong -= quantity;
                                    std::cout << "Da xuat " << quantity << " san pham." << std::endl;
                                    break; 
                                } else {
                                    std::cout << "So luong nhap vao khong hop le hoac khong du so luong trong kho. Vui long nhap lai." << std::endl;
                                }
                            } while (true);
                            break; 
                        }
                    }
                    if (!checkname) {
                        std::cout << "Khong tim thay mat hang voi ten da nhap." << std::endl;
                    }
                } else {
                    std::cout << "Ten hang: " << kho[j].tenhang << std::endl;
                    std::cout << "So luong: " << kho[j].soluong << std::endl;
                    std::cout << "Gia thanh: " << kho[j].giathanh << std::endl;

                    int quantity;
                    do {
                        std::cout << "Nhap so luong can xuat: ";
                        std::cin >> quantity;
                        std::cin.ignore(); 

                        if (quantity > 0 && quantity <= kho[j].soluong) {
                            kho[j].soluong -= quantity;
                            std::cout << "Da xuat " << quantity << " san pham." << std::endl;
                            break; 
                        } else {
                            std::cout << "So luong nhap vao khong hop le hoac khong du so luong trong kho. Vui long nhap lai." << std::endl;
                        }
                    } while (true);
                }
            }
            
        }
        if (!found) {
            std::cout << "Khong tim thay san pham voi ma nay. Vui long nhap lai." << std::endl;
            i--; 
        }
    }
    std::cout << "CAP NHAT KHO HANG HIEN TAI" << std::endl;
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
 std::cout << "Ngày: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " Lúc: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << std::endl;
}

void deletefile() {
    std::ofstream logFile("log.txt", std::ios::trunc);
    logFile.close();
}
void timee(std::string& timeStr) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::stringstream ss;
    ss  << "Ngày: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year
       << " Lúc: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec ;

    timeStr = ss.str();
    
}
void clearLogFile() {
    std::ofstream logFile("log.txt", std::ios::trunc);
    logFile.close();
}
void showlog(){
    std::ifstream logFile("log.txt");
    if (logFile.is_open()) {
        std::string line;
        while (getline(logFile, line)) {
            std::cout << line << std::endl;
        }
        logFile.close();
    } else {
        std::cerr << "Unable to open log file." << std::endl;
    }
}
void check1() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].giathanh < kho[j].giathanh) {
                std::swap(kho[i], kho[j]);
            }
        }
    }
    std::cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO GIA GIAM DAN:" << std::endl;
    hienthikho(somathang());
}
void check2() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].giathanh > kho[j].giathanh) {
                std::swap(kho[i], kho[j]);
            }
        }
    }
    std::cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO GIA TANG DAN:" << std::endl;
    hienthikho(somathang());
}
void check3() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].soluong < kho[j].soluong) {
                std::swap(kho[i], kho[j]);
            }
        }
    }
    std::cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO SO LUONG GIAM DAN:" << std::endl;
    hienthikho(somathang());
}
void check4() {
	taokho();
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (kho[i].soluong > kho[j].soluong) {
                std::swap(kho[i], kho[j]);
            }
        }
    }
    std::cout << "DANH SACH SAN PHAM SAU KHI SAP XEP THEO SO LUONG TANG DAN:" << std::endl;
    hienthikho(somathang());
}
void laythongtinsanpham(const std::string& code) {
    bool found = false;
    for (int i = 0; i < somathang(); i++) {
        if (kho[i].code == code) {
            found = true;
            std::cout << GREEN << "Ten hang: " << kho[i].tenhang << std::endl;
            std::cout << "So luong: " << kho[i].soluong << std::endl;
            std::cout << "Gia thanh: " << kho[i].giathanh << RESET << std::endl;
        }
    }
    if (!found) {
        std::cout << "Khong tim thay san pham voi ma nay." << std::endl;
    }
}
int main() {
    while(1){
        std::cout << MAGENTA << "______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______" << std::endl;
        std::cout << "|  1.XEM THONG TIN MAT HANG TON KHO                  |" << std::endl;
        std::cout << "|  2.XUAT KHO                                        |" << std::endl;
        std::cout << "|  3.NHAP HANG VAO KHO                               |" << std::endl;
        std::cout << "|  4.SAP XEP                                         |" << std::endl;
        std::cout << "|  5.KIEM TRA HANG THEO MA SAN PHAM                  |" << std::endl;
        std::cout << "|  6.XEM LICH SU XUAT NHAP HANG                      |" << std::endl;
        std::cout << "|  0.THOAT HE THONG                                  |" << std::endl;
        std::cout << "!____________________________________________________!" << std::endl;
        std::cout << "SELECT OPTION: " << RESET;
        int lc;
        std::cin >> lc;
        if(lc == 1){
            taokho();
            hienthikho(somathang());
            //FINISHED
        }
        else if(lc == 2){
            std::cout << YELLOW;
            std::string timeMsg;
            timee(timeMsg);
            std::cout << RESET;
            logOperation(timeMsg);
            //FINISHED
            xuatkho();
        }
        else if(lc == 3){
            std::cout << YELLOW;
            std::string timeMsg;
            timee(timeMsg);
            logOperation(timeMsg);
            std::cout << RESET;
            nhapkho();
        }
        else if(lc == 4){
            while(1){
                std::cout << "________LUA CHON CACH SAP XEP_________" << std::endl;
                std::cout << "|  1.SAP XEP THEO GIA TIEN GIAM DAN  |" << std::endl;
                std::cout << "|  2.SAP XEP THEO GIA TIEN TANG DAN  |" << std::endl;
                std::cout << "|  3.SAP XEP THEO SO LUONG GIAM DAN  |" << std::endl;
                std::cout << "|  4.SAP XEP THEO SO LUONG TANG DAN  |" << std::endl;
                std::cout << "|  5.THOAT                           |" << std::endl;
                std::cout << "!____________________________________!" << std::endl;
                std::cout << "SELECT OPTION: ";
                    int check ;
                    std::cin >> check;
                    if(check ==1){
                        check1();
                        continue;
                    }
                    else if (check == 2){
                        check2();
                        continue;
                    }
                    else if (check == 3) {
                        check3();
                        continue;
                    }
                    else if (check == 4) {
                        check4();
                        continue;
                    }
                    else if (check == 5){
                        std::cout<< "MOI BAN CHON CAC CHUC NANG KHAC"<<std::endl;
                    }
                }   
        }
        else if (lc == 5) {
            taokho();
            std::string code;
            std::cout << "Nhap ma san pham: ";
            std::cin >> code;
            laythongtinsanpham(code);
        }
        else if(lc == 6){
            std::cout << CYAN << "\n\nLich su nhap & xuat hang trong ngay hom nay" << std::endl;
            showlog();
            std::cout << "\n\n";
        }
        else if(lc == 0){
            deletefile();
            //FINISHED
                std::cout << RED << "------------------EEEEE  N   N  DDDD------------------\n";
                std::cout << "------------------E      NN  N  D   D-----------------\n";
                std::cout << "------------------EEEE   N N N  D   D-----------------\n";
                std::cout << "------------------E      N  NN  D   D-----------------\n";
                std::cout << "------------------EEEEE  N   N  DDDD------------------\n" << RESET;
            return 0;
        }
    }
    return 0;
}
