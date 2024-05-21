#include <stdio.h>

int main()
{
    int n, phanDu,i=0;
    char xauhex[20];
    printf("Nhap vao mot so nguyen duong lon hon 100: ");
    scanf("%d", &n);

    while (n != 0)
    {
        phanDu=n%16;
        n /= 16;
        if (phanDu < 10)
            xauhex[i]=phanDu+48;
        else
            xauhex[i]=phanDu+55;
        i++;
    }
    printf("So da nhap chuyen sang he 16 la: ");
    for (int j = i-1 ; j >=0 ; j--)    
        printf("%c",xauhex[j]);
    return 0;
}