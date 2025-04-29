#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *arr, int n);
void selectionSort(int *arr, int n);
void quickSort(int *arr, int l, int r);
void bubbleSort(int *arr, int n);
void heapSort(int *arr, int n);
void adjust(int *arr, int i, int n);
void mergeSort(int *a, int n);
void MPass(int *X, int *Y, int n, int L);
void merge(int *X, int b, int m, int n, int *Z);

int main()
{

    while (true)
    {
        int a[10] = {12, 13, 20, 26, 89, 60, 57, 22, 10, 78};
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertionSort(a, sizeof(a) / sizeof(a[0]));
            break;
        case 2:
            selectionSort(a, sizeof(a) / sizeof(a[0]));
            break;
        case 3:
            quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
            break;
        case 4:
            bubbleSort(a, sizeof(a) / sizeof(a[0]));
            break;
        case 5:
            heapSort(a, sizeof(a) / sizeof(a[0]));
            break;
        case 6:
            mergeSort(a, sizeof(a) / sizeof(a[0]));
            break;
        default:
            break;
        }
        for (int i = 0; i < 10; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

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
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void quickSort(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r, k = (l + r) / 2;
    int x = arr[k];
    do
    {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i != j);
    quickSort(arr, l, j - 1);
    quickSort(arr, j + 1, r);
    return;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
void adjust(int *arr, int i, int n)
{
    int key = arr[i];
    int j = 2 * i + 1;
    while (j < n)
    {
        if ((j < n - 1) && (arr[j] < arr[j + 1]))
            j++;
        if (key >= arr[j])
            break;
        arr[i] = arr[j];
        i = j;
        j = 2 * i + 1;
    }
    arr[i] = key;
    return;
}
void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        adjust(arr, i, n);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        adjust(arr, 0, i);
    }
    return;
}

void merge(int *X, int b, int m, int n, int *Z)
{
    int i = b;
    int j = m + 1;
    int k = b;
    while (i <= m && j <= n)
    {
        if (X[i] <= X[j])
        {
            Z[k] = X[i];
            i++;
        }
        else
        {
            Z[k] = X[j];
            j++;
        }
        k++;
    }
    if (i > m)
    {
        for (int t = 0; t <= n - j; t++)
        {
            Z[k + t] = X[j + t];
        }
    }
    else
    {
        for (int t = 0; t <= m - i; t++)
        {
            Z[k + t] = X[i + t];
        }
    }
}

void MPass(int *X, int *Y, int n, int L)
{
    int i = 0;
    while (i + 2 * L - 1 < n)
    {
        merge(X, i, i + L - 1, i + 2 * L - 1, Y);
        i += 2 * L;
    }
    if (i + L - 1 < n)
    {
        merge(X, i, i + L - 1, n - 1, Y);
    }
    else
    {
        for (int j = i; j < n; j++)
        {
            Y[j] = X[j];
        }
    }
}

void mergeSort(int *a, int n)
{
    int *b = new int[n];
    int L = 1;
    while (L < n)
    {
        MPass(a, b, n, L);
        L = L * 2;
        MPass(b, a, n, L);
        L = L * 2;
    }
    delete[] b;
}