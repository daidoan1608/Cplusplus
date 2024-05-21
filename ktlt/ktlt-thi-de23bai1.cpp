// Ho ten: Doan Minh Dai
// Ma SV: 671259
// Lop: K67CNTTC
// De:

#include <stdio.h>
#include <iostream>
#include <string.h>

//===Chương trình chính===
int main()
{
    // Khai bao bien
    char s[50], s1[50], s2[50];
    int i = 0, j = 0, k = 0;

    // Nhập vào xâu ký tự
    printf("Nhập vào xâu ký tự(chỉ gồm chữ thường và số: ");
    scanf("%s", &s);

    // Tách xâu
    while (s[i] != '\0')
    {
        // Phần tử thứ i trong xâu s trong khoảng 0 đến 9 thì cho vào xâu s1
        if (s[i] >= '0' && s[i] <= '9')
        {
            s1[j] = s[i];
            j++;
        }

        // Phần tử thứ i trong xâu s trong khoảng a đến z thì cho vào xâu s2
        else
        {
            s2[k] = s[i];
            k++;
        }
        i++;
    }

    //Thêm phần tử rỗng vào cuối mỗi xâu
    s1[j] = '\0';
    s2[j] = '\0';

    //Đưa xâu ban đầu, xâu đã tách, độ dài các xâu ra màn hình
    printf("Xâu ban đầu là: %s\n có độ dài là: %d",s,strlen(s));
    printf("\n\nXâu chứa số là: %s\n có độ dài là: %d",s1,strlen(s1));
    printf("\n\nXâu chưa chữ là: %s\n có độ dài là: %d",s2,strlen(s2));


    return 0;
}
//===Định nghĩa hàm===