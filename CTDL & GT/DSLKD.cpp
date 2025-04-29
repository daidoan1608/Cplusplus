#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//cai dat cau truc du lieu dslkd
struct node
{
    int infor;
    node *link;
};

//Khai bao ham cai dat cac phep toan
node* SLPostInsert(node* &F,node *M,int x);
node* SLPreInsert(node* &F,node *M,int x);
void SLDelete(node* &F,node *M);
void SLDisplay(node *F);
node* SLSearch(node *F,int x);

//chuong trinh chinh
int main()
{
    ifstream fin("daysonguyen.txt");

    //Tao 2 DSLK don P, Q
    node *P=NULL,*Q=NULL,*M=NULL;

    //Khai bao bien
    int x;

    //Doc day so tu tep vao DSLKD P theo dung thu tu tren tep
    while(fin>>x) M = SLPostInsert(P,M,x);

    cout<<"Day so nguyen trong DSLKD la:\n";
    SLDisplay(P);

    //Tao DSLKD Q la dao duoc cua P
    M=P;
    
    while(M)
    {
        SLPreInsert(Q,Q,M->infor);
        M=M->link;
    }
    cout<<"\n\nDay so trong DSLKD P sau khi dao nguoc la:\n";
    SLDisplay(Q);


    cout<<"\nHay nhap gia tri muon xoa trong day P : "; cin>>x;
    if(SLSearch(P,x))
    {
        SLDelete(P,SLSearch(P,x));
        cout<<"\nDSLK P sau khi xoa la: ";
        SLDisplay(P);
    }
    else
        cout<<"\nKhong co phan tu x trong DSLKD P !!";


    cout<<endl;
    return 0;
}

//dinh nghia ham
node* SLPostInsert(node* &F,node *M,int x)
{
    //tao nut moi chua du lieu x
    node *N=new node;
    N->infor = x;
    N->link = NULL;

    //bo sung nut chua du lieu x vao danh sach
    if(F==NULL) F=N;
    else
    {
        N->link=M->link;
        M->link=N;
    }

    //tra ve dia chi nut moi bo sung
    return N;
}
node* SLPreInsert(node* &F,node *M,int x)
{
    //tao nut moi chua du lieu x
    node *N=new node;
    N->infor = x;
    N->link = NULL;

    //bo sung nut moi vao truoc nut M
    if(F==NULL) F=N;
    else
        if(M==F)
        {
            N->link=M;
            F=N;
        }
        else
        {
            node *P=F;
            while(P->link!=M)
                P=P->link;

            P->link=N;
            N->link=M;
        }

    //tra ve dia chi nut moi bo sung
    return N;
}
void SLDelete(node* &F,node *M)
{
    //thong bao danh sach rong
    if(F==NULL)
    {
        cout<<"Danh sach rong!";
        return;
    }
    else
 if(M==F) F=F->link;
        else
        {
            //tim nut dung truoc M
            node *P=F;
            while(P->link!=M) P=P->link;

            //noi nut truoc M voi nut sau M
            P->link=M->link;
         }

    //loai bo M
    delete M;
}

void SLDisplay(node *F)
{
    node *P=F;
    while(P)
    {
        cout<<P->infor<<"  ";
        P=P->link;
    }
}

node* SLSearch(node *F,int x)
{
    node *P=F;
    while(P)
        if(P->infor==x) return P;
        else P=P->link;

    //Truong hop khong tim thay
    return NULL;
}



