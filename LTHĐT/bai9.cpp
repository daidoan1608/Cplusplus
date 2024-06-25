//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Tính hiệu 2 ma trận nguyên: Cmxn = Amxn - Bmxn. Ma trận Amxn để trong tệp văn 
bản “matran-A.txt”, ma trận Bmxn để trong tệp văn bản “matran-B.txt”. Đưa các ma 
trận ra màn hình theo định dạng hàng, cột. Yêu cầu: sử dụng toán tử nhập >> để đọc 
vào ma trận từ tệp; sử dụng toán tử xuất << để đưa ma trận ra màn hình theo định dạng  
hàng cột, toán tử trừ - để trừ 2 ma trận; ma trận được tự động khởi tạo kích thước m, n 
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
        MaTran operator-(MaTran &mt2);
        //Hàm bạn
        friend ifstream& operator>> (ifstream &fin, MaTran &mt);
        friend ostream& operator<< (ostream &cout, MaTran &mt);
};
//===Chương trình chính===
int main(){
    MaTran mtA, mtB, hieu;
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");
    finA >> mtA;
    finB >> mtB;
    hieu = mtA - mtB;
    cout << "Ma tran A:\n" << mtA;
    cout << "Ma tran B:\n" << mtB;
    cout << "Hieu cua hai ma tran tren la:\n" << hieu;
    cout << endl;
    return 0;
}
//===Khai báo hàm===
MaTran::MaTran():m(0), n(0){}
MaTran MaTran::operator-(MaTran &mt2){
    MaTran hieu;
    if(m==mt2.m && n==mt2.n){
        hieu.m = m;
        hieu.n = n;
        for(int i=0;i<m;i++)
           for(int j=0;j<n;j++)
                hieu.a[i][j] = a[i][j] - mt2.a[i][j];
    }
    else cout<<"\nHai ma tran khong cung kich thuoc, khong tru duoc.\n";
    return hieu;
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