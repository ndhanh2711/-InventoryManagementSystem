#include <iostream>
#include <ctime>
using namespace std;
void time(){
    time_t now = time(0);
 tm *ltm = localtime(&now);
 cout << "Ngày: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " Lúc: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << endl;
}
int main( )
{
 time();
}