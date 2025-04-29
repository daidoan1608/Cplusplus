#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

// Khai bao cau truc 1 nut nho cho DSLK kep
struct node
{
    int infor;
    node *left, *right;
};

// Khai bao ham cai dat cac phep toan
node *DLPostInsert(node *&L, node *&R, node *M, int x);
void DLDisplay(node *L, node *R);
node *DLSearchX(node *&L, node *&R, int x);

//===Chuong trinh chinh===
int main()
{
    // Khai bao tep
    ifstream fin("daysonguyen-kt.txt");
    // Cai dat cau truc luu tru DSLK kep
    node *L = NULL, *R = NULL;

    // Khai bao bien
    int x;
    node *M = NULL;

    // Doc vao tu tep theo thu tu
    while (fin >> x)
        DLPostInsert(L, R, R, x);

    // Dua ra day so doc duoc
    cout << "day so trong DSLKK la:\n";
    DLDisplay(L, R);

    // Nhap vao gia tri can tim:
    cout << "\n\nNhap gia tri can tim: ";
    cin >> x;

    // Tim phan tu bang x
    M = DLSearchX(L, R, x);

    if (M != NULL)
    {
        cout << "Tim thay x tai dia chi: " << M << endl;
    }
    else
    {
        cout << "Khong tim thay x trong DSLK kep.\n";
    }

    cout << endl;
    return 0;
}

//==Dinh nghia ham===
node *DLPostInsert(node *&L, node *&R, node *M, int x)
{
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    if (L == NULL) // danh sach rong
        L = R = N;
    else if (M == R) // M tro nut cuoi
    {
        M->right = N;
        N->left = M;
        R = N;
    }
    else
    {
        N->right = M->right;
        M->right->left = N;
        M->right = N;
        N->left = M;
    }
    return N;
}

void DLDisplay(node *L, node *R)
{
    // In ra tu trai sang phai
    node *P = L;

    while (P)
    {
        cout << P->infor << " ";
        P = P->right;
    }
}

node *DLSearchX(node *&L, node *&R, int x)
{
    // Tim nut co phan tu dl x
    node *P = L;

    while (P)
    {
        if (P->infor == x)
            return P;
        else
            P = P->right;
    }

    // Truong hop khong tim thay
    return NULL;
}
