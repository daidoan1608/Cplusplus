//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Một nhân sự nói chung có họ tên và ngày sinh. Nhân viên trong một công ty là một loại 
nhân sự nhưng có thêm mã nhân viên và hệ số lương. Cán bộ quản lý trong công ty là 
một loại nhân viên nhưng có thêm chức vụ và hệ số phụ cấp chức vụ. Nhập vào thông 
tin của n cán bộ quản lý trong công ty. Đưa ra thông tin của các cán bộ quản lý đã nhập. 
Tìm cán bộ quản lý có lương cao nhất. Lương của cán bộ quản lý được tính theo công 
thức: (hệ số lương + hệ số phụ cấp chức vụ) * 1800.  
*/
#include <iostream>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng
class NhanSu{
    private:
        char hoTen[30];
        char ngaySinh[11];
    public:
        void nhap();
        void xuat();

};
class NhanVien:public NhanSu{
    private:
        char maNV[10];
        float heSoLuong;
    public:
        void nhap();
        float getHeSoLuong();
        void xuat();
};
class CanBoQuanLy:public NhanVien{
    private:
        char chucVu[20];
        float heSoPhuCap;
    public:
        void nhap();
        void xuat();
        float luong();
};
//===Chương trình chính===
int main(){
    int n,index = 0;
    float max;
    cout << "Nhap so luong can bo quan ly: "; cin >> n;
    CanBoQuanLy *cbql = new CanBoQuanLy[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin can bo quan ly thu " << i+1 << ": " << endl;
        cbql[i].nhap();
    }
    cout << "Thong tin cua cac can bo quan ly: " << endl;
    max = cbql[0].luong();
    for (int i = 0; i < n; i++)
    {
        cout << "Can bo quan ly thu " << i+1 << ": " << endl;
        cbql[i].xuat();
        if(cbql[i].luong() > max){
            max = cbql[i].luong();
            index = i;
        }
    }
    cout << "Can bo quan ly co luong cao nhat la: " << endl;
    cbql[index].xuat();
    cout << endl;
    return 0;
}
//===Khai báo hàm===
void NhanSu::nhap(){
    cout << "Nhap ho ten: ";
    scanf(" ");
    cin.getline(hoTen, sizeof(hoTen));
    cout << "Nhap ngay sinh: ";
    cin.getline(ngaySinh, sizeof(ngaySinh));
}
void NhanVien::nhap(){
    NhanSu::nhap();
    cout << "Nhap ma nhan vien: ";
    cin.getline(maNV, sizeof(maNV));
    cout << "Nhap he so luong: ";
    cin >> heSoLuong;
}
void CanBoQuanLy::nhap(){
    NhanVien::nhap();
    cout << "Nhap chuc vu: ";
    scanf(" ");
    cin.getline(chucVu, sizeof(chucVu));
    cout << "Nhap he so phu cap: ";
    cin >> heSoPhuCap;
}
void NhanSu::xuat(){
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
}
void NhanVien::xuat(){
    NhanSu::xuat();
    cout << "Ma nhan vien: " << maNV << endl;
    cout << "He so luong: " << heSoLuong << endl;
}
void CanBoQuanLy::xuat(){
    NhanVien::xuat();
    cout << "Chuc vu: " << chucVu << endl;
    cout << "He so phu cap: " << heSoPhuCap << endl;
}
float NhanVien::getHeSoLuong(){
    return heSoLuong;
}
float CanBoQuanLy::luong(){
    return (NhanVien::getHeSoLuong() + heSoPhuCap)*1800;
}