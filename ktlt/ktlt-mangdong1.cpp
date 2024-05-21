#include <stdio.h>
#include<stdlib.h>



int main()
{
    // Khai bao bien
    int n,i,max,index;

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

    //Tìm phan tu lon nhat trong day so

    max = a[0];
    index = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }

    //Xuat phan tu lon nhat ra man hinh
    printf("Phan tu lon nhat la phan tu thu %d co gia tri la: %d", index+1, max);

    //Giai phong vung nho dong cap phat cho mang
    free(a);
    return 0;
}