// kiểm tra các số nguyên tố từ 1 đến n
#include <iostream>
#include <math.h>
using namespace std;

bool nguyento(int a)
{
    if (a<1)
    {
        return false;
    }
    else if(a=2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i <= sqrt(a) ; i++)
        {
            if(a % i == 0)
            return false;
        }
    }
    return a > 1;
}

int main()
{
    int n;
    cout << "Nhap vao n=";
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        if (nguyento(i))
        {
            cout << i << endl;
        }
    }
    return 0;
   /*bool co;
    int n;
    cout << "Nhap vao n=";
    cin >> n; 
    for (int i = 1; i <= n; i++)
    {
        if (i>1)
        {
            co = true;
            for (int j = 2; j < i; j++)           
            {
                if (i%j==0)
                {
                    co =false;
                    break;
                }
                
            }
        }
        else
        {
            co = false;
        }
        if (co)
        {
            cout << i << " ";
        }
    }
    return 0;*/
}