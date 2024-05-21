#include<stdio.h>
#include<stdlib.h>

void hoanDoi(int *a,int *b);
void sapXep(int *dayso, int n);
void inDaySo(int *dayso, int n);

using namespace std;

int main()
{
    int n=0;
    int so;
    int *daySo;
    FILE *fp;

    fp=fopen("daysonguyen.txt","r");
    if (fp == NULL)
    {
        printf("Khong the mo tep");
        return 1;
    }
    //đếm số phần tử trong tệp
    while (fscanf(fp,"%d",&so)==1)
        n++;

    //đưa con trỏ tệp về phần tử đầu tiên
    rewind(fp);

    daySo = (int*)malloc(n*sizeof(int));

    //đọc dãy số nguyên từ tệp vào mảng
    for (int i = 0; i < n; i++)
        fscanf(fp,"%d",&daySo[i]);
    
    //đóng tệp
    fclose(fp);
    
    //Sắp xếp lại dãy số
    sapXep(daySo,n);

    //In dãy số đã sắp xếp ra
    printf("Day so da sap xep tang dan: ");
    inDaySo(daySo,n);

    free(daySo);

    return 0;
}
//===Định nghĩa hàm===
void hoanDoi(int *a,int *b)
{
    int trungGian= *a;
    *a=*b;
    *b=trungGian;
}

void sapXep(int *daySo,int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (daySo[j]<daySo[i])
                hoanDoi(&daySo[i],&daySo[j]);  
}

void inDaySo(int *daySo,int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ",daySo[i]);
}