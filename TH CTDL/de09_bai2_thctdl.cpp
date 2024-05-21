// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:

#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

struct thiSinh
{
    char soBaoDanh[6];
    float diemThi;
};

struct Node
{
    thiSinh infor;
    struct Node *link;
};

// Khai bao ham cai dat cac phep toan tren ngan xep
void push(Node* &T,thiSinh x);
thiSinh pop(Node* &T);
bool isEmpty(const Node *T);

//===chuong trinh chinh===
int main()
{
    // Cai dat cau truc luu tru ke tiep cua ngan xep
    Node *T= NULL;
    thiSinh a;
    int n,i=0;
    char tg[3];

    ifstream fin("thisinh.txt");

    fin >> n;
    for (int i = 0; i < n; i++)
    {
        // fin.getline(tg,sizeof(tg));
        fin.getline(a.soBaoDanh,sizeof(a.soBaoDanh),'\t');
        fin >> a.diemThi;
        push(T, a);
    }
    
    cout << "Danh sach thi sinh sap xep theo chieu diem thi giam dan la:\n\n";
    while (!isEmpty(T))
    {
        thiSinh a = pop(T);
        cout << "\nThi sinh so " << i+1 ;
        cout << "\nSo bao danh: " << a.soBaoDanh;
        cout << "\nDiem thi: " << a.diemThi << endl;
        i++;
    }
    delete T;
    fin.close();
    cout << endl;
    return 0;
}
//===dinh nghia ham===
void push(Node* &T, thiSinh x)
{
    Node *N= new Node;
    N->infor=x;
    N->link= T;
    T=N;
}

thiSinh pop(Node* &T)
{
    if (isEmpty(T))
    {
        printf("Ngan xep rong.\n");
        thiSinh temp;
        return temp;
    }
    thiSinh tg=T->infor;
    Node *P=T;
    T=T->link;
    delete P;
    return tg;
}

bool isEmpty(const Node*T)
{
    return T == NULL;
}
