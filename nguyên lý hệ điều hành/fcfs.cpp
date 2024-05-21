#include <iostream>
#include <queue>

using namespace std;

//Tao biến cấu trúc tiến trình gồm có id và thời gian thực thi
struct Process{
    int id;
    int burstTime;
};

void fcfsScheduling(queue<Process>& processes, int n)
{

    float waitTime=0, totalTime=0;
    int *waitTimes = new int[n];
    int *ids = new int[n];
    int i=0;
    while (!processes.empty()) //Kiểm tra hàng đợi tiến trình có trống hay ko
    {
        Process currentProcess = processes.front();//Lấy ra tiến trình đến trước đưa vào tiến trình hiện tại
        processes.pop();//Xóa tiến trình đã lấy khỏi hàng đợi tiến trình
        waitTimes[i] = waitTime;
        ids[i] = currentProcess.id;
        i++;
        cout << waitTime << "|" << "   Process " << currentProcess.id << " ";
        for (int k = 0; k < currentProcess.burstTime; ++k)
            cout << ".";
        totalTime += waitTime;
        waitTime += currentProcess.burstTime;//Thoi gian cho cua tien trinh sau bằng thời gian chờ của tiến trình trước + thời gian thực hiên tiến trình trước
    }
    cout << "|" << waitTime << "\n" << endl;

    for (int j = 0; j < n; j++)
        cout << "Thoi gian cho doi cua tien trinh P" << ids[j] << " la: " <<  waitTimes[j] << endl;
    
    cout << "\nThoi gian cho doi trung binh cua cac tien trinh la: " << totalTime/n << endl;
}

int main()
{
    int n;
    queue<Process> processes;
    cout << "Nhap vao so luong tien trinh muon lap lich: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Process newProcess;
        cout << "Nhap vao id cua tien trinh thu " << i << ": ";
        cin >> newProcess.id;
        cout << "Nhap vao thoi gian su dung cua tien trinh thu" << i << ": ";
        cin >> newProcess.burstTime;
        processes.push(newProcess);//Đưa tiến trình vào hàng đợi
    }
    fcfsScheduling(processes, n);//Lập lịch những tiến trình đã nhập vào

    return 0;
}
