#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ho_ten;
    int i=0,j;
    char c;
    cout << "Nhap vao ho ten:";
    getline(cin, ho_ten); //Ham nhap vao chuoi ky tu chua khoang trong
    /*do
    {
        c=ho_ten[i]; //gán c bằng vị trí thứ i trong xâu
        i++;
    } while (c!=' '); //nếu c là khoảng trắng in ra giá trị của i
        cout << "i=" << i << endl;
        cout <<"Ho la:" << ho_ten.substr(0,i-1) << endl; //hàm lấy số ký tự từ vị trí 0, số ký tự lấy ra là i-1 
    j=ho_ten.length()-1;
    do
    {
        c=ho_ten[j];
        j--;
    } while (c!=' ');
        cout <<"Ten la:" << ho_ten.substr(j+2) << endl;
        cout <<"Ten dem la:" << ho_ten.substr(i,j-i+1);*/
    stringstream ss(ho_ten);
    string temp;
    while (ss >> temp)
    {
        cout << temp << endl;
    }
    
    return 0;
}