// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:

#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int infor;
    struct Node *left;
    struct Node *right;
} Node;

Node *makeNode(int x);
void DLpreInsert(Node **F, Node **M, int x);
void DLDelete(Node **F, Node **M);
void SLDisplay(Node **F);
void SLConcat(Node **P, Node **Q);

int main()
{
    Node *L = NULL;
    Node *R = NULL;

    cout << endl;
    return 0;
}

Node *makeNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->infor = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void DLpreInsert(Node **L, Node **R, Node **M ,int x)
{
    Node *N = makeNode(x);
    if (*L == NULL && *R == NULL)
    {
        *L = N;
        *R = N;
    }
    else if (*M == *L)
    {
        N->right = *M;
        (*M)->left = N;
        *L = N;
    }
    else
    {

        ((*M)->left)->right = N;
        N->left = (*M)->left;
        N->right = *M;
        (*M)->left = N;
    }
}

void DLDelete(Node **L, Node **R, Node **M)
{
    if (*L == NULL && *R == NULL)
    {
        printf("Danh sach rong");
        return;
    }

    if (*L == *M && *R == *M)
    {
        *L = NULL;
        *R = NULL;
    }
    else if (*M == *L)
    {
        *L = (*L)->right;
        (*L)->left = NULL;
    }
    else if (*M == *R)
    {
        *R = (*R)->left;
        (*R)->right = NULL;
    }
    else
    {
        ((*M)->right)->left = (*M)->right;
        ((*M)->left)->right = (*M)->left;
    }
    free(M);
}

void SLDisplay(Node *L, Node *R)
{
    Node *P = L;
    while (P != NULL)
    {
        printf("%d", P->infor);
        P = P->right;
    }
    printf("/n");
}
