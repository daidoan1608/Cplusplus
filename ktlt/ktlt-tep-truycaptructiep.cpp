// Ho ten: Doan Minh Dai
// Ma SV: 671259
// Lop: K67CNTTC
// De:

#include <stdio.h>

int main() 
{
    int n, x, k, y;
    FILE *fp;

    fp = fopen("songuyen.dat", "r+b");
    

    fseek(fp, 0, SEEK_END);
    n = ftell(fp) / sizeof(int);

    printf("Nhap vao vi tri phan tu can thay the (1 <= k <= %d): ", n);
    scanf("%d", &k);

    printf("Nhap vao gia tri thay the: ");
    scanf("%d", &x);

    fseek(fp, (k - 1) * sizeof(int), SEEK_SET);
    fwrite(&x, sizeof(int), 1, fp);

    rewind(fp);
    while (fread(&y, sizeof(int), 1, fp) > 0) {
        printf("%d ", y);
    }

    fclose(fp);

    return 0;
}

