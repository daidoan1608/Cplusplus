#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Định nghĩa cấu trúc ThiSinh
struct ThiSinh
{
    char soBaoDanh[10];
    float diemThi;
};

// Khai báo các hàm ngăn xếp
void push(ThiSinh *S, int &T, ThiSinh x, int N);
ThiSinh pop(ThiSinh *S, int &T);
bool isEmpty(ThiSinh *S, int &T);

//=== Chương trình chính ===
int main()
{
    const int N = 100;
    ThiSinh S[N];
    int T = -1; // T là chỉ số đỉnh ngăn xếp (ban đầu rỗng)

    ThiSinh ts1 = {"12345", 8.5};
    ThiSinh ts2 = {"67890", 9.0};
    ThiSinh ts3 = {"11223", 7.0};

    push(S, T, ts1, N);
    push(S, T, ts2, N);
    push(S, T, ts3, N);

    cout << "Pop tu ngan xep:\n";
    while (!isEmpty(S, T))
    {
        ThiSinh ts = pop(S, T);
        cout << "SBD: " << ts.soBaoDanh << ", Diem thi: " << ts.diemThi << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}

//=== Định nghĩa hàm ===

// Hàm thêm phần tử vào ngăn xếp
void push(ThiSinh *S, int &T, ThiSinh x, int N)
{
    if (T == N - 1)
    {
        cout << "Ngan xep da day.\n";
        return;
    }
    S[++T] = x; // Tăng đỉnh ngăn xếp và thêm phần tử
}

// Hàm lấy phần tử khỏi ngăn xếp
ThiSinh pop(ThiSinh *S, int &T)
{
    ThiSinh temp = {"", 0.0}; // Trả về đối tượng rỗng nếu ngăn xếp rỗng
    if (T == -1)
    {
        cout << "Ngan xep rong.\n";
        return temp;
    }
    return S[T--]; // Trả về phần tử trên cùng và giảm T
}

// Hàm kiểm tra ngăn xếp rỗng
bool isEmpty(ThiSinh *S, int &T)
{
    return T == -1;
}
