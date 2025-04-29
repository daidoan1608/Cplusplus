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
class Queue
{
	private:
		enum {size=32};
		Type Q[size];
		int F,R;
	
	public:
		Queue();
		void insert(Type x);
		Type remove();
		bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
	Queue<int> Q1,Q2;

	
	cout<<endl;
	return 0;
}
//===dinh nghia ham===
template <class Type>
Queue<Type>::Queue():F(-1),R(-1)
{
	
}

template <class Type>
void Queue<Type>::insert(Type x)
{
	//1.Kiem tra ngan xep day
	if(F==0 && R==size-1 || F==R+1)
	{
		cout<<"Ngan xep da day!";
		return;
	}
	if (R==-1)
		F=R=0;
	else if(R==size-1)
		R=0;
	else
		R++;

	Q[R] = x;
}

template <class Type>
Type Queue<Type>::remove()
{
	Type tg;
	if(F==-1)
	{
		cout<<"Ngan xep da rong!";
		return tg;
	}
	tg = Q[F];
	if (F==R)
		F=R=-1;
	else if (F==size-1)
		F=0;
	else
		F++;

	return tg;
}

template <class Type>
bool Queue<Type>::isEmpty()
{
	return F==-1;
}