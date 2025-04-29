// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int infor;
    struct Node *link;
};

void cQInsert(Node **F, Node **R, int x);
int cQDelete(Node **F, Node **R);
bool isEmpty(const Node *F, const Node *R);

int main()
{
    // Cai dat cau truc luu tru ke tiep cua ngan xep
    Node *F = NULL;
    Node *R = NULL;

    FILE *file;
    int number;

    // Mở tệp văn bản để đọc
    file = fopen("daysonguyen.txt", "r");

    // Kiểm tra xem tệp có tồn tại không
    if (file == NULL)
    {
        printf("Khong the mo tep\n");
        return 1; // Thoát chương trình với mã lỗi 1
    }

    // Đọc và hiển thị dãy số nguyên dương từ tệp
    while (fscanf(file, "%d", &number) == 1)
    {
        cQInsert(&F, &R, number);
    }

    // Đóng tệp sau khi hoàn thành
    fclose(file);

    int chan[50], le[50], i = 0, j = 0;

    while (!isEmpty(F, R))
    {
        int temp = cQDelete(&F, &R);
        if (temp % 2 == 0)
        {
            chan[i] = temp;
            i++;
        }
        else
        {
            le[j] = temp;
            j++;
        }
    }
    printf("Day so le:\n");
    for (int k = 0; k < j; k++)
        printf("%d\n", le[k]);

    printf("Day so chan:\n");
    for (int k = 0; k < i; k++)
        printf("%d\n", chan[k]);
    system("pause");

    cout << endl;
    return 0;
}

void cQInsert(Node **F, Node **R, int x)
{
    Node *N = new Node;
    N->infor = x;
    N->link = NULL;
    if (isEmpty(*F, *R))
    {
        *F = N;
        *R = N;
    }
    else
        (*R)->link = N;
    *R = N;
}

int cQDelete(Node **F, Node **R)
{
    if (isEmpty(*F, *R))
    {
        printf("Hang doi rong.\n");
        return 1;
    }

    int tg = (*F)->infor;
    Node *P = *F;

    if (*F == *R)
    {
        *F = NULL;
        *R = NULL;
    }
    else
        *F = (*F)->link;

    free(P);
    return tg;
}

bool isEmpty(const Node *F, const Node *R)
{
    return ((F == NULL) && (R == NULL));
}