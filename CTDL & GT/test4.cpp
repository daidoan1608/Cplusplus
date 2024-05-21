#include<iostream>
#include<fstream>

using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
};

node* BST(node*& T, int x);

int main()
{
    int n, x;
    node* T = NULL;

    ifstream fin("daykhoa.txt");
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> x;
        BST(T, x);
    }

    cout << "Nhap vao khoa muon tim kiem x = ";
    cin >> x;

    node* result = BST(T, x);

    if (result)
        cout << "Tim thay " << x << endl;
    else
        cout << "Khong tim thay " << x << endl;

    return 0;
}

node* BST(node*& T, int x)
{
    node* P = NULL;
    node* Q = T;

    while (Q != NULL)
    {
        if (x < Q->key)
        {
            P = Q;
            Q = Q->left;
        }
        else if (x == Q->key)
        {
            cout << "Tim thay " << x << endl;
            return Q;
        }
        else
        {
            P = Q;
            Q = Q->right;
        }
    }

    node* newNode = new node;
    newNode->key = x;
    newNode->left = newNode->right = NULL;

    if (T == NULL)
        T = newNode;
    else if (x < P->key)
        P->left = newNode;
    else
        P->right = newNode;

    cout << "Da them " << x << endl;
    return newNode;
}
