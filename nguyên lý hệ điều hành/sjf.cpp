#include <bits/stdc++.h>
#include <climits>// Để sử dụng giá trị INT_MAX

using namespace std;

struct Process
{
    int burstTime;
    int arrivalTime;
};


void sfjScheduling(Process *processes,int sum_burstTime,int n)
{
    int smallest , i, time=0;
    int sum_turnaround = 0, waitTime = 0;
    int *waitTimes = new int[n];
    processes[-1].burstTime = INT_MAX; // Sử dụng giá trị INT_MAX để thể hiện giá trị lớn nhất cho burst time

    
    for (; time < sum_burstTime;)
    {
        smallest = -1;
        //Duyệt mảng để tìm ra chỉ số của tiến trình bằng cách so sánh thời gian đến của tiến trình với thời gian cpu đã chạy và thời gian
        //thực hiện của tiến trình có phải là nhỏ nhất hay ko
        for (i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= time && processes[i].burstTime > 0 && processes[i].burstTime < processes[smallest].burstTime)
                smallest = i;
        }
        //Nếu ko tìm thấy tiến trình nào phù hợp thì tăng thời gian đã chạy của cpu lên
        if (smallest == -1) {
            time++;
            continue;
        }
        waitTimes[smallest + 1] = time - processes[smallest].arrivalTime;//Thời gian chờ của tiến trình đang thưc hiện đưa vào mảng để xuất ra màn hình


        cout << "|" << time << ".....P[" << smallest + 1 << "]....." ;

        sum_turnaround += time + processes[smallest].burstTime - processes[smallest].arrivalTime;//thời gian xử lý xong tiến trình từ lúc đến đến lúc kết thúc
        waitTime += waitTimes[smallest + 1]; //Thời gian chờ của tiến trình đang thưc hiện
        time += processes[smallest].burstTime; //Thời điểm kết thúc của tiến trình đã thực hiện = thời gian cpu đã chạy
        cout << time;
        processes[smallest].burstTime = 0;
    }
    cout << "|";
    for (int i = 1; i <= n; i++)
    {
        cout << "\nThoi gian cho cua P[" << i << "] la: " << waitTimes[i] << endl;
    }
    
    cout << "\n\nThoi gian cho trung binh la = " <<  static_cast<float>(waitTime) / n << "\n" << endl;
};

int main() {
    int sum_burstTime = 0;
    int n;
    cout << "Nhap vao so tien trinh can lap lich: ";
    cin >> n;
    Process *processes =new Process[n];

    for (int i = 0; i < n; i++)
    {   
        cout << "Nhap vao thoi gian den cua tien trinh P" << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Nhap vao thoi gian thuc hien cua tien trinh P" << i + 1 << ": ";
        cin >> processes[i].burstTime;
        sum_burstTime += processes[i].burstTime;
    }
    sfjScheduling(processes,sum_burstTime,n);
    return 0;
}
