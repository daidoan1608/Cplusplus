#include <iostream>
#include <cstring> // Để sử dụng hàm xử lý chuỗi như strcpy

using namespace std;

struct ThiSinh
{
    char soBaoDanh[10];
    float diemThi;
};

struct Node
{
    ThiSinh thiSinh; // Dữ liệu là một ThiSinh
    Node *link;      // Con trỏ đến node tiếp theo
};

// Khai báo hàm xử lý stack
void push(Node *&T, ThiSinh thiSinh);
ThiSinh pop(Node *&T);
bool isEmpty(const Node *T);

//=== Chương trình chính ===
int main()
{
    Node *T = nullptr; // T là ngăn xếp (ban đầu rỗng)

    // Đẩy các phần tử vào ngăn xếp
    ThiSinh ts1 = {"12345", 8.5};
    ThiSinh ts2 = {"67890", 9.0};
    ThiSinh ts3 = {"11223", 7.0};

    push(T, ts1);
    push(T, ts2);
    push(T, ts3);
    // Lấy các phần tử ra và in thông tin
    cout << "Pop từ ngăn xếp:\n";
    while (!isEmpty(T))
    {
        ThiSinh ts = pop(T);
        cout << "SBD: " << ts.soBaoDanh << ", Diem thi: " << ts.diemThi << endl;
    }
    system("pause");
    return 0;
}

//=== Định nghĩa hàm ===
void push(Node *&T, ThiSinh thiSinh)
{
    Node *N = new Node;
    N->thiSinh = thiSinh;
    N->link = T;
    T = N;
}

ThiSinh pop(Node *&T)
{
    ThiSinh temp = {"", 0.0}; // Trả về đối tượng rỗng nếu ngăn xếp rỗng
    if (T == nullptr)
    {
        cout << "Ngăn xếp rỗng.\n";
        return temp;
    }

    Node *P = T;
    temp = P->thiSinh;
    T = T->link;
    delete P;
    return temp;
}

bool isEmpty(const Node *T)
{
    return T == nullptr;
}
