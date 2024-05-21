

#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *arr, int n);

int main()
{
    // Khai báo biến
    int *arr = new int;
    int n;

    //Đọc tệp
    ifstream fin("daykhoa-kt-de15bai1.txt");

    //Đọc số lượng phần tử
    fin >> n;

    //Đọc các phần tử trong tệp và đưa ra màn hình
    cout << "Day khoa ban dau la: ";
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
        cout << arr[i] << "   ";
    }
    cout << "\n" ;

    //Sắp xếp hàm và đưa ra màn hình
    selectionSort(arr,n);

    cout << "Day khoa sau khi sap xep la: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< "   " ;
    }
    cout << "\n";

    //Đóng tệp
    fin.close();

    cout << endl;
    return 0;
}
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[min])
                min = j;
        }
        if (min!=i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}