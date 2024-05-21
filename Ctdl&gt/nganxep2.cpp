// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int infor;
    struct Node *link;
};

typedef struct Node Node;

// Khai bao ham cai dat cac phep toan tren ngan xep
Node* makeNode(int x);
void push(Node **T,int x);
int pop(Node **T);
bool isEmpty(const Node *T);

//===chuong trinh chinh===
int main()
{
    // Cai dat cau truc luu tru ke tiep cua ngan xep
    Node *T=NULL;
    
    cout << endl;
    return 0;
}
//===dinh nghia ham===
void push(Node **T, int x)
{
    Node *N=makeNode(x);
    N->link= *T;
    *T=N;
}

int pop(Node **T)
{
    if (T==NULL)
    {
        printf("Ngan xep rong.\n");
        return 1;
    }
    int tg=(*T)->infor;
    Node *P=*T;
    *T=(*T)->link;
    free(P);
    return tg;
}

bool isEmpty(const Node **T)
{
    return T == NULL;
}

Node* makeNode(int x)
{
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->infor = x;
    newNode->link = NULL;
    return newNode;
}