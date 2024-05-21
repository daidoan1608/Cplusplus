// Ho ten: Doan Minh Dai
// Ma SV: 671259
// Lop: K67CNTTC
// De:

#include <stdio.h>
#include <iostream>
#include <string.h>

void inRa(int a[10][10],int m, int n);
int tong(int a[10][10],int m, int n);
int trungBinhCong(int a[10][10],int m, int n);

//===Chương trình chính===
int main()
{
    // Khai bao bien
    int maTran[10][10];
    int m,n;
    FILE *fp;

    //Mở tệp
    fp = fopen("matrannguyen-thi.txt","rt");

    //Đọc kích thước ma trận từ tệp
    fscanf(fp,"%d%d",&m,&n);

    //Đọc ma trận
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp,"%d",&maTran[i][j]);

    //Đóng tệp
    fclose(fp);
    
    //In ra ma trận
    printf("Ma trận được quét từ tệp là: \n");
    inRa(maTran,m,n);

    printf("Tổng các phần tử của ma trận là: %d",tong(maTran,m,n));

    printf("Trung bình cộng các phần tử của ma trận là: %f",trungBinhCong(maTran,m,n));

    return 0;
}
//===Định nghĩa hàm===
//Hàm in ra ma trận
void inRa(int a[10][10],int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        //In ra các phần tử của hàng i
        for (int j = 0; j < n; j++)
            printf("%6d",a[i][j]);
        
        //Xuống dòng
        printf("\n");
    }
}
int tong(int a[10][10],int m, int n)
{
    int tong=0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            tong += a[i][j];
    return tong;
}
int trungBinhCong(int a[10][10],int m, int n)
{
    return (float)tong(a,m,n)/(m*n);
}