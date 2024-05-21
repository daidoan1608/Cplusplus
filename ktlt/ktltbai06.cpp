#include <stdio.h>

int main() {
    FILE *fp;
    int a, b, c;

    // Mở tệp "data.txt" với chế độ đọc
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Khong the mo tep\n");
        return 1;
    }

    // Đọc dữ liệu từ tệp
    fscanf(fp, "%d %d %d", &a, &b, &c);

    // Đóng tệp
    fclose(fp);

    // In kết quả
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
