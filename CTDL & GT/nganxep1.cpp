// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:
/*
(ctdlgt-nganxep1.cpp): Cài đặt cấu trúc dữ liệu ngăn xếp
lưu trữ kế tiếp có phần tử là số nguyên.
Ứng dụng ngăn xếp đã cài đặt cho bài toán
chuyển đổi số nguyên hệ 10 sang hệ 2.
*/
#include <iostream>
#include <stdio.h>
using namespace std;
// Khai bao hang kich thuoc ngan xep
#define N 32
// Khai bao ham cai dat cac phep toan tren ngan xep
void push(int *S, int &T, int x);
int pop(int *S, int &T);
bool isEmpty(const int *S, int T);
//===chuong trinh chinh===
int main()
{
    // Cai dat cau truc luu tru ke tiep cua ngan xep
    int S[N];
    int T = -1;

    int n, thuong, du;
    
    printf("Nhap vao so nguyen duong can chuyen doi: ");
    scanf("%d",&n);

    thuong = n;
    
    while (thuong)
    {               
        du = thuong % 2;
        thuong /= 2;

        push(S,T,du);
    }
    
    printf("So nhi phan cua %d la: ",n);
    while (!isEmpty(S,T))
        printf("%d",pop(S,T));
    
    cout << endl;
    return 0;
}
//===dinh nghia ham===
void push(int *S, int &T, int x)
{
    if (T == N - 1)
        printf("Ngan xep da day.");
    S[++T] = x;
}
int pop(int *S, int &T)
{
    if (T==-1)
    {
        printf("Ngan xep rong.\n");
        return 1;
    }
        return S[T--]; // Lấy giá trị từ ngăn xếp và giảm T
}
bool isEmpty(const int *S, int T)
{
    return T == -1;
}