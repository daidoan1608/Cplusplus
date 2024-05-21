#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao cau truc gop he so va so mu cua mot so hang trong da thuc
struct dathuc
{
    float heSo;
    int soMu;
};

//Khai bao cau truc nut nho cua hang doi
struct node
{
    dathuc infor;
    node *link;
};

//khai bao cac ham cai dat cac phep toan
void QInsert(node* &F,node* &R,dathuc x);
dathuc QDelete(node* &F,node *&R);
bool QIsEmpty(const node *F, const node *R);

//===chuong trinh chinh===
int main()
{
    //khai bao bien hang doi
    node* F = NULL;
    node* R = NULL;
//Khai bao tep vao
    ifstream fin("dathuc.txt");

    //Khai bao bien
    dathuc t;

    //Doc da thuc tu tep dua vao hang doi va dua ra man hinh
    cout<<"Da thuc doc tu tep la :\nP(x) = ";
    while(fin>>t.heSo>>t.soMu)
    {
        if(t.soMu==0) //printf("%0.1f",t.heSo);
            cout << t.heSo;
        else //printf(" + %0.1fx^%d",t.heSo,t.soMu);
            cout << '+' << t.heSo << "x^" << t.soMu;
        QInsert(F,R,t);
    }

    //Tinh P(x)
    float x,Px=0;
    cout<<"\n\nNhap vao x: ";cin>>x;

    while(!QIsEmpty(F,R))
    {
        t = QDelete(F,R);
        Px += t.heSo*pow(x,t.soMu);
    }

    //printf("P(x) = %0.1f",Px);
    cout << "P(x) = " << Px ; 

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void QInsert(node* &F,node* &R,dathuc x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao sau nut R
    if(QIsEmpty(F,R)) //Hang doi rong
    {
        F=R=N;
        return;
    }
    else R->link=N;

    //3.Cho R cho sang nut moi
    R=N;
}

dathuc QDelete(node* &F,node* &R)
{
    //1.Kiem tra rong
    if(QIsEmpty(F,R))
    {
        cout<<"\nHang doi rong!";
        dathuc tg;
        return tg;
    }

    //2.Giu lai nut dau hang doi
    dathuc tg = F->infor;
    node *P = F;

    //3.Cho F cho sang nut tiep theo
    if(F==R) F=R=NULL;
    else F=F->link;

    //Huy nut va tra ve phan tu loai bo
    delete P;
    return tg;
}

bool QIsEmpty(const node *F, const node *R)
{
    return (F == NULL) && (R == NULL);
}