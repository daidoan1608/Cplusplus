// DSLKK, doc day tu tep daysonguyen.txt, nhap phan tu x muon xoa, dua ra day sau khi xoa
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
// Khai bao cau truc gop 2 bien L, R
struct DList
{
    node *L, *R;
};

// Khai bao ham cai dat cac phep toan
node *DLPostInsert(DList &LR, node *M, int x);
void DLPreInsert(DList &LR, node *M, int x);
void DLDelete(DList &LR, node *M);
void DLDisplay(DList LR, bool leftToRight = 1);
node *DLSearchX(DList LR, int x);

//===Chuong trinh chinh===
int main()
{
    // Khai bao tep
    ifstream fin("daysonguyen.txt");
    // Cai dat cau truc luu tru DSLK kep
    DList LR = {NULL, NULL};

    // kkhai bao bien
    int x;
    node *M = NULL;

    // doc vao tu tep theo thu tu
    while (fin >> x)
        DLPostInsert(LR, LR.R, x);
    // Dua ra day so doc duoc
    cout << "day so trong DSLKK la:\n";
    DLDisplay(LR);
    // Xoa phan tu dl x
    cout << "\n\nNhap gia tri can xoa: ";
    cin >> x;
    // Xoa tat ca phan tu trong DSLKK co gia tri bang x
    while (M = DLSearchX(LR, x))
        DLDelete(LR, M);
    // Dua ra DSLKK sau khi xoa
    cout << "\nday so trong DSLKK sau khi xoa la:\n";
    DLDisplay(LR);

    cout << endl;
    system("pause");
    return 0;
}
//==Dinh nghia ham===
node *DLPostInsert(DList &LR, node *M, int x)
{
    // 1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;
    // 2.Bo sung nut moi
    if (LR.L == NULL) // Hang doi rong
        LR.L = LR.R = N;
    else if (M == LR.R) // M tro toi nut cuc phai
    {
        M->right = N;
        N->left = M;
        LR.R = N;
    }
    else // Truong hop con lai
    {
        N->right = M->right;
        M->right->left = N;
        M->right = N;
        N->left = M;
    }
    // Tra ve dia chi nut moi bo sung
    return N;
}
void DLPreInsert(DList &LR, node *M, int x)
{
    // 1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;
    // 2.Bo sung nut moi
    if (LR.L == NULL) // Hang doi rong
        LR.L = LR.R = N;
    else if (M == LR.L) // M tro toi nut cuc trai
    {
        N->right = M;
        M->left = N;
        LR.L = N;
    }
    else // Truong hop con lai
    {
        M->left->right = N;
        N->left = M->left;
        N->right = M;
        M->left = N;
    }
}
void DLDelete(DList &LR, node *M)
{
    // 1.Kiem tra dan123ggh sach rong
    if (LR.L == NULL)
    {
        cout << "Danh sach lien ket kep rong!";
        return;
    }
    // 2.Thay doi lien ket
    if (LR.L == LR.R) // Danh sach chi con 1 nut va M tro toi nut do
        LR.L = LR.R = NULL;
    else if (M == LR.L) // M tro toi nut cuc trai
    {
        LR.L = LR.L->right;
        LR.L->left = NULL;
    }
    else if (M == LR.R) // M tro toi nut cuc phai
    {
        LR.R = LR.R->left;
        LR.R->right = NULL;
    }
    else // Truong hop con lai
    {
        M->left->right = M->right;
        M->right->left = M->left;
    }

    // 3.Huy nut M
    delete M;
}
void DLDisplay(DList LR, bool leftToRight)
{
    node *P = leftToRight ? LR.L : LR.R;

    while (P)
    {
        cout << P->infor << " ";
        P = leftToRight ? P->right : P->left;
    }
}

node *DLSearchX(DList LR, int x)
{
    // Tim nut co phan tu dl x
    node *P = LR.L;
    while (P)
        if (P->infor == x)
            return P;
        else
            P = P->right;

    // Truong hop khong tim thay
    return NULL;
}
