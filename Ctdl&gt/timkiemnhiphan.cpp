#include <iostream>
using namespace std;

int binarySearch(int *arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Trả về vị trí của key trong mảng
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Trả về -1 nếu key không tồn tại trong mảng
}

int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Trả về vị trí của key trong mảng
        }
    }
    return -1; // Trả về -1 nếu key không tồn tại trong mảng
}

int main() {
    int n;
    cout << "Nhập số phần tử trong mảng: ";
    cin >> n;

    int arr[n];
    cout << "Nhập các phần tử của mảng theo thứ tự tăng dần:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Nhập phần tử cần tìm kiếm: ";
    cin >> key;

    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        cout << "Phần tử " << key << " được tìm thấy tại vị trí " << index << ".\n";
    } else {
        cout << "Không tìm thấy phần tử " << key << " trong mảng.\n";
    }

    return 0;
}
