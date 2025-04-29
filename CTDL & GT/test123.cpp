#include <iostream>
#include <fstream>
#include <iomanip> // Để định dạng xuất

using namespace std;

struct thiSinh
{
    char soBaoDanh[10];
    float diemThi;
};

void SLPostInsert(thiSinh *&arr, int &n, thiSinh thongTin);
void SLDelete(thiSinh *&arr, int &n, int index);
void SLDisplay(thiSinh *arr, int n);
int SLSearch(thiSinh *arr, int n, char *soBaoDanh);

int main()
{

    return 0;
}

void SLPostInsert(thiSinh *&arr, int &n, thiSinh thongTin)
{
    // Cấp phát lại mảng với kích thước tăng thêm 1
    thiSinh *newArr = new thiSinh[n + 1];
    for (int i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[n] = thongTin;
    n++;

    // Giải phóng mảng cũ và cập nhật con trỏ
    delete[] arr;
    arr = newArr;
}

void SLDelete(thiSinh *&arr, int &n, int index)
{
    if (index < 0 || index >= n)
    {
        cout << "Chi so khong hop le!\n";
        return;
    }

    // Cấp phát lại mảng với kích thước giảm đi 1
    thiSinh *newArr = new thiSinh[n - 1];
    for (int i = 0, j = 0; i < n; i++)
    {
        if (i != index)
        {
            newArr[j++] = arr[i];
        }
    }
    n--;

    // Giải phóng mảng cũ và cập nhật con trỏ
    delete[] arr;
    arr = newArr;
}

void SLDisplay(thiSinh *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Thi sinh " << i + 1 << ":\n";
        cout << "  So bao danh: " << arr[i].soBaoDanh << endl;
        cout << "  Diem thi: " << fixed << setprecision(2) << arr[i].diemThi << endl;
    }
}

int SLSearch(thiSinh *arr, int n, char *soBaoDanh)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].soBaoDanh, soBaoDanh) == 0)
        {
            return i;
        }
    }
    return -1;
}
