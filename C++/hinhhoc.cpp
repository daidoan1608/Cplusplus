#include <bits/stdc++.h>
using namespace std;

bool nguyento(int a)
{
    if (a<=1)
    {
        return false;
    }
    else if (a==2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i < a; i++)
        {
            if (a%i==0)
            {
                return false;
            }
        }
    }
}

int main()
{   
    unsigned long long n;
    cin >> n;
    int so_du=0;
    int dem=0;
    while(n!=0)
    {
        so_du=n%10;
        if(nguyento(so_du)==true)
        {
            dem++;
        }   
        n=n/10;
    }
    cout << dem << endl;
    return 0;
}