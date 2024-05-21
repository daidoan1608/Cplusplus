#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

struct thiSinh
{
        char soBD[11];
        char hoTen[31];
        char gioiTinh[6];
        float diemThi;
};

struct node
{
        thiSinh infor;
        struct node *link;
};

void push(node* &T,thiSinh x);
thiSinh pop(node* &T);
bool isEmpty(const node *T);

int main()
{
        node *T = NULL;
        ifstream fin("thisinh1.txt");

        int n;
        thiSinh x;
        char tg[3];

        fin >> n;
        fin.ignore();
        for(int i = 0; i < n; i++)
        {
                fin.getline(tg,sizeof(tg));
                fin.getline(x.soBD,sizeof(x.soBD),'\t');
                fin.getline(x.hoTen,sizeof(x.hoTen),'\t');
                fin.getline(x.gioiTinh,sizeof(x.gioiTinh),'\t');
                fin >> x.diemThi;
                push(T,x);
        }

        cout << "Danh sach thi sinh nam xep theo thu tu diem thi giam dan: " << endl;
        while(!isEmpty(T))
        {
                x=pop(T);
                if(strcasecmp(x.gioiTinh,"Nam")==0)
                {
                        cout << "\nSo bao danh: " << x.soBD;
                        cout << "\nHo ten: " << x.hoTen;
                        cout << "\nGioi tinh: " << x.gioiTinh;
                        cout << "\nDiem thi: " << x.diemThi << endl;
                }
        }

        cout << endl;
        fin.close();
        return 0;
}

void push(node* &T,thiSinh x)
{
        node *N = new node;
        N->infor = x;
        N->link = T;
        T = N;
}

thiSinh pop(node* &T)
{
        if(isEmpty(T))
        {
                cout << "Ngan xep rong" << endl;
                thiSinh tg;
                return tg;
        }
        thiSinh tg = T->infor;
        node *P=T;
        T=T->link;
        delete P;
        return tg;
}

bool isEmpty(const node *T)
{
    return T==NULL;
}