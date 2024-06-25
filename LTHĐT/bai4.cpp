//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Cho tệp văn bản “phanso1.txt” và “phanso2.txt”, mỗi tệp có một dòng chứa phân số ở 
dạng a/b. Tính tổng hai phân số đọc vào từ tệp. Đưa các phân số ra màn hình ở dạng rút 
gọn và chưa rút gọn. Yêu cầu sử dụng toán tử nhập >> để đọc vào phân số từ tệp; sử 
dụng toán tử xuất << để đưa phân số ra màn hình ở dạng a/b; sử dụng toán tử + để cộng 
hai phân số; phân số được tự động khởi tạo tử số bằng 0 và mẫu số bằng 1 hoặc được 
khởi tạo tử số và mẫu số bằng giá trị cho trước. 
*/
#include <iostream>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng phan so
class PhanSo{
    private:
        int tu;
        int mau;
    public:
        PhanSo();
        PhanSo(int t, int m);
        PhanSo operator+(PhanSo &ps2);
        void rutGon();
        //Hàm bạn
        friend ifstream& operator>> (ifstream &fin, PhanSo &ps);
        friend ostream& operator<< (ostream &cout, PhanSo &ps);
};
//===Chương trình chính===
int main(){
    PhanSo ps1, ps2, sum;
    ifstream fin1("phanso1.txt");
    ifstream fin2("phanso2.txt");
    fin1 >> ps1;
    fin2 >> ps2;
    cout << "Phan so 1:\n\tChua rut gon: " << ps1;
    ps1.rutGon();
    cout << "\n\tRut gon: " << ps1 <<endl;
    cout << "Phan so 2:\n\tChua rut gon: " << ps2;
    ps2.rutGon();
    cout<< "\n\tRut gon: " << ps2 <<endl;
    sum = ps1 + ps2;
    cout << "Tong cua hai phan so tren la: " << sum << endl;
    sum.rutGon();
    cout << "Tong cua hai phan so tren sau khi rut gon la: " << sum << endl;
    return 0;
}
//===Khai báo hàm===
PhanSo::PhanSo():tu(0), mau(1){}
PhanSo::PhanSo(int t, int m):tu(t), mau(m){}
PhanSo PhanSo::operator+(PhanSo &ps2){
    PhanSo temp;
    temp.tu = tu*ps2.mau + ps2.tu*mau;
    temp.mau = mau*ps2.mau;
    return temp;
}
void PhanSo::rutGon(){
    int a = tu;
    int b = mau;

	while(b != 0){
      int r = a % b;
      a = b;
      b = r;
   }
    tu /= a+b;
    mau /= a+b;
}
ifstream& operator>>(ifstream &fin, PhanSo &ps){
    char c;
    fin >> ps.tu >> c >> ps.mau;
    return fin;
}
ostream& operator<<(ostream &cout, PhanSo &ps){
    cout << ps.tu << "/" << ps.mau;
    return cout;
}
