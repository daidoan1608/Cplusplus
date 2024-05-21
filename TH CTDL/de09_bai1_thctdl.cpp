#include <bits/stdc++.h>

using namespace std;

struct matHang
{
    char tenHang[50];
    int soLuong;
    int donGia; 
};
void selectionSort(matHang *arr, int n);


int main()
{
    int soLuongMatHang;
    ifstream fin("mathang.txt");
    fin >> soLuongMatHang;
    fin.ignore();
    matHang *list = new matHang[soLuongMatHang];

    for (int i = 0; i < soLuongMatHang; i++)
    {
        fin.getline(list[i].tenHang, sizeof(list[i].tenHang));
        fin >> list[i].soLuong >> list[i].donGia;
        fin.ignore();
    }
    cout << "Danh sach mat hang ban dau la:\n";
    cout << setw(20) << left << "Ten Hang"
         << setw(15) << right << "So Luong"
         << setw(15) << right << "Don Gia" << endl;
    for (int i = 0; i < soLuongMatHang; i++)
    {
        cout << setw(20) << left << list[i].tenHang
             << setw(15) << right << list[i].soLuong
             << setw(15) << right << list[i].donGia << endl;
    }
    cout << "\n\n\nDanh sach mat hang sau khi da sap xep la:\n";
    selectionSort(list,soLuongMatHang);
    for (int i = 0; i < soLuongMatHang; i++)
    {
        cout << setw(20) << left << list[i].tenHang
             << setw(15) << right << list[i].soLuong
             << setw(15) << right << list[i].donGia << endl;
    }
    cout << endl;
    return 0;
}

void selectionSort(matHang *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        
        {
            {
                if (arr[j].soLuong < arr[min].soLuong)
                    min = j;
            }
            if (min!=i)
            {    
                matHang temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
