#include<iostream>
using namespace std;

int main()
{
    int n,a[100],s=0,dem;
    float tbc;
    printf("So phan tu cua day so la: ");
    scanf("%d",&n);
    printf("Nhap vao day so can sap xep: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i]%3==0 && a[i]>0)
        {
            s += a[i];
            dem++;
        }
    }
    tbc=1.0*s/dem;
    printf("Tong cac so duong chia het cho 3 trong day so la: %d",s);
    printf("\nTong cac so duong chia het cho 3 trong day so la: %.3f",tbc);
    return 0;
}