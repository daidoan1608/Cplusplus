//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Tính hiệu hai phân số nhập vào từ bàn phím. Đưa các phân số ra màn hình ở dạng rút 
gọn và chưa rút gọn. Yêu cầu sử dụng toán tử nhập >> để nhập vào phân số từ bàn phím 
ở dạng a/b; sử dụng toán tử xuất << để đưa phân số ra màn hình ở dạng a/b; sử dụng 
toán tử - để trừ hai phân số; phân số được tự động khởi tạo tử số bằng 0 và mẫu số bằng 
1 hoặc được khởi tạo tử số và mẫu số bằng giá trị cho trước.  
*/
#include <iostream>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng ma trận
class PhanSo{
    private:
        int tu;
        int mau;
    public:
        PhanSo();
        PhanSo(int t, int m);
        PhanSo operator-(PhanSo &ps2);
        void rutGon();
        //Hàm bạn
        friend istream& operator>> (istream &cin, PhanSo &ps);
        friend ostream& operator<< (ostream &cout, PhanSo &ps);
};
//===Chương trình chính===
int main(){
    PhanSo ps1, ps2, hieu;
    cout << "Nhap phan so 1(a/b): "; cin >> ps1;
    cout << "Nhap phan so 2(a/b): "; cin >> ps2;
    hieu = ps1 - ps2;
    cout << "Phan so 1:\n\tChua rut gon: " << ps1;
    ps1.rutGon();
    cout << "\n\tRut gon: " << ps1 <<endl;
    cout << "Phan so 2:\n\tChua rut gon: " << ps2;
    ps2.rutGon();
    cout<< "\n\tRut gon: " << ps2 <<endl;
    cout << "Hieu cua hai phan so tren la: " << hieu << endl;
    hieu.rutGon();
    cout << "Hieu cua hai phan so tren sau khi rut gon la: " << hieu << endl;
    return 0;
}
//===Khai báo hàm===
PhanSo::PhanSo():tu(0), mau(1){}
PhanSo::PhanSo(int t, int m):tu(t), mau(m){}
PhanSo PhanSo::operator-(PhanSo &ps2){
    PhanSo temp;
    temp.tu = tu*ps2.mau - ps2.tu*mau;
    temp.mau = mau*ps2.mau;
    return temp;
}
void PhanSo::rutGon(){
    int a = tu;
    int b = mau;
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    tu /= a;
    mau /= a;
}
istream& operator>>(istream &cin, PhanSo &ps){
    char c;
    cin >> ps.tu >> c >> ps.mau;
    return cin;
}
ostream& operator<<(ostream &cout, PhanSo &ps){
    cout << ps.tu << "/" << ps.mau;
    return cout;
}