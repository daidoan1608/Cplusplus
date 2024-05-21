#include <iostream>
#include <string>
using namespace std;

int main()
{
    int number;
    string s="";
    cout << "Nhap vao so can doi sang he nhi phan:";
    cin >> number;
    do
    {
        if (number%2==1)
        {
            s="1"+s;
        }else
        {
            s="0"+s;
        }
        number=number/2;
    }
    while (number!=0);
    cout << s;
    return 0;
}