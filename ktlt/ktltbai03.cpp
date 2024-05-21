//Ho ten: Doan Minh Dai
//Ma SV: 671259
//Lop: K67CNTTC
//De:

#include<stdio.h>
#include<math.h>

bool nguyento(int a)
{
    if (a<=1)
    {
        return false;
    }
    else if(a==2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i <= sqrt(a) ; i++)
        {
            if(a % i == 0)
            return false;
        }
    }
    return a > 1;
}
    
int main()
{
    int n;
    printf("Nhap vao n: ");
    scanf("%d",&n);
    // printf("Cac so nguyen to nho hon n la: ");
    // for (int i = 1; i < n;i++)
    // {
    //     if (nguyento(i))
    //     {
    //         printf("%d ",i);
    //     }
    // }
    if (n<2)
    {
        printf("Khong co so nguyen to nao nho hon n!");
    }
    else
    {
        printf("\n\nCac so nguyen to nho hon n la: ");
        for (int i = 2; i < n; i++)
        {
            bool nguyento = true;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    nguyento = false;
                    break;
                }
            }
            if (nguyento)
            {
                printf("%d  ",i);
            }
            
        }
        
    }
    return 0;
}