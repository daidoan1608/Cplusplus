#include <bits/stdc++.h>

using namespace std;

// Kiểm tra xem có thể cấp phát tài nguyên cho tiến trình i hay không
bool canAllocate(int i, int **need, int *work, int m)
{
    for (int j = 0; j < m; ++j)
        if (need[i][j] > work[j]) 
            return false;
    return true;
}

//Tính tài nguyên còn lại sau khi đã cấp phát cho các tiến trình một mức nào đó
void allocateResources(int i, int **allocation, int **need, int *work, int m)
{
    for (int j = 0; j < m; ++j)
    {
        work[j] += allocation[i][j];
        need[i][j] = 0;
    }
}

// Giải thuật Banker
void bankerAlgorithm(int **allocation, int **max, int *available, int n, int m)
{
    int **need = new int *[n];//Khai báo biến mảng 2 chiều need(Số lượng mỗi loại tài nguyên mỗi tiến trình cần để hoàn thành)
    for (int i = 0; i < n; ++i)
        need[i] = new int[m];

    // Tính ma trận Need
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            need[i][j] = max[i][j] - allocation[i][j];

    
    int *finish = new int[n];
    fill(finish, finish + n, false);//thiết lập tất cả các phần tử của vector finish bằng false

    int count = 0; //Số tiến trình đã hoàn thành
    int *work = new int[m];

    copy(available, available + m, work);//copy toàn bộ các giá trị trong vector available vào vector work
    cout << "P";

    for (int j = 0; j < m; ++j)//Tính lượng tài nguyên còn lại của mỗi loại tài nguyên
    {
        for (int i = 0; i < n; i++)
            work[j]-=allocation[i][j];

        cout << setw(8) << right << "TN" << j+1;
    }
    cout << endl;

    while (count < n)
    {
        bool found = false;

        for (int i = 0; i < n; ++i)

            if (!finish[i] && canAllocate(i, need, work, m))
            {
                allocateResources(i, allocation, need, work, m);
                finish[i] = true;
                found = true;
                ++count;

                //In ra số lượng tài nguyên còn lại sau mỗi khi thực hiện xong 1 tiến trình
                cout << i ;
                for (int j = 0; j < m; j++)
                    cout << setw(9) << right << work[j] ;
                cout << endl;
            }
    
        if (!found)
        {
            // Không tìm thấy tiến trình nào có thể cấp phát tài nguyên
            cout << "\nHe thong khong an toan, co tien trinh yeu cau so luong tai nguyen vuot muc." << endl;
            return;
        }
    }

    // Nếu tất cả tiến trình đều hoàn thành
    cout << "\nHe thong an toan, cac tien trinh deu duoc cung cap du tai nguyen." << endl;
    return;
}

int main() {
    int n, m;

    cout << "Nhap vao so luong tien trinh (n): ";
    cin >> n;

    cout << "Nhap vao so loai tai nguyen (m): ";
    cin >> m;

    int **allocation = new int *[n]; //Khai báo biến mảng 2 chiều allocation(Lượng tài nguyên đã phân phối của mỗi loại tài nguyên cho mỗi tiến trình)
    int **max = new int *[n]; //Khai báo biến mảng 2 chiều max(Lượng tài nguyên yêu cầu của mỗi loại tài nguyên cho mỗi tiến trình)

    for (int i = 0; i < n; ++i)
    {
        allocation[i] = new int[m];
        max[i] = new int[m];
    }

    int *available = new int[m];

    cout << "Nhap vao ma tran Allocation: " << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> allocation[i][j];

    cout << "Nhap vao ma tran Max: " << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> max[i][j];


    cout << "Nhap vao vector Available: " << endl;
    for (int j = 0; j < m; ++j)
        cin >> available[j];

    // Kiểm tra hệ thống
    bankerAlgorithm(allocation, max, available, n, m);

    return 0;
}