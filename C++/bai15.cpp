#include <iostream>
using namespace std;

int main()
{
    int n;
    int giaithua=1;
    cout << "Nhap vao N=";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        giaithua=giaithua*i;
    }
    cout << "N!=" << giaithua;
}