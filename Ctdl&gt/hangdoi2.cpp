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

Node *makeNode(int x);
void cQInsert(Node **F, Node **R, int x);
int cQDelete(Node **F, Node **R);
bool isEmpty(const Node *F, const Node *R);

int main()
{
    // Cai dat cau truc luu tru ke tiep cua ngan xep
    Node *F = NULL;
    Node *R = NULL;

    cout << endl;
    return 0;
}

void cQInsert(Node **F, Node **R, int x)
{
    Node *N = makeNode(x);
    if (isEmpty())
    {
        *F = N;
        *R = N;
    }
    else
        (*R)->link = N;
    *R = N;
}

int cQDelete(Node **F, Node **R)
{
    if (isEmpty(*F, *R))
    {
        printf("Hang doi rong.\n");
        return 1;
    }

    int tg = (*F)->infor;
    Node *P = *F;

    if (F == R)
    {
        F = NULL;
        R = NULL;
    }
    else
        *F = (*F)->link;

    free(P);
    return tg;
}

bool isEmpty(const Node *F, const Node *R)
{
    return ((F == NULL) && (R == NULL));
}

Node *makeNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->infor = x;
    newNode->link = NULL;
    return newNode;
}