// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:

#include <bits/stdc++.h>

using namespace std;

struct thisinh
{
    char soBD[11];
    float diemThi;
};

struct Node
{
    thisinh infor;
    struct Node *link;
};

// Khai bao ham cai dat cac phep toan tren ngan xep
void push(Node* &T,char x);
char pop(Node* &T);
bool isEmpty(const Node *T);

//===chuong trinh chinh===
int main()
{
    // Cai dat cau truc luu tru phan tan cua ngan xep
    Node *T= NULL;
    int n;
    cout << "Nhap vao so nguyen duong n can chuyen doi tu he 10 sang hex: ";
    cin >> n;
    ofstream fout("thctdlgt-thi-ketqua.txt");
    fout << n << "\n";
    while (n != 0)
    {
        char tg;
        if (n % 16 < 10)
        {
            tg = char(n % 16 + 48);
            push(T,tg); //Phần dư nhỏ hơn 10 nối phần dư vào xâu
        }
        else
        {
            tg = char(n % 16 + 55);
            push(T,tg); //Phần dư lớn hơn 10 chuyển phần dư thành chứ in hoa bằng cách + 55 để lấy giá trị kí tự chữ hoa trong bảng mã askey
        }
        n = n / 16;
    }

    cout << "So nguyen duong da nhap co dang hex la:";
    while (!isEmpty(T))
    {   
        char tg = pop(T);
        fout << tg ;
        cout << tg ;
    }

    cout << endl;
    delete T;
    return 0;
}
//===dinh nghia ham===
void push(Node* &T, char x)
{
    Node *N= new Node;
    N->infor=x;
    N->link= T;
    T=N;
}

char pop(Node* &T)
{
    if (isEmpty(T))
    {
        printf("Ngan xep rong.\n");
        return 1;
    }
    char tg=T->infor;
    Node *P=T;
    T=T->link;
    delete P;
    return tg;
}

bool isEmpty(const Node*T)
{
    return T == NULL;
}
