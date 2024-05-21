#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int m,n,i,j,a[100][100],s=0,dem=0;
    float tbc;
    printf("Nhap vao so hang cua ma tran: ");
    scanf("%d",&m);
    printf("Nhap vao so cot cua ma tran: ");
    scanf("%d",&n);
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("Nhap vao phan tu a[%d][%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
            if (a[i][j]>0 && a[i][j]%2==0)
            {
                s += a[i][j];
                dem++;
            }
        }
        
    }
    tbc=1.0*s/dem;
    printf("Tong cac phan tu duong chan cua ma tran la: %d",s);
    printf("\nTBC cua cac phan tu duong chan cua ma tran la: %.3f\n",tbc);
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;   
}
