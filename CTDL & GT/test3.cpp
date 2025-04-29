#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void bubbleSort(int *arr, int n);

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
        cout << arr[i] << "   ";
    }
    bubbleSort(arr,n);
    cout << "\nDay khoa sau khi sap xep giam dan la: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "   ";
    cout << endl;
    return 0;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n-1 ; j > i; j--)
        {
            if (arr[j] > arr[j - 1]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}