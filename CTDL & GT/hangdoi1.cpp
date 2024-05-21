// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:

#include <stdio.h>
#include <stdlib.h>

#define N 100

void cQInsert(int *Q,int &F,int &R,int x);
int cQDelete(int *Q,int &F,int &R);
bool isEmpty(const int *Q,int F,int R);

int main()
{
    int F = -1; // Chỉ mục đầu hàng đợi
    int R = -1;  // Chỉ mục cuối hàng đợi
    int Q[N]; // Mảng lưu trữ các phần tử
    
    FILE *file;
    int number;

    // Mở tệp văn bản để đọc
    file = fopen("daysonguyen.txt", "r");

    // Kiểm tra xem tệp có tồn tại không
    if (file == NULL) {
        printf("Khong the mo tep\n");
        return 1; // Thoát chương trình với mã lỗi 1
    }

    // Đọc và hiển thị dãy số nguyên dương từ tệp
    while (fscanf(file, "%d", &number) == 1)
    {
        cQInsert(Q,F,R,number);
    }

    // Đóng tệp sau khi hoàn thành
    fclose(file);

    int chan[50],le[50],i=0,j=0;

    while (!isEmpty(Q,F,R))
    {
        int temp=cQDelete(Q,F,R);
        if(temp%2==0)
        {
            chan[i]=temp;
            i++;
        }
        else
        {
            le[j]=temp;
            j++;
        }
    }
    printf("Day so le:\n");
    for (int k = 0; k < j; k++)
        printf("%d\n", le[k]);

    printf("Day so chan:\n");
    for (int k = 0; k < i; k++)
        printf("%d\n", chan[k]);

    return 0;
}
// Hàm kiểm tra hàng đợi có rỗng không
bool isEmpty(const int *Q,int F,int R)
{
    return (F == -1 && R == -1);
}

// Hàm để thêm một phần tử vào hàng đợi
void cQInsert(int *Q,int &F,int &R,int x)
{
    if (F==0 && R==N || F==R + 1)
    {
        printf("Hang doi day!\n");
        return;
    }

    if (F==-1 && R==-1)
        F = R = 0; // Nếu hàng đợi rỗng, đặt F về 0
    else if (R==N)
        R=0;
    else 
        R++;
    
    Q[R] = x;
}

// Hàm để lấy một phần tử ra khỏi hàng đợi
int cQDelete(int *Q,int &F,int &R)
{
    int tg;
    if (isEmpty(Q,F,R))
    {
        printf("Hang doi rong!\n");
        return -1; // Giả sử -1 là giá trị đặc biệt để biểu thị hàng đợi rỗng
    }

    tg = Q[F];
    if (F==R)
    {
        F=R=-1;
    }
    else if(F==N-1)
        F=0;
    else
        F++;

    return tg;
}