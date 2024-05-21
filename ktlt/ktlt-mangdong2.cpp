#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Khai bao bien
    int m, n, i, j, temp;

    printf("Nhap vao kich thuoc cua ma tran(m*n): ");
    scanf("%d%d", &m, &n);

    // Cap phat bo nho dong cho mang 2 chieu m*n phan tu
    int **a;
    a = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    // Nhap vao cac phan tu cua day so
    printf("Nhap vao cac phan tu cua day so:\n");

    for (int i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Phan tu a%d%d cua ma tran la: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Dua ma tran da nhap ra man hinh
    printf("\n\nMa tran da nhap la:\n");

    for (int i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }

    // Tìm phan tu nho nhat va doi ve cuoi hang
    for (int i = 0; i < m; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[i][j] < a[i][j + 1])
            {
                temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
            }
        }
    }

    // Dua ma tran da sap xep lai ra man hinh
    printf("\n\nMa tran da sap xep lai la:\n");

    for (int i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
    // Giai phong vung nho dong cap phat cho mang
    free(a);
    return 0;
}