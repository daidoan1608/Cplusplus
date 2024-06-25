//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Sử dụng danh sách liên kết đơn P để lưu trữ dãy số nguyên
theo thứ tự đọc vào từ tệp văn bản "daysonguyen-bai33.txt", trên tệp không có thông tin
về số phần tử của dãy số. Tạo danh sách liên kết đơn Q bao gồm các phần tử dữ liệu của P
nhưng theo thứ tự đảo ngược. Xóa một nút trên DSLK đơn P mà có phần tử dữ liệu bằng
x nhập vào từ bàn phím. Đưa ra màn hình dãy số nguyên trong danh sách liên kết đơn.
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng ma trận
class DSLKD{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F;
    public:
        DSLKD();
        ~DSLKD();
        void postInsert(int x);
        void preInsert(int x);
        bool remove(int x);
        void display();
};
//===Chương trình chính===
int main(){
    DSLKD P,Q;
    int x;
    ifstream fin("daysonguyen-bai33.txt");
    while (fin >> x)
    {
        P.postInsert(x);
        Q.preInsert(x);
    }
    cout << "Danh sach lien ket don P:" << endl;
    P.display();

    cout << "Nhap gia tri can xoa: ";
    cin >> x;
    P.remove(x);

    cout << "Danh sach lien ket don P sau khi xoa phan tu " << x << ":" << endl;
    P.display();

    cout << "Danh sach lien ket don Q (dao nguoc):" << endl;
    Q.display();
    cout << endl;
    
    cout << endl;
    return 0;
}
//===Khai báo hàm===
DSLKD::DSLKD():F(NULL){
}
DSLKD::~DSLKD(){
    node *P;
    while (F != NULL)
    {
        P = F;
        F = F->link;
        delete P;
    }
}
void DSLKD::preInsert(int x){
    node *N = new node;
    N->infor = x;
    N->link = F;
    N->link = F;
    F = N;
}
void DSLKD::postInsert(int x){
    node *N = new node;
    N->infor = x;
    N->link = NULL;
    if (F==NULL) F = N;
    else
    {
        node *P = F;
        while (P->link != NULL)
            P = P->link;
        P->link = N;
    }
}
bool DSLKD::remove(int x) {
    if (F == NULL) {
        return -1;
    }
    node *P = F, *Q = NULL;
    while (P != NULL) {
        if (P->infor == x) {
            if (Q == NULL) {
                F = P->link;
            } else {
                Q->link = P->link;
            }
            delete P;
            return x;
        }
        Q = P;
        P = P->link;
    }
    return -1;
}
void DSLKD::display()
{
    node *P = F;
    while (P != NULL)
    {
        printf("%d\n", P->infor);
        P = P->link;
    }
}
