//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Cho tệp văn bản “sinhvien-thi.txt” chứa danh sách n sinh viên, mỗi sinh viên có thông 
tin về mã sinh viên, tên (không có họ đệm), điểm kiểm tra, điểm thi. Điểm môn học 
được tính bằng 0,4 x Điểm kiểm tra + 0,6 x Điểm thi. Sắp xếp danh sách sinh viên theo 
điểm môn học giảm dần. Đưa ra màn hình danh sách sinh viên sau khi sắp xếp. Yêu cầu 
sử dụng toán tử so sánh > để so sánh hai sinh viên theo điểm môn học. 
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
        bool operator>(SinhVien &sv);
        //Hàm bạn
        friend ifstream& operator>> (ifstream &fin, SinhVien &sv);
        friend ostream& operator<< (ostream &cout, SinhVien &sv);
};
//===Chương trình chính===
int main(){
    int n;
    ifstream fin("sinhvien-thi.txt");
    fin >> n;
    SinhVien *sv = new SinhVien[n];
    for (int i = 0; i < n; i++)
        fin >> sv[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sv[j+1] > sv[j]) {

                SinhVien temp = sv[j];
                sv[j] = sv[j + 1];
                sv[j + 1] = temp;
            }
        }
    }
    cout << "Danh sach sinh vien theo thu tu giam dan cua diem mon hoc: " << endl;
    printf("%-8s %-10s %-5s %-5s\n","Ma SV","Ten","KT","Thi");
    for (int i = 0; i < n; i++)
    {
        cout << sv[i] << endl;
    }
    
    cout << endl;
    return 0;
}
//===Khai báo hàm===
float SinhVien::diemMonHoc(){
    return 0.4*diemKT + 0.6*diemThi;
}
bool SinhVien::operator>(SinhVien &sv){
    return diemMonHoc() > sv.diemMonHoc();
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