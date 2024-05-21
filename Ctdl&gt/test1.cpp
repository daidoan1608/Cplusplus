//Ho ten: Le Tuan Tu
//MaSV: 623321
//Lop: K62CNTTA
//De:
/*
Bài 05(thctdlgtbai05.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
tệp văn bản 'matran-A.txt', ma trận Bmxn để trong tệp văn bản 'matran-B.txt'. Ma trận tổng Cmxn
được ghi ra tệp văn bản 'kq-thctdlgtbai05.txt'. Yêu cầu sử dụng mạng động chứa các ma trận,
viết hàm đọc vào ma trận từ tệp, hàm đưa ra ma trận và hàm cộng 2 ma trận.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao ham cai dat cac phep toan tren mang 2 chieu
void docVaoMT(int* &V,int &m,int &n,const char *tenTep);
void duaRaMT(int *V,int m,int n);
int* congMT(int *V1,int *V2,int m,int n);

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int *A,*B,*C;
    int mA,nA,mB,nB;

    //Doc vao ma tran
    docVaoMT(A,mA,nA,"matran-A.txt");
    docVaoMT(B,mB,nB,"matran-B.txt");

    //Dua ra ma tran A,B
    cout<<"Ma tran A:\n";
    duaRaMT(A,mA,nA);
    cout<<"\n\nMa tran B:\n";
    duaRaMT(B,mB,nB);
    
    //Cong ma tran
    if(mA==mB && nA==nB)
    {
	C = congMT(A,B,mA,nA);
	cout<<"\n\nMa tran C = A + B:\n";
	duaRaMT(C,mA,nA);

	//Ghi ma tran tong ra tep
	ofstream fout("kq-thctdlgtbai05.txt");
	
	fout<<mA<<" "<<nA<<endl;

	for(int i=1;i<=mA;i++)
	{
	    //Ghi hang i ra tep
	    for(int j=1;j<=nA;j++)
	    {
		int k=(i-1)*nA+j-1;
		fout.width(6);fout<<C[k];
	    }

	    //Xuong dong
	    fout<<endl;
	}

	cout<<"\n\nDa ghi ma tran tong C ra tep kq-thctdlgtbai05.txt";
    }
    else cout<<"Hai ma tran khong cung kich thuoc, khong cong duoc.";

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void docVaoMT(int* &V,int &m,int &n,const char *tenTep)
{
    //Khai bao tep vao
    ifstream fin(tenTep);

    //Doc kich thuoc ma tran vao m,n
    fin>>m>>n;

    //Tao mang do lam vector luu tru cho mang 2 chieu chua ma tran
    V = new int[m*n];

    //Doc vao ma tran vao vector luu tru V cua mang 2 chieu
    for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
	    int k = (i-1)*n + j - 1;
	    fin>>V[k];
	}
}

void duaRaMT(int *V,int m,int n)
{
    for(int i=1;i<=m;i++)
    {
	//Dua ra hang i
	for(int j=1;j<=n;j++)
	{
	    int k=(i-1)*n+j-1;
	    printf("%6d",V[k]);
	}
	
	//Xuong dong
	cout<<endl;
    }
}

int* congMT(int *V1,int *V2,int m,int n)
{
    //Tao mang dong lam vector luu tru chua ma tran tong
    int *V3 = new int[m*n];
    
    //Cong 2 ma tran
    for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
	    int k=(i-1)*n+j-1;
	    V3[k] = V1[k] + V2[k];
	}

    //Tra ve ma tran tong
    return V3;
}