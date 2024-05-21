//Ho ten: Doan Minh Dai
//Ma SV: 671259
//Lop: K67CNTTA
//De:Tính gần đúng sinx với độ chính xác 10^-4 theo công thức sau: sinx = x - x^3/3! + x^5/5! + ... + (-1)^n * x^(2*n+1)/(2*n+1)! + ...
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
//===Khai báo hàm===

//===Chương trình chính===
int main()
{
    int x;
    float sinx = 0;
    cout << "Nhap vao x: ";
    cin >> x;

    for(int n=0; ; n++)
    {
        float t = pow(-1,n)*pow(x,2*n+1);
        int m = 1;
        for(int i=1; i<=2*n+1; i++)
            m *= i;
        t /= m;
        if(fabs(t) < 1e-4)
            break;
        sinx += t;
    }
    
    cout << "sin(" << x << ") = " << sinx << endl;
    return 0;
}
//===Định nghĩa hàm===