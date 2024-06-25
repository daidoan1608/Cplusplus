//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Cho tệp văn bản “diemmonhoc.txt” chứa danh sách điểm môn học của n sinh viên, mỗi 
sinh viên có thông tin về mã sinh viên, tên (không có họ đệm), điểm kiểm tra, điểm thi. 
Điểm môn học được tính bằng 0,3 x Điểm kiểm tra + 0,7 x Điểm thi. Đếm số lượng và 
đưa ra màn hình danh sách các sinh viên chưa đạt (có điểm môn học < 4). Yêu cầu sử 
dụng toán tử nhập >> và toán tử xuất << để nhập vào và đưa ra thông tin của từng sinh 
viên.  
*/
#include <iostream>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng ma trận
class SinhVien{
    private:
        char maSV[8];
        char ten[10];
        float diemKT;
        float diemThi;
    public:
        float diemMonHoc();
        //Hàm bạn
        friend ifstream& operator>> (ifstream &fin, SinhVien &sv);
        friend ostream& operator<< (ostream &cout, SinhVien &sv);
};
//===Chương trình chính===
int main(){
    int n,dem = 0;
    ifstream fin("diemmonhoc.txt");
    fin >> n;
    SinhVien *sv = new SinhVien[n];
    for (int i = 0; i < n; i++)
    {
        fin >> sv[i];
        if (sv[i].diemMonHoc() < 4)
            dem++;
    }
    cout << "So luong sinh vien chua dat mon hoc la: " << dem << endl;
    cout << "Danh sach sinh vien chua dat mon hoc: " << endl;
    printf("%-8s %-10s %-5s %-5s\n","Ma SV","Ten","KT","Thi");
    for (int i = 0; i < n; i++)
    {
        if (sv[i].diemMonHoc() < 4)
        {
            cout << sv[i] << endl;
        }
    }
    cout << endl;
    return 0;
}
//===Khai báo hàm===
float SinhVien::diemMonHoc(){
    return 0.3*diemKT + 0.7*diemThi;
}
ifstream& operator>>(ifstream &fin, SinhVien &sv){
    fin.ignore();
    fin >> sv.maSV;
    fin.ignore(); // Bỏ qua ký tự tab hoặc khoảng trắng
    fin >> sv.ten;
    fin.ignore(); // Bỏ qua ký tự tab hoặc khoảng trắng
    fin >> sv.diemKT;
    fin >> sv.diemThi;
    return fin;
}
ostream& operator<<(ostream &cout, SinhVien &sv){
    printf("%-8s %-10s %-5.1f %-5.1f",sv.maSV,sv.ten,sv.diemKT,sv.diemThi);
    return cout;
}