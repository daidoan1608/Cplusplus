#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
/*
Bài 13(thctdlgtbai13.cpp): Cài d?t và s? d?ng danh sách liên k?t don cho bài toán sau:
Ð?c danh sách sinh viên t? t?p van b?n 'sinhvien.txt' luu vào DSLKD, m?i sinh viên có thông tin
v? mã sinh viên, h? tên, l?p, di?m tbc. Xóa sinh viên có mã nh?p vào t? bàn phím.
Tìm và dua ra màn hình các sinh viên có di?m tbc >= 6.5.
*/
using namespace std;

//Khai bao cau truc sinh vien
struct sinhvien{
	//string masv;
	string masv;
	string hoten;
	string lop;
	float diemtbc;
};
typedef struct sinhvien SINHVIEN;

//khai bao cau truc sinh vien
struct node
{
	SINHVIEN data;
	struct node *pNext; //con tro dung de lien ket giua node và
	};
typedef struct node NODE;

//KHai bao danh sach lien ket don cua sinh vien===
struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

//hàm khoi tao DSLKD cac sinh vien
void khoiTaodanhsach(LIST &l){
		l.pHead = NULL;
		l.pTail = NULL;
	}

//hàm khoi tao mot node de them vao danh sach
NODE *khoiTaonode(SINHVIEN x){
		NODE *p = new NODE;
		if(p == NULL){
				cout<< "\nCap phat that bai!";
				return NULL;
			}
		p -> data = x; //dua du lieu sinh vien x và data cua node P
		p -> pNext = NULL;//khoi tao node p nhung node p chua có lien ket don
		
		return p;
	}
//Ham them 1 node sinh vien vao dau danh sach
void ThemDau(LIST &l, NODE *p){
		//neu danh sach rong
		if(l.pHead == NULL){
				l.pHead = l.pTail = p;
			}else{
				p->pNext = l.pHead; //cho con tro den pHead
				l.pHead = p; //Cap nhat lai dau danh sach cua node p
			}	
			
	}
//ham them 1 node vao cuoi danh sach
void Themcuoi(LIST &l, NODE *p){
		//neu danh sach rong
		if(l.pHead == NULL){
				l.pHead = l.pTail = p; //node p them vao cung chinh là
			}	
		else {
				l.pTail->pNext = p;//conn tro cua pTail tro den node p
				l.pTail = p;//Cap nhat lai pTail chinh la node p
			}	
	}

//ham doc dul lieu sinh vien
void DocthongtinSV(ifstream &fin, SINHVIEN &sv){
		//doc ho ten sinh vien
		getline(fin >> ws, sv.masv, ',');
		//getline(fin, sv.masv,',');//doc den dau enter thì dung
		//fin >> sv.masv;
	//	fin.seekg(1,1);//bo khoang trang
		getline(fin, sv.hoten,',');
		getline(fin, sv.lop,',');
		//doc diem trung binh ko phai chuoi
		fin>>sv.diemtbc;
	}
//hàm doc danh sach sinh vien tu file
void DocdanhsachSV(ifstream &fin, LIST &l){
		while(!fin.eof() 	){ //!fin.eof() && sv.diemtbc >= 6.5
			//Doc thong tin sv
			SINHVIEN sv;
			DocthongtinSV(fin,sv);
			//tao khoi tao 1 node sinh vien
			NODE *p = khoiTaonode(sv);
			//them sinh vien(them node p) vao danh sach LKD
			Themcuoi(l,p);
			}
	}
	
//ham xuat  du lieu
void xuat(SINHVIEN sv){
		cout<<"\nMa sinh vien: "<< sv.masv;
		cout<<"\nHo ten: "<< sv.hoten;
		cout<<"\nLop sinh vien: "<< sv.lop;
		cout<<"\nDiem trung binh cong: "<< sv.diemtbc;
		
		cout<<"\n";
	}
//hàm xuat danh sach sinh vien
void xuatDSSV(LIST l,SINHVIEN &sv){
	int i=1;
		float a = l.pHead ->data.diemtbc;
		//BUoc 1
		for(NODE *k = l.pHead; k != NULL; k = k->pNext){
			if( k-> data.diemtbc >= 0 ){
				a = k->data.diemtbc;
				cout<<"\n\n\t SINH VIEN THU " << i;;
				xuat(k->data);//k là NODE; data là sinh vien
				}
				i++;
			}
			cout<<"\n"<<endl;
	}

// Hàm tìm sinh viên có mã nh?p vào
// NODE* TimSinhVien(LIST l, string masv) {
//   NODE* p = l.pHead;
//   while (p) {
//     if (p->data.masv == masv) {
//     	p = p->pNext;
//     }
//    return p;
//   }
 
// }
NODE* TimSinhVien(LIST l, string masv) {
  NODE* p = l.pHead;
  while (p) {
    if (p->data.masv == masv) {
    	return p; //= p->pNext;
    }
	p=p->pNext;
  }
   return NULL;
 
}

// Hàm xóa sinh viên có mã nh?p vào
// void XoaSinhVien(LIST l, string masv) {
//   NODE* p = l.pHead -> pNext;
//   if (p->data.masv == masv) {
//     p = p->pNext;
//     delete p;
//     return;
//   }
//   NODE* prev = p;
//   p = p->pNext;
//   while (p) {
//     if (p->data.masv == masv) {
//     	p = p->pNext;
//     	prev = p;
//     //	p = p->pNext;
//       	prev->pNext = p->pNext;
//       	delete prev;
     
//     }
   	
//     return;
  
//   }
// }
void XoaSinhVien(LIST& l, string masv) {
    if (l.pHead == NULL) {
        return;
    }

    NODE* p = l.pHead;
    if (p->data.masv == masv) {
        l.pHead = l.pHead->pNext;
        delete p;
        return;
    }

    NODE* prev = p;
    p = p->pNext;

    while (p) {
        if (p->data.masv == masv) {
            prev->pNext = p->pNext;
            delete p;
            return;
        }
        prev = p;
        p = p->pNext;
    }
}

//hàm xuat danh sach sinh vien sau khi xoa
void xuatDSSV_xoa(LIST l,SINHVIEN &sv){
		float a = l.pHead ->data.diemtbc;
		//BUoc 1
		for(NODE *k = l.pHead; k != NULL; k = k->pNext){
			if( k-> data.diemtbc >=6.5 ){
				a = k->data.diemtbc;
			//	cout<<"\n\n\t SINH VIEN THU ", ;
				xuat(k->data);//k là NODE; data là sinh vien
				}
			}
			cout<<"\n"<<endl;
	}
	
int main()
{
	//khai bao bien
		string masv;
		SINHVIEN sv;
		LIST l;
	//	char M;
		NODE *M;
		khoiTaodanhsach(l);
		
		//mo file
		ifstream fin;
		fin.open("sinhvien3.txt",ios::in);
		
		//doc danh sach sinh vien tu file
		DocdanhsachSV(fin,l);
		
		//xuat danh sach sinh vien 
		xuatDSSV(l,sv);
	
		
		//xoa sinh vien nhap tu ban phim
		cout << "Nhap ma sinh vien muon xoa: ";
		cin >> masv;
  		//getline(cin >> ws, masv);
		//cin.ignore();
		//cin >> sv.masv;
  		
  		M=	TimSinhVien(l,masv);
  		if(M){
  			//xóa
			XoaSinhVien(l,masv); 
			//Duyet danh sach sinh vien sau khi xoa
			cout<<"\nDanhs sach sinh vien sau khi xoa"<<masv<<"\n";
			//xuatDSSV_xoa(l,sv);
			xuatDSSV(l,sv);
			}
		else{
			cout<<"\nKhong co ma sinh vien!"<<masv<<"\n";
		}
		//dong file
		fin.close();
		system("pause");
		return 0;
	}

