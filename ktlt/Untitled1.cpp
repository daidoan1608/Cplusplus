// Ho ten: Doan Minh Dai
// Ma SV: 671259
// Lop: K67CNTTC
// De:

#include <stdio.h>
#include <math.h>
#define PI 3.14

int main()
{
    int choice;
    float a, b, c, r, dai, rong;
    float chuvi, dientich;

    while (1)
    {
        printf("\nTINH DIEN TICH VA CHU VI CAC HINH\n1. Tinh dien tich va chu vi hinh tam giac biet ba canh\n2. Tinh dien tich va chu vi hinh tron biet ban kinh\n3. Tinh dien tich va chu vi hinh chu nhat biet 2 canh\n4. Ket thuc chuong trinh\n\nChon hinh de tinh(1/2/3/4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap vao ba canh cua tam giac: ");
            scanf("%f%f%f", &a, &b, &c);

            int p;
            p = (a + b + c) / 2;
            dientich = sqrt(p * (p - a) * (p - b) * (p - c));

            printf("\nDien tich cua tam giac co ba canh %f, %f, %f la: %f", a, b, c, dientich);
            printf("\nChu vi cua tam giac co ba canh %f, %f, %f la: %f", a, b, c, a + b + c);
            
            fflush(stdin);
            getchar();

            break;
        case 2:
            printf("Nhap vao ban kinh cua hinh tron: ");
            scanf("%f", &r);

            printf("\nDien tich cua hinh tron co ban kinh r=%f la: %f", r, r * r * PI);
            printf("\nChu vi cua hinh tron co ban kinh r=%f la: %f", r, 2 * r * PI);
            fflush(stdin);

            getchar();

            break;
        case 3:
            printf("\nNhap vao chieu dai va chieu rong cua hinh chu nhat: ");
            scanf("%f%f", &dai, &rong);

            printf("\nDien tich cua hinh chu nhat co chieu dai %f va chieu rong %f la: %f", dai, rong, dai * rong);
            printf("\nChu vi cua hinh chu nhat co chieu dai %f va chieu rong %f la: %f", dai, rong, (dai + rong) * 2);
            fflush(stdin);

            getchar();

            break;
        case 4:
            return 0;
        default:
            printf("Ban da nhap sai lua chon vui long nhap lai\n");
            break;
        }
    }
    return 0;
}
