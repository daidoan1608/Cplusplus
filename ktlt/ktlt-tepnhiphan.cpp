// Ho ten: Doan Minh Dai
// Ma SV: 671259
// Lop: K67CNTTC
// De:

#include <stdio.h>

int main() 
{
    //Khai bao bien
    int n,x;
    FILE *fp;

    //Nhap vao so luong cac so nguyen
    printf("Nhap so luong so nguyen can tao: ");
    scanf("%d", &n);
    
    //Ghi tep
    fp = fopen("songuyen.dat", "wb");

    for (int i = 0; i < n; i++)
    {
        printf("Nhap so thu %d: ", i+1);
        scanf("%d", &x);
        fwrite(&x, sizeof(int), 1, fp);
    }
    
    fclose(fp);
    

    //Doc tep
    fp = fopen("songuyen.dat","rb");

    printf("Cac so nguyen trong tep la: ");

    //Doc cac so nguyen co trong tep va in ra
    while (fread(&x, sizeof(int), 1, fp))
    {
        printf("%d ", x);
    } 
    

    fclose(fp);
    return 0;
}
