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
#include <limits>
                #define RESET   "\033[0m"   //Chuyển đổi mã màu từ mã máy sang chữ
                #define RED     "\033[31m"
                #define GREEN   "\033[32m"
                #define YELLOW  "\033[33m"
                #define BLUE    "\033[34m"
                #define MAGENTA "\033[35m"
                #define CYAN    "\033[36m"
struct mathang{
//định nghĩa thông tin mặt hàng
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
void logOperation(const std::string& operation) {  //Hàm ghi thông tin vào file log.txt
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << operation << std::endl;
    }
    logFile.close();
}
void nhap2(std::vector<mathang>& kho, int n) {  //Hàm nhập thông tin vào kho
    std::cin.ignore();
    std::cout << "Name: ";
    std::cin.getline(kho[n].tenhang, 100);
    std::cout << "Sl: ";
    std::cin >> kho[n].soluong;
    std::cin.ignore();
    std::cout << "Cost/item: ";
    std::cin >> kho[n].giathanh;
    kho[n].code = generateCode(kho[n].tenhang);
    //3 dòng bên dưới để ghi thông tin nhập hàng vào file.txt
    std::ostringstream oss;
    oss << GREEN << "       NHAP    Mat hang: " << kho[n].tenhang << "      So luong: " << kho[n].soluong << "       Gia tien: " << kho[n].giathanh << RESET;
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
    //tính tổng số tiền hàng có trong kho
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
        //kiểm tra và thông báo các mặt hàng có dưới 20 sản phẩm
        if(kho[i].soluong < 20 && strlen(kho[i].tenhang) != 0){
            std::cout << RED << "INFORM: Mat hang ' " << kho[i].tenhang << " ' trong kho qua it de duy tri nhu cau\n" << std::endl << RESET;
        }
    }
}
class Mathang {
public:
    virtual void xuatHang(int quantity) = 0;
    virtual void nhapHang(int quantity) = 0;
    virtual void xoaHang() = 0;
    virtual void dieuChinhGia(double newPrice) = 0;
    virtual ~Mathang() = default;
};
class MatHang : public Mathang {
    mathang &mh;
public:
    MatHang(mathang &m) : mh(m) {}

    void xuatHang(int quantity) override {
            mh.soluong -= quantity;
            std::cout << "Da xuat " << quantity << " san pham dien tu: " << mh.tenhang << std::endl;
    }

    void nhapHang(int quantity) override {
        mh.soluong += quantity;
        std::cout << "Da nhap " << quantity << " san pham dien tu: " << mh.tenhang << std::endl;
    }

    void xoaHang() override {
        mh.soluong = 0;
        std::cout << "San pham dien tu da duoc xoa khoi kho: " << mh.tenhang << std::endl;
    }

    void dieuChinhGia(double newPrice) override {
        mh.giathanh = newPrice;
        std::cout << "Gia moi cho san pham dien tu la " << newPrice << " VND." << std::endl;
    }
};
void xuatkho() {
    std::string code;
    int n;    
    std::cout << CYAN << "Nhap so luong mat hang can xuat kho: "<< RESET;
    while (true) {
        std::string input;
        std::cin >> input;

        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            std::cout << "Dau vao  khong dung dinh dang. Vui long nhap lai.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            n = stoi(input);
            break; // Ð?u vào h?p l?
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << "Nhap ma san pham " << i+1 << ": " << RESET;
        std::cin >> code;
        std::cin.ignore(); // Xử lý newline character sau khi nhập mã sản phẩm

        bool found = false;
        for (int j = 0; j < somathang(); j++) {
            if (kho[j].code == code) {
                found = true;
                bool checkname = false;

                if (j > 0 && kho[j].code == kho[j - 1].code) {
                    continue;
                }

                if (j < somathang() - 1 && kho[j].code == kho[j + 1].code) {
                    std::cout << RED << "Co nhieu mat hang cung ma don hang, vui long nhap day du ten mat hang: " << RESET;
                    std::string Name;
                    getline(std::cin, Name);

                    for (int k = j; k < somathang(); k++) {
                        if (kho[k].tenhang == Name && kho[k].code == code) {
                            checkname = true;
                            std::cout << GREEN << "Ten hang: " << kho[k].tenhang << std::endl;
                            std::cout << "So Luong: " << kho[k].soluong << std::endl;
                            std::cout << "Gia: " << kho[k].giathanh << RESET << std::endl;

                            int quantity;
                            do {
                                std::cout << "Nhap so luong can xuat: ";
                                std::cin >> quantity;
                                std::cin.ignore();

                                if (quantity > 0 && quantity <= kho[k].soluong) {
                                    MatHang mh(kho[k]);
                                    mh.xuatHang(quantity);
                                    std::cout << "Da xuat " << quantity << " san pham." << std::endl;

                                    // Ghi log sau khi xuất hàng
                                    logOperation(std::string("Xuat Mat Hang: ") + kho[k].tenhang + " So luong: " + std::to_string(quantity));
                                    break;
                                } else {
                                    std::cout << RED << "So luong nhap vao khong hop le hoac khong du so luong trong kho, Vui long nhap lai:" << RESET << std::endl;
                                }
                            } while (true);
                            break;
                        }
                    }
                    if (!checkname) {
                        std::cout << RED << "Khong tim thay mat hang voi ten da nhap." << RESET << std::endl;
                    }
                } else {
                    std::cout << GREEN << "Ten hang: " << kho[j].tenhang << std::endl;
                    std::cout << "So luong: " << kho[j].soluong << std::endl;
                    std::cout << "Gia thanh: " << kho[j].giathanh << RESET << std::endl;

                    int quantity;
                    do {
                        std::cout << CYAN << "Nhap so luong can xuat: ";
                        std::cin >> quantity;
                        std::cin.ignore(); 

                        if (quantity > 0 && quantity <= kho[j].soluong) {
                            MatHang mh(kho[j]);
                            mh.xuatHang(quantity);
                            std::cout << RESET << MAGENTA << "Da xuat " << quantity << " san pham." << RESET << std::endl;

                            // Ghi log sau khi xuất hàng
                            logOperation(std::string("       XUAT      Mat Hang: ") + kho[j].tenhang + " So luong: " + std::to_string(quantity));
                            break;
                        } else {
                            std::cout << RED << "So luong nhap vao khong hop le hoac khong du so luong trong kho. Vui long nhap lai." << RESET << std::endl;
                        }
                    } while (true);
                }
            }
        }
        if (!found) {
            std::cout << RED << "Khong tim thay san pham voi ma nay. Vui long nhap lai." << RESET << std::endl;
            i--; // Để người dùng nhập lại cho mã sản phẩm không hợp lệ
        }
    }

    std::cout << YELLOW << "CAP NHAT KHO HANG HIEN TAI" << RESET << std::endl;
    hienthikho(somathang());
}
   
void nhapkho(){
    std::cout << "So mat hang co trong kho la: ";
    std::cout << somathang() << std::endl;
    std::cout << "SO LUONG MAT HANG MUON THEM VAO KHO: ";
    int n;
    std::string code;
    std::cin >> n;
    int check = 0;
    std::cout << "________________LUA CHON NHAP KHO_________________" << std::endl;
    std::cout << "|  1.NHAP HANG DA CO TRONG KHO                    |" << std::endl;
    std::cout << "|  2.NHAP HANG MOI CHUA CO TRONG KHO              |" << std::endl;
    std::cout << GREEN << "SELECT OPTION: " << RESET;
    std::cin>>check;
    if(check == 1){
    	for(int i=0;i<n;i++){
    	std::cout<< "Nhap ma san pham: ";
    	std::cin >> code;
        std::cin.ignore(); // X? lý newline character sau khi nh?p mã s?n ph?m

        bool found = false;
        for (int j = 0; j < somathang(); j++) {
            if (kho[j].code == code) {
                found = true;
                bool checkname = false;

                if (j > 0 && kho[j].code == kho[j - 1].code) {
                    continue;
                }

                if (j < somathang() - 1 && kho[j].code == kho[j + 1].code) {
                    std::cout << RED << "Co nhieu mat hang cung ma don hang, vui long nhap day du ten mat hang: " << RESET;
                    std::string Name;
                    getline(std::cin, Name);

                    for (int k = j; k < somathang(); k++) {
                        if (kho[k].tenhang == Name && kho[k].code == code) {
                            checkname = true;
                            std::cout << GREEN << "Ten hang: " << kho[k].tenhang << std::endl;
                            std::cout << "So Luong: " << kho[k].soluong << std::endl;
                            std::cout << "Gia: " << kho[k].giathanh << RESET << std::endl;
                            int quantity;
                            do {
                                std::cout << "Nhap so luong can them: ";
                                std::cin >> quantity;
                                std::cin.ignore();
                                MatHang mh(kho[k]);
                                mh.nhapHang(quantity);
                                std::cout << RESET << MAGENTA << "Da nhap " << quantity << " san pham." << RESET << std::endl;
                                break; 
                            } while (true);
                            break;
                        }
                    }
                    if (!checkname) {
                        std::cout << RED << "Khong tim thay mat hang voi ten da nhap." << RESET << std::endl;
                    }
                } else {
                    std::cout << GREEN << "Ten hang: " << kho[j].tenhang << std::endl;
                    std::cout << "So luong: " << kho[j].soluong << std::endl;
                    std::cout << "Gia thanh: " << kho[j].giathanh << RESET << std::endl;

                    int quantity;
                    do {
                        std::cout << CYAN << "Nhap so luong can xuat: ";
                        std::cin >> quantity;
                        std::cin.ignore();                         
                        MatHang mh(kho[j]);
                        mh.nhapHang(quantity);
                        std::cout << RESET << MAGENTA << "Da nhap " << quantity << " san pham." << RESET << std::endl;
                        break;                        
                    } while (true);
                    break;
                }
            }
        }
        if (!found) {
            std::cout << RED << "Khong tim thay san pham voi ma nay. Vui long nhap lai." << RESET << std::endl;
            i--; // Ð? ngu?i dùng nh?p l?i cho mã s?n ph?m không h?p l?
        }
    }

    std::cout << YELLOW << "CAP NHAT KHO HANG HIEN TAI" << RESET << std::endl;
    hienthikho(somathang());
}
	else if(check == 2){
    int check = 0;
    for(int i = 0; i < n; i++){
        printf("NHAP THONG TIN MAT HANG SO %d:\n", somathang());
        nhap2(kho, somathang());
    }
    std::cout << "CAP NHAT KHO HANG HIEN TAI"<<std::endl;
    hienthikho(somathang());
}
}    



void xoakho() {
    std::string code;
    int n;
    std::cout << "Nhap so luong mat hang xoa khoi kho: ";
    while (true) {
        std::string input;
        std::cin >> input;

        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }
        if (!isNumber) {
            std::cout << "Dau vao khong dung dinh dang. Vui long nhap lai.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            n = std::stoi(input);
            break;
        }
    }
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::cout << "Nhap ma san pham " << i + 1 << ": ";
        std::getline(std::cin, code);

        bool found = false;
        for (int j = 0; j < kho.size(); j++) {
            if (kho[j].code == code) {
                found = true;
                bool checkname = false;
                if (j < somathang() - 1 && kho[j].code == kho[j + 1].code) {
                    std::cout << RED << "Co nhieu mat hang cung ma don hang, vui long nhap day du ten mat hang: " << RESET;
                    std::string Name;
                    std::getline(std::cin, Name);

                    for (int k = j; k < somathang(); k++) {
                        if (kho[k].tenhang == Name && kho[k].code == code) {
                            checkname = true;
                            std::cout << GREEN << "Ten hang: " << kho[k].tenhang << std::endl;
                            std::cout << "So Luong: " << kho[k].soluong << std::endl;
                            std::cout << "Gia: " << kho[k].giathanh << RESET << std::endl;
                            MatHang mh(kho[j]);
                            mh.xoaHang();
                            kho.erase(kho.begin() + j);
                            break;
                        }
             }if (!checkname) {
                std::cout << RED << "Khong tim thay mat hang voi ten da nhap." << RESET << std::endl;
            }
        }else {
                    std::cout << GREEN << "Ten hang: " << kho[j].tenhang << std::endl;
                    std::cout << "So luong: " << kho[j].soluong << std::endl;
                    std::cout << "Gia thanh: " << kho[j].giathanh << RESET << std::endl;
                    std::cout << GREEN << "Da xoa san pham " << kho[j].tenhang << " khoi kho." << RESET << std::endl;
                    MatHang mh(kho[j]);
                    mh.xoaHang();
                    kho.erase(kho.begin() + j);
                    break;
                }
            }
        }
        if (!found) {
            std::cout << "Khong tim thay san pham voi ma nay. Vui long nhap lai.\n";
            i--;
        }
    }
    
    std::cout << "CAP NHAT KHO HANG HIEN TAI\n";
    hienthikho(somathang());
}
void dieuchinhgia() {
    int n;
    std::cout << CYAN << "Nhap so luong mat hang can dieu chinh gia: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i) {
        std::string code;
        std::cout << "Nhap ma san pham " << i + 1 << ": " << RESET;
        std::getline(std::cin, code);

        bool found = false;

        for (int j = 0; j < somathang(); ++j) {
            if (kho[j].code == code) {
                found = true;

                bool checkname = false;
                if (j < somathang() - 1 && kho[j].code == kho[j + 1].code) {
                    std::cout << RED << "Co nhieu mat hang cung ma don hang, nhap ten day du cua mat hang: " << RESET;
                    std::string Name;
                    std::getline(std::cin, Name);

                    for (int k = j; k < somathang(); ++k) {
                        if (kho[k].tenhang == Name && kho[k].code == code) {
                            checkname = true;
                            std::cout << GREEN << "Ten hang: " << kho[k].tenhang << std::endl;
                            std::cout << "So Luong: " << kho[k].soluong << std::endl;
                            std::cout << "Gia: " << kho[k].giathanh << RESET << std::endl;

                            std::cout << GREEN << "Nhap gia moi: ";
                            int newPrice;
                            std::cin >> newPrice;
                            std::cin.ignore();                       
                            MatHang mh(kho[k]);
                            mh.dieuChinhGia(newPrice);
                            std::cout << RESET << "Gia moi duoc cap nhat." << std::endl;
                            break;
                        }
                    }
                } else {
                    std::cout << GREEN << "Ten hang: " << kho[j].tenhang << std::endl;
                    std::cout << "So luong: " << kho[j].soluong << std::endl;
                    std::cout << "Gia thanh: " << kho[j].giathanh << RESET << std::endl;

                    std::cout << GREEN << "Nhap gia moi: ";
                    int newPrice;
                    std::cin >> newPrice;
                    std::cin.ignore();

                    MatHang mh(kho[j]);
                    mh.dieuChinhGia(newPrice);
                    std::cout << RESET << "Gia moi duoc cap nhat." << std::endl;
                }

                break; 
            }
        }
        if (!found) {
            std::cout << RED << "Khong tim thay san pham voi ma nay. Vui long nhap lai." << RESET << std::endl;
            --i; 
        }
    }
    std::cout << YELLOW << "CAP NHAT KHO HANG HIEN TAI" << RESET << std::endl;
    hienthikho(somathang());
}
void baomat(){
    //nhập thông tin tài khoản mật khẩu cho hệ thống bằng cách kiểm tra trùng chuỗi kí tự
    std::string a = "alester";
    std::string b = "top1thaibinh";
    std::cout << GREEN << "LOG IN(Use the English keyboard to type.)"<< RESET << std::endl;
    while(1){
        std::cout << GREEN << "User name:" << RESET;
        std::string tk;
        std::cin >> tk;
        if(a.compare(tk) != 0){
            std::cout << RED << "Wrong account, please enter again." << RESET << std::endl;
            continue;
        }
        else{
            std::cout << GREEN << "Password:" << RESET;
            std::string mk;
            std::cin >> mk;
            if(mk.compare(b) != 0){
                std::cout << RED << "Wrong password, please re-enter." << RESET << std::endl;
                continue;
            }
            else{
                break;
            }
        }
    }
}
void deletefile() {
    //hàm xoá thông tin trong file sau khi kết thúc chương trình
    std::ofstream logFile("log.txt", std::ios::trunc);
    logFile.close();
}
void timee(std::string& timeStr) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::stringstream ss;
    ss  << "Ngày: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year
       << "      Lúc: " <<  ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec ;
    timeStr = ss.str();
    
}
void clearLogFile() {
    //đóng file sau khi sử dụng
    std::ofstream logFile("log.txt", std::ios::trunc);
    logFile.close();
}
void showlog(){
    //hàm ghi file, hiển thị các nội dung có trong file để xem lịch sử xuất nhập hàng
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
template <typename Compare>
void sapxep(mathang kho[], Compare cmp) {
    for (int i = 0; i < somathang() - 1; i++) {
        for (int j = i + 1; j < somathang(); j++) {
            if (cmp(kho[i], kho[j])) {
                std::swap(kho[i], kho[j]);
            }
        }
    }
}

// Hàm check để sắp xếp và hiển thị danh sách sản phẩm
void check() {
    while (true) {
        std::cout << BLUE << "________LUA CHON CACH SAP XEP_________" << std::endl;
        std::cout << "|  1. SAP XEP THEO GIA TIEN GIAM DAN  |" << std::endl;
        std::cout << "|  2. SAP XEP THEO GIA TIEN TANG DAN  |" << std::endl;
        std::cout << "|  3. SAP XEP THEO SO LUONG GIAM DAN  |" << std::endl;
        std::cout << "|  4. SAP XEP THEO SO LUONG TANG DAN  |" << std::endl;
        std::cout << "|  5. THOAT                           |" << std::endl;
        std::cout << "!____________________________________!" << RESET << std::endl;
        std::cout << GREEN << "SELECT OPTION: " << RESET;
        int check;
        std::cin >> check;

        switch (check) {
            case 1:
                // Sắp xếp theo giá giảm dần
                std::cout << "DANH SÁCH SẢN PHẨM SAU KHI SẮP XẾP THEO GIÁ GIẢM DẦN:\n";
                sapxep(kho.data(), [](const mathang& a, const mathang& b) {
                    return a.giathanh < b.giathanh;
                });
                hienthikho(somathang());
                break;

            case 2:
                // Sắp xếp theo giá tăng dần
                std::cout << "DANH SÁCH SẢN PHẨM SAU KHI SẮP XẾP THEO GIÁ TĂNG DẦN:\n";
                sapxep(kho.data(), [](const mathang& a, const mathang& b) {
                    return a.giathanh > b.giathanh;
                });
                hienthikho(somathang());
                break;

            case 3:
                // Sắp xếp theo số lượng giảm dần
                std::cout << "DANH SÁCH SẢN PHẨM SAU KHI SẮP XẾP THEO SỐ LƯỢNG GIẢM DẦN:\n";
                sapxep(kho.data(), [](const mathang& a, const mathang& b) {
                    return a.soluong < b.soluong;
                });
                hienthikho(somathang());
                break;

            case 4:
                // Sắp xếp theo số lượng tăng dần
                std::cout << "DANH SÁCH SẢN PHẨM SAU KHI SẮP XẾP THEO SỐ LƯỢNG TĂNG DẦN:\n";
                sapxep(kho.data(), [](const mathang& a, const mathang& b) {
                    return a.soluong > b.soluong;
                });
                hienthikho(somathang());
                break;

            case 5:
                std::cout << YELLOW << "MOI BAN CHON CAC CHUC NANG KHAC" << RESET << std::endl;
                return; // Thoát khỏi hàm check

            default:
                std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }
}
void laythongtinsanpham(const std::string& code) {
    //check thông tin sản phẩm cần tìm bằng cách nhập mã
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
    deletefile(); //xoá thông tin còn dư trong file ghi lịch sử nếu còn bị tồn lại từ trước
            std::string timeMsg;
            timee(timeMsg);
            logOperation(timeMsg);
            logOperation("     Dang nhap vao he thong");
    taokho();
    while(1){
        std::cout << MAGENTA << "______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______" << std::endl;
        std::cout << "|  1.XEM THONG TIN MAT HANG TON KHO                  |" << std::endl;
        std::cout << "|  2.XUAT KHO                                        |" << std::endl;
        std::cout << "|  3.NHAP HANG VAO KHO                               |" << std::endl;
        std::cout << "|  4.SAP XEP                                         |" << std::endl;
        std::cout << "|  5.KIEM TRA HANG THEO MA SAN PHAM                  |" << std::endl;
        std::cout << "|  6.XEM LICH SU XUAT NHAP HANG                      |" << std::endl;
	std::cout << "|  7.XOA HANG TRONG KHO                              |" << std::endl;
        std::cout << "|  8.DIEU CHINH GIA CAC MAT HANG                     |" << std::endl;
        std::cout << "|  0.THOAT HE THONG                                  |" << std::endl;
        std::cout << "!____________________________________________________!" << std::endl;
        std::cout << "SELECT OPTION: " << RESET;
        int lc;
        while (true) {
        std::string input;
        std::cin >> input;

        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            std::cout << "Dau vao  khong dung dinh dang. Vui long nhap lai.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            lc = stoi(input);
            break; // Ð?u vào h?p l?
        }
    }
        if(lc == 1){
            hienthikho(somathang());
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
            std::string timeMsg;
            timee(timeMsg);
            logOperation(timeMsg);
            nhapkho();
        }
        else if(lc == 4){
            check();
        }
        else if (lc == 5) {
            std::string code;
            std::cout << "Nhap ma san pham: ";
            std::cin >> code;
            laythongtinsanpham(code);
        }
        else if(lc == 6){
            std::cout << CYAN << "\n\nLICH SU HOAT DONG CUA KHO HANG"  << RESET << RED << std::endl;
            showlog();
            std::cout << "\n\n" << RESET;
        }
	else if(lc==7){
        	xoakho();
	}
	else if(lc== 8){
		dieuchinhgia();
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
        else {
        std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
    }
    }
    return 0;
}
