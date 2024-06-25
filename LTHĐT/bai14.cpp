#include <iostream>
#include <stdio.h>

using namespace std;
// Khai bao lop doi tuong danh sach lien ket kep (DSLKK)
class DList{
private:
    struct node
    {
        int infor;
        node *left, *right;
    } *L, *R;
public:
    DList();
    ~DList();
    void lastInsert(int x);
    bool remove(int x);
    void display();
};
//===chuong trinh chinh===
int main(){
    DList list;
    int n,x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        list.lastInsert(x);
    }
    list.display();
    cout << endl;
    return 0;
}
//===dinh nghia ham===
DList::DList() : L(NULL), R(NULL){}
DList::~DList(){
    while (L)
    {
        node *P = L;
        L = L->right;
        delete P;
    }
}
void DList::lastInsert(int x){
    // Tao nut nho mo de chua x
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    // Noi nut moi vao cuoi DSLKK (sau R)
    if (R == NULL)
        L = R = N;
    else{
        R->right = N;
        N->left = R;
        R = N;
    }
}
void DList::display(){
    node *P = L;
    while (P){
        cout << P->infor;
        // Cho P tro sang nut tiep theo
        P = P->right;
    }
}