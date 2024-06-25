#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop doi tuong hinh
class NhanSu
{
    protected:
        char hoten[30];
    public:
        virtual void nhap()=0;
        virtual void xuat()=0;
};

//Khai bao lop doi tuong hinh tam giac
class NhanVien:public NhanSu
{
	private:
        float heSoLuong;	
	public:
		void nhap();
		void xuat();
};

//Khai bao lop doi tuong hinh chu nhat
class CanBo:public NhanVien
{
	private:
		char chucVu[30];
	
	public:
		void nhap();
        void xuat();
};

int main()
{
    NhanSu *list;
}
void NhanVien::nhap(){
    cout << "Nhap ho ten: "; scanf(" "); cin.getline(hoten,sizeof(hoten));
    cout << "Nhap he so luong: "; cin >> heSoLuong;
}
void NhanVien::xuat(){
    cout << "Ho ten: " << hoten << endl;
    cout << "He so luong: " << heSoLuong << endl;
}
void CanBo::nhap(){
    NhanVien::nhap();
    cout << "Nhap chuc vu: "; scanf(" "); cin.getline(chucVu,sizeof(chucVu));
}
void CanBo::xuat(){
    NhanVien::xuat();
    cout << "Chuc vu: " << chucVu << endl;
}