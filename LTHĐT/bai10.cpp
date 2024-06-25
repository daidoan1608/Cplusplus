//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Cho 3 điểm trong mặt phẳng: A(x1, y1), B(x2, y2) và C(x3, y3). Tính chu vi tam giác 
ABC. Yêu cầu: sử dụng toán tử nhập >> để nhập tọa độ từ bàn phím ở dạng x y; sử dụng 
toán tử xuất << để đưa tọa độ ra màn hình ở dạng (x, y); dùng toán tử trừ - để tính 
khoảng cách giữa 2 điểm; tọa độ các điểm được tự động khởi tạo bằng 0 và có thể khởi 
tạo bằng 2 giá trị cho trước.. 
*/
#include <iostream>
#include <math.h>
using namespace std;
//Khai báo lớp đối tượng ma trận
 class Diem{
    private:
        float x,y;
    public:
        Diem();
        Diem(float x,float y);
        float operator-(Diem &D2);
        //Ham ban
        friend istream& operator>>(istream &cin,Diem &D);
        friend ostream& operator<<(ostream &cout,Diem &D);
 };
//===Chương trình chính===
int main(){
    Diem A,B,C;
    cout << "Nhap toa do diem A: "; cin >> A;
    cout << "Nhap toa do diem B: "; cin >> B;
    cout << "Nhap toa do diem C: "; cin >> C;
    cout << "Toa do 3 diem vua nhap la: A" << A << ", B" << B << ", C" << C << endl;
    float kcAB = A-B;
    float kcBC = B-C;
    float kcCA = C-A;
    cout << "Chu vi tam giac ABC la: " << kcAB+kcBC+kcCA;
    cout << endl;
    return 0;
}
//===Khai báo hàm===
Diem::Diem():x(0),y(0){}
Diem::Diem(float x,float y):x(x),y(y){}
float Diem::operator-(Diem &D2){
    return sqrt((x-D2.x)*(x-D2.x)+(y-D2.y,2)*(y-D2.y,2));
}
istream& operator>>(istream &cin,Diem &D){
    cout << "\n\tNhap toa do x: "; cin >> D.x;
    cout << "\tNhap toa do y: "; cin >> D.y;
    return cin;
}
ostream& operator<<(ostream &cout,Diem &D){
    cout << "(" << D.x << "," << D.y << ")";
    return cout;
}