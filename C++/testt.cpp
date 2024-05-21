//Ho ten: Le Tuan Tu
//MaSV: 672234
//Lop: K67CNTTC
//De: Tinh gan dung so pi voi n so hang dau tien
#include<iostream>
#include<stdio.h>
using namespace std;
//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n;
    float s=1;
    
    //Nhap n
    printf("Nhap vao gia tri cua n: ");
    scanf("%d",&n);
    
    //Tinh tong ve phai de trong bien s
    for(int i=1;i<=n;i++)
        if(i%2==0) s += 1.0/(2*i+1);
        else s -= 1.0/(2*i+1);
    
    //Dua ra pi tinh duoc
    printf("So PI tinh duoc la: %0.4f",4*s);
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===