#include <iostream>
#include <fstream>

using namespace std;

struct thiSinh
{
    char soBaoDanh[10];
    float diemThi;
};
struct node
{
    thiSinh infor;
    node *link;
};

void SLPostInsert(node *&F, node *M, thiSinh thongTin);
void PreInsert(node *&F, node *&M, thiSinh thongTin);
void SLDelete(node *&F, node *M);
void SlDisplay(node *F);
node *SLSearch(node *F, thiSinh thongTin);

int main()
{
    node *F = NULL, *M = NULL;
    thiSinh thongTin;
    int n;
    ifstream fin("thisinh-kt.txt");

    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> thongTin.soBaoDanh;
        fin >> thongTin.diemThi;
        SLPostInsert(F, M, thongTin);
    }

    cout << "Danh sach thi sinh ban dau:\n";
    SLDisplay(F);

    cout << "Danh sach thi sinh theo diem giam dan:\n";
//
//


}

void SLPostInsert(node *&F, node *M, thiSinh thongTin)
{
    node *N = new node;
    N->infor = thongTin;
    N->link = NULL;
    if (F == NULL)
    {
        M = N;
        F = N;
    }
    else
    {
        M->link = N;
        M = N;
    }
}

void PreInsert(node *&F, node *M, thiSinh thongTin)
{
    node *N = new node;
    N->infor = thongTin;
    N->link = NULL;
    if (F == NULL)
        F = N;
    else if (M == F)
    {
        N->link = M;
        F = N;
    }
    else
    {
        node *P = F;
        while (P->link != M)
            P = P->link;
        P->link = N;
        N->link = M;
    }
}
void SLDelete(node *&F, node *M)
{
    if (F == NULL)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    else if (M == F)
        F = F->link;
    else
    {
        node *P = F;
        while (P->link != M)
            P = P->link;
        P->link = M->link;
    }
    delete M;
}
void SLDisplay(node *F)
{
    node *P = F;
    int i = 1;
    while (P)
    {
        cout << "Sinh vien " << i << endl;
        cout << "So bao danh: " << P->infor.soBaoDanh << endl;
        cout << "Diem thi: " << P->infor.diemThi << endl;
        P = P->link;
        i++;
    }
}

node *SLSearch(node *F, thiSinh thongTin)
{
    node *P = F;
    while (P)
    {
        if (P->infor.soBaoDanh == thongTin.soBaoDanh)
            return P;
        P = P->link;
    }
    return NULL;
}
