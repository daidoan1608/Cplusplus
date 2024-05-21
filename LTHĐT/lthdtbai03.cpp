//Ho ten: Doan Minh Dai
//Ma SV: 671259
//Lop: K67CNTTA
//De:Cho tệp văn bản chứa dãy số nguyên dương a1,a2,a3...,an. Đọc vào dãy số, đưa các số lẻ về đầu dãy, các số chẵn về cuối dãy. Ghi dãy số sau khi thay đổi ra tệp "ketqua-lthdtbai03.txt". Y/c sử dụng mạng động chứa dãy số.
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>

using namespace std;
//===Khai báo hàm===

//===Chương trình chính===
int main()
{
    int *a, n;
    ifstream fin("dayso.txt");
    fin >> n;
    a = new int[n];
    for(int i=0; i<n; i++)
        fin >> a[i];
    fin.close();
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            for (int j = i; j < n; j++)
            {
                if (a[j] % 2 != 0)
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    break;
                }
            }
        }
    }
    ofstream fout("ketqua-lthdtbai03.txt");
    for(int i=0; i<n; i++)
        fout << a[i] << " ";
    fout.close();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
//===Định nghĩa hàm===