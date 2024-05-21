#include <iostream>
using namespace std;

int main()
{
    int arr[100] , n=0 , temp ;
    cout << "Nhap vao so phan tu cua mang n=";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao phan tu thu" << " " << i+1 << " ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j =i+1; j < n; j++)
        {
            if (arr[i]<arr[j])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu" << " " << i+1 << "la" << " " << arr[i];
    }
    return 0;
}