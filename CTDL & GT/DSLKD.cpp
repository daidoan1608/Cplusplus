// Ho ten: Đoàn Minh Đại
// MaSV: 671259
// Lop: K67CNTTA
// De:

#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int infor;
    struct Node *link;
} Node;

Node *makeNode(int x);
void SLPostInsert(Node **F, Node **M, int x);
void SLPreInsert(Node **F, Node **M, int x);
void SLDelete(Node **F, Node **M);
void SLDisplay(Node **F);
void SLConcat(Node **P, Node **Q);

int main()
{
    Node *F = NULL;

    cout << endl;
    return 0;
}

Node *makeNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->infor = x;
    newNode->link = NULL;
    return newNode;
}

void SLPostInsert(Node **F, Node *M, int x)
{
    Node *N = makeNode(x);
    if (*F == NULL)
        *F = N;
    else
    {
        N->link = M->link;
        M->link = N;
    }
}

void SLPreInsert(Node **F, Node **M, int x)
{
    Node *N = makeNode(x);
    if (*F == NULL)
        *F = N;
    else if (*M == *F)
    {
        N->link = *M;
        *F = N;
    }
    else
    {
        Node *P = *F;
        while (P->link != *M)
            P = P->link;
        P->link = N;
        N->link = *M;
    }
    return;
}

void SLDelete(Node **F, Node **M)
{
    if (*F == NULL)
    {
        printf("Danh sach rong");
        return;
    }

    if (*F == *M)
    {
        *F = (*F)->link;
        Node *P = *F;
        while (P->link != *M)
            P = P->link;
        P->link = (*M)->link;
    }
    free(M);
}

void SLDisplay(Node *F)
{
    Node *P = F;
    while (P != NULL)
    {
        printf("%d", P->infor);
        P = P->link;
    }
    printf("/n");
}

void SLConcat(Node **P, Node **Q)
{
    if (*Q == NULL)
        return;
    else if (*P == NULL)
    {
        *P = *Q;
    }
    else
    {
        Node *P1 = *P;
        while (P1->link != NULL)
            P1 = P1->link;
        P1->link = *Q;
    }
}