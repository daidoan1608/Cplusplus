#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};
// Hàm thêm một phần tử x vào cây BST
Node* BST(Node* &T, int x) {
    Node *p = NULL;
    Node *q = T;

    while (q != NULL) {
        if (x < q->key) {
            p = q;
            q = q->left;
        } else if (x == q->key) {
            return q; // Phần tử đã tồn tại trong cây
        } else {
            p = q;
            q = q->right;
        }
    }

    // Tạo một nút mới để chứa phần tử x
    Node *newNode = new Node;
    newNode->key = x;
    newNode->left = newNode->right = NULL;

    // Nếu cây rỗng, gán nút mới làm gốc
    if (T == NULL) {
        T = newNode;
    } else {
        if (x < p->key) {
            p->left = newNode;
        } else {
            p->right = newNode;
        }
    }
    return NULL;
}
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    int n, x;
    Node* T = NULL;

    ifstream fin("daykhoa.txt");
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> x;
        BST(T, x);
    }

    cout << "Nhap vao khoa muon tim kiem x = ";
    cin >> x;

    Node* result = BST(T, x);

    if (result)
        cout << "Tim thay " << x << endl;
    else
        cout << "Khong tim thay " << x << endl;
    inOrderTraversal(T);
    return 0;
}