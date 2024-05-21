#include <stdio.h>

int main()
{
    float a1, b1, c1, a2, b2, c2, x, y, d;

    printf("Nhap cac he so a, b, c cua he phuong trinh tuyen tinh ax + by = c:\n");
    scanf("%f%f%f", &a1, &b1, &c1);
    printf("Nhap cac he so a, b, c cua he phuong trinh tuyen tinh ax + by = c:\n");
    scanf("%f%f%f", &a2, &b2, &c2);

    d = a1 * b2 - a2 * b1;

    if (d == 0) {
        if (c1 * b2 == c2 * b1) {
            printf("He phuong trinh co vo so nghiem.\n");
        } else {
            printf("He phuong trinh vo nghiem.\n");
        }
    } else {
        x = (c1 * b2 - c2 * b1) / d;
        y = (a1 * c2 - a2 * c1) / d;
        printf("He phuong trinh co nghiem (x, y) = (%.2f, %.2f).\n", x, y);
    }

    return 0;
}
