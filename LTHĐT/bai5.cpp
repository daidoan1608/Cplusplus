//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Cho tệp văn bản “matran.txt” chứa ma trận số thực Amxn. Đọc vào ma trận A từ tệp. 
Tính trung bình cộng các phần tử của ma trận A. Nhân ma trận A với một số thực x nhập 
vào từ bàn phím để được ma trận B (B = A*x). Đưa ma trận A và B ra màn hình theo 
định dạng hàng, cột. Yêu cầu sử dụng toán tử nhập >> để đọc vào ma trận từ tệp; sử 
dụng toán tử xuất << để đưa ma trận ra màn hình theo định dạng hàng, cột; sử dụng toán 
tử nhân * để nhân ma trận với một số; ma trận được tự động khởi tạo kích thước m, n 
bằng 0. 
*/
#include <iostream>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng ma trận
class MaTran{
    private:
		enum {size = 10};
		int a[size][size];
		int m,n;
    public:
        MaTran();
        MaTran operator*(int x);
        float trungBinh();
        //Hàm bạn
        friend ifstream& operator>> (ifstream &fin, MaTran &mt);
        friend ostream& operator<< (ostream &cout, MaTran &mt);
};
//===Chương trình chính===
int main(){
    MaTran mt;
    int x;
    ifstream fin("matran.txt");
    fin >> mt;
    cout << "Ma tran A:\n" << mt;
    cout << "Trung binh cong cac phan tu cua ma tran A: " << mt.trungBinh() << endl;
    cout << "Nhap so thuc x: "; cin >> x;
    MaTran mt2 = mt*x;
    cout << "Ma tran B = A*x:\n" << mt2;
    cout << endl;
    return 0;
}
//===Khai báo hàm===
MaTran::MaTran():m(0), n(0){}
MaTran MaTran::operator*(int x){
    MaTran temp;
    temp.m = m;
    temp.n = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.a[i][j] = a[i][j]*x;
        }
    }
    return temp;
}
float MaTran::trungBinh(){
    float sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            sum += a[i][j];
    return sum/(m*n);
}
ifstream& operator>>(ifstream &fin, MaTran &mt){
    fin >> mt.m >> mt.n;
    for (int i = 0; i < mt.m; i++)
        for (int j = 0; j < mt.n; j++)
            fin >> mt.a[i][j];
    return fin;
}
ostream& operator<<(ostream &cout, MaTran &mt){
    for (int i = 0; i < mt.m; i++)
    {
        for (int j = 0; j < mt.n; j++)
            printf("%5d", mt.a[i][j]);
        cout << endl;
    }
    return cout;
}