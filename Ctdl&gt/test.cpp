#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *arr, int n);

int main()
{
    int n;
    ifstream fin("daykhoa-kt.txt");
    fin >> n;
    int *arr=new int[n];
    cout << "Day khoa ban dau la: \n";
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
        cout << arr[i] << setw(5);
    }
    selectionSort(arr,n);
    cout << "\nDay khoa sau khi sap xep giam dan la: \n";
    for (int i = 0; i < n; i++)
    
        cout << arr[i] << setw(5);
    cout << endl;
    return 0;
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        if (max!=i)
        {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }     
    }
}