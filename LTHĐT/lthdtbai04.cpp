//Ho ten: Doan Minh Dai
//Ma SV: 671259
//Lop: K67CNTTA
//De:Tính tổng 2 ma trận nguyên có kích thước mxn, Cmxn = Amxn + Bmxn.
//Đưa các ma trận ra màn hình theo định dạng hàng, cột. Y/c sử dụng mảng động
//chứa các ma trận. Các ma trận đọc vào từ tệp văn bản: "matran-A.txt" và "matran-B.txt".
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>

using namespace std;
//===Khai báo hàm===

//===Chương trình chính===
int main()
{
    int **a, **b, **c, m, n;
    ifstream fin("matran-A.txt");
    fin >> m >> n;
    a = new int*[m];
    for(int i=0; i<m; i++)
    {
        a[i] = new int[n];
        for(int j=0; j<n; j++)
            fin >> a[i][j];
    }
    fin.close();
    for(int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    fin.open("matran-B.txt");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            fin >> b[i][j];
    }
    cout << endl;
}
//===Định nghĩa hàm===