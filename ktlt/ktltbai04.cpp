//Ho ten: Doan Minh Dai
//Ma SV: 671259
//Lop: K67CNTTC
//De:

#include<stdio.h>
#include<math.h>

int main()
{
    float sinx,x,temp;
    int n;

    printf("Nhap vao gia tri cua x: ");
    scanf("%1f",&x);

    sinx=temp=x;
    n=1;

    while (fabs(temp)>=1e-4)
    {
        temp = (-1*temp*x*x)/((2*n)*(2*n+1));
        sinx += temp;
        n++;
    }
    
printf("sin(%1f) =  %1f\n",x,sinx);

    return 0;
}