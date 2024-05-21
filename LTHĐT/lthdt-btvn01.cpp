//Ho ten: Doan Minh Dai
//Ma SV: 671259
//Lop: K67CNTTA
//De:Viết Chương trình tính gióa trị của biểu thức: Y = 2*log5(x^2 + 1)
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
//===Khai báo hàm===

//===Chương trình chính===
int main()
{
    int x;
    cout << "Nhap vao x: ";
    cin >> x;
    float y = 2*((log10(x*x + 1))/(log10(5)));
    cout << "Gia tri cua bieu thuc Y = 2*log5(x^2 + 1) la: " << y << endl;
    return 0;
}
//===Định nghĩa hàm===