#include <stdio.h>
#include<stdlib.h>



int main()
{
    // Khai bao bien
    int n,i;

    printf("Nhap vao so phan tu cua day so: ");
    scanf("%d", &n);

    //Cap phat bo nho dong cho mang n phan tu
    int *a = (int *) calloc(n, sizeof(int));

    //Nhap vao cac phan tu cua day so
    printf("Nhap vao cac phan tu cua day so: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    //Thay doi kich thuoc mang ban dau
    a = (int*) realloc(a,(n+1)*sizeof(int));

    //Chen them phan tu x vao cuoi day
    printf("Nhap phan tu can chen vao cuoi day so: ");
    scanf("%d",&a[n]);

    //In ra day so
    printf("Day so da nhap vao la: ");
    for ( i = 0; i <= n; i++)
    {
        printf("%d   ",a[i]);
    }
    
    //Giai phong vung nho dong cap phat cho mang
    free(a);
    return 0;
}