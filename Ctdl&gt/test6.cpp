#include <iostream>

using namespace std;
void merge(int *X, int b,int m, int n,int *Z)
{
        int i = b;
        int j = m+1;
        int k = b;
        while(i <= m && j <=n)
        {
                if(X[i] <= X[j])
                {
                        Z[k] = X[i];
                        i++;
                }else{
                        Z[k] = X[j];
                        j++;
                }
                k++;
        }
        if( i > m )
        {
                for(int t = 0; t <= n-j;t++){
                        Z[k+t] =X[j+t];
                }
        }
        else{
                for(int t=0; t <=m-i;t++){
                        Z[k+t] = X[i+t];
                }
        }
}
void MPass(int *X,int *Y,int n, int L)
{
        int i = 0;
        while(i + 2*L -1 < n)
        {
                merge(X,i,i+L -1, i +2*L-1,Y);
                i+=2*L;
        }
        if(i+L-1 < n)
                merge(X,i,i+L-1,n-1,Y);
        else
        {       for(int j= i; j < n; j++)
                        Y[j] = X[j];

        }
}
void mergeSort(int *arr,int n)
{
        int *b = new int[n];
        int L = 1;
        while(L < n)
        {
                MPass(arr,b,n,L);
                L=L*2;
                MPass(b,arr,n,L);
                L=L*2;
        }
        delete[] b;
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}