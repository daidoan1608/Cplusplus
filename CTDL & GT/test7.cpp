#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void selectionSort(int *arr, int n);

int main()
{
    int n;
    ifstream fin("daykhoa-kt.txt");
    fin >> n;

    int *arr = new int[n];
    cout << "Day khoa ban dau la: \n";
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
        cout << arr[i] << "   ";
    }

    selectionSort(arr, n);

    cout << "\nDay khoa sau khi sap xep tang dan la: \n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

    cout << endl;
    return 0;
}

// Cài đặt hàm sắp xếp chọn
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
