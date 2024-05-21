#include <iostream>
using namespace std;

int main()
{
    int thang;
    int nam;
    cout << "Nhap vao thang , nam" << " ";
    cin >> thang >> nam;
    switch (thang)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        cout << "Thang co 31 ngay";
        break;
    case 4:case 6:case 9:case 11:
        cout << "Thang co 30 ngay";
        break;
    case 2:
        if ((nam%4==0) && (nam%100!=0) || (nam%400==0))
        {
            cout << "Thang co 29 ngay";
        }
        else
            cout << "Thang co 28 ngay";
        break;
    default:
        cout << "Nhap sai thang nam";
        break;
    }
    return 0;
}