//Ho ten: Le Tuan Tu
//MaSV: 672234
//Lop: K67CNTTA
//De: Bài tập áp dụng về mẫu lớp
/*
Ứng dụng ngăn xếp lưu trữ kế tiếp chuyển số nguyên dương
hệ 10 sang hệ 2 và 16. Yêu cầu sử dụng mẫu lớp
trong cài đặt.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao mau lop doi tuong ngan xep
template <class Type>
class Stack
{
	private:
		enum {size=32};
		Type S[size];
		int T;
	
	public:
		Stack();
		void push(Type x);
		Type pop();
		bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
	//Tao 1 doi tuong ngan xep co phan tu la so nguyen
	Stack<int> s1;
	//Tao 1 doi tuong ngan xep co phan tu la ky tu
	Stack<char> s2;
	
	//Khai bao bien
	int n,thuong,du;
	
	cout<<"Chuong trinh chuyen so nguyen duong n sang so nhi phan va so hex";
	cout<<"\n\nNhap vao so nguyen duong n= ";
	cin>>n;
	
	//Chuyen n sang he 2
	thuong=n;
	while(thuong)
	{
		du = thuong%2;
		thuong /= 2;
		s1.push(du);
	}
	
	cout<<"So nhi phan cua "<<n<<" la: ";
	while(!s1.isEmpty()) cout<<s1.pop();

	//Chuyen n sang he 16
	thuong=n;
	while(thuong)
	{
		du = thuong%16;
		thuong /= 16;
		
		if(du<10) s2.push(du+48);
		else s2.push(du+55);
	}
	
	cout<<"\nSo hex cua "<<n<<" la: ";
	while(!s2.isEmpty()) cout<<s2.pop();
	
	cout<<endl;
	return 0;
}
//===dinh nghia ham===
template <class Type>
Stack<Type>::Stack():T(-1)
{
	
}

template <class Type>
void Stack<Type>::push(Type x)
{
	//1.Kiem tra ngan xep day
	if(T==size-1)
	{
		cout<<"Ngan xep da day!";
		return;
	}
	
	//2-3.Tang T len 1 va dua x vao ngan xep tai vi tri T
	S[++T] = x;
}

template <class Type>
Type Stack<Type>::pop()
{
	//1.Kiem tra ngan xep rong
	if(T==-1)
	{
		Type tg;
		cout<<"Ngan xep da rong!";
		return tg;
	}
	
	//2-3-4.Tra ve phan tu dinh va giam T di 1
	return S[T--];
}

template <class Type>
bool Stack<Type>::isEmpty()
{
	return T==-1;
}