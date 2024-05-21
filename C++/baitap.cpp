// đổi từ hệ nhị phân sang hệ thập phân
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int temp=0,so_thap_phan=0,so_du=0;
    long so_nhi_phan;
    cout << "Nhap so so nhi phan can chuyen doi :";
    cin >> so_nhi_phan;
    while (so_nhi_phan!=0)
    {
        so_du = so_nhi_phan%10;
        so_nhi_phan = so_nhi_phan/10;
        so_thap_phan=so_thap_phan+so_du*pow(2,temp);
        temp++;
    }
    cout << "So nhi phan nhap vao chuyen qua he so thap phan la:" << so_thap_phan;
    return 0;
}