//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Nhập vào danh sách n tên tỉnh từ bàn phím. Sắp xếp danh sách tên tỉnh theo vần ABC. 
Yêu cầu sử dụng đối tượng xâu ký tự tự cài đặt để chứa tên tỉnh; sử dụng toán tử nhập 
>> để nhập vào xâu ký tự; sử dụng toán tử xuất << để đưa xâu ký tự ra màn hình; sử 
dụng toán tử < để so sánh xâu ký tự; xâu ký tự được tự động khởi tạo bằng xâu rỗng; sử 
dụng mảng động để chứa danh sách n tên tỉnh. 
*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
//Khai báo lớp đối tượng ma trận
class XauKyTu{
    private:
        char tenTinh[20];
    public:
        XauKyTu();
        bool operator<(const XauKyTu &xt);
        //Hàm bạn
        friend istream& operator>> (istream &cin, XauKyTu &xt);
        friend ostream& operator<< (ostream &cout, XauKyTu &xt);
};
//===Chương trình chính===
int main(){
    int n;
    cout << "Nhap so luong tinh: "; cin >> n;
    XauKyTu *xt = new XauKyTu[n];
    for (int i = 0; i < n; i++)
        cin >> xt[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (xt[j+1] < xt[j]) {
                XauKyTu temp = xt[j];
                xt[j] = xt[j + 1];
                xt[j + 1] = temp;
            }
        }
    }
    cout << "Danh sach tinh theo thu tu ABC: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << xt[i] << "\n";
    }
    
    cout << endl;
    return 0;
}
//===Khai báo hàm===
XauKyTu::XauKyTu(){
    strcpy(tenTinh,"");
}
bool XauKyTu::operator<(const XauKyTu &xt){
    return (strcmp(tenTinh,xt.tenTinh) < 0);
}
istream& operator>>(istream &cin, XauKyTu &xt){
    cout << "Nhap ten tinh: ";
    scanf(" ");
    cin.getline(xt.tenTinh,sizeof(xt.tenTinh));
    return cin;
}
ostream& operator<<(ostream &cout, XauKyTu &xt){
    cout << xt.tenTinh;
    return cout;
}