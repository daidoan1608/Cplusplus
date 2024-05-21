#include<bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int finishTime;
    int turnaroundTime;
    int waitTime;
    Process(int _id, int _arrivalTime, int _burstTime, int _remainingTime, int _finishTime, int _turnaroundTime, int _waitTime)
    : id(_id), arrivalTime(_arrivalTime), burstTime(_burstTime), remainingTime(_remainingTime),
      finishTime(_finishTime), turnaroundTime(_turnaroundTime), waitTime(_waitTime) {}

};

bool compareArrival(const Process& a, const Process& b) //Hàm so sánh thời gian đến
{
    return a.arrivalTime < b.arrivalTime;
};
int findMinProcess(vector<Process> processes,bool statusProcess[],int currentTime)
{
    int Min = INT_MAX;
    int index = -1;
    for (int i = 0; i < processes.size(); i++)
    {
        if ((statusProcess[i]) && (processes[i].remainingTime < Min) && (processes[i].arrivalTime <= currentTime))
        {
            Min = processes[i].remainingTime;
            index = i;
        }
    }
    return index;
};
void srtfScheduling(vector<Process> processes)
{
    int totalWaitTime = 0;
    int currentTime = 0;
    sort(processes.begin(),processes.end(),compareArrival);//Sắp xếp tiến trình tăng dần theo thời gian đến
    int numProcess = processes.size();//Khai báo số lượng tiến trình ban đầu bằng số lượng tiến trình trong vector
    bool statusProcess[numProcess];
    for (int i = 0; i < numProcess; i++)
    {
        statusProcess[i] = true;
    }//Cho trạng thái ban đầu của các tiến trình là chưa thực hiện
    while (numProcess)
    {
        int indexProcessing = findMinProcess(processes,statusProcess,currentTime);//Chỉ số có tiến trình được thực hiện là tiến trình đã đến và có thời gian thực thi ngắn nhất
        if (indexProcessing != -1)
        {
            processes[indexProcessing].remainingTime--;//Giảm thời gian cần thực hiện còn lại của tiến trình đi 1
            if (processes[indexProcessing].remainingTime == 0) //nếu giảm xong mà thời gian cần thực hiện bằng 0 thì tiến trình đã thực hiện xong
            {   //thực hiện
                numProcess--;//giảm số lượng tiến tình cần thực hiện
                statusProcess[indexProcessing] = false; //Chuyển trạng thái của tiến trình thành đã xử lý
                //Cập nhập các chỉ số của tiến trình đã thực hiện
                processes[indexProcessing].finishTime = currentTime + 1;
                processes[indexProcessing].turnaroundTime = processes[indexProcessing].finishTime - processes[indexProcessing].arrivalTime;
                processes[indexProcessing].waitTime = processes[indexProcessing].turnaroundTime - processes[indexProcessing].burstTime;
            }
        }
        currentTime++;
    }
    for (int i = 0;i < processes.size();i++)
    {
        cout << "ID: " << processes[i].id << endl;
        cout << "Thoi gian cho cua tien trinh la: " << processes[i].waitTime << endl;
        cout << "---------------------" << endl;
        totalWaitTime += processes[i].waitTime;
    }
    cout << "\n\n Thi gian cho trung binh cua moi tien trinh la: " << static_cast<float>(totalWaitTime) / processes.size() << endl;
};

void sjfScheduling(vector<Process> processes)
{
    int totalWaitTime = 0;
    int currentTime = 0;
    sort(processes.begin(),processes.end(),compareArrival);//Sắp xếp tiến trình tăng dần theo thời gian đến
    int numProcess = processes.size();//Khai báo số lượng tiến trình ban đầu bằng số lượng tiến trình trong vector
    bool statusProcess[numProcess];
    for (int i = 0; i < numProcess; i++)
    {
        statusProcess[i] = true;
    }//Cho trạng thái ban đầu của các tiến trình là chưa thực hiện
    while (numProcess)
    {
        int indexProcessing = findMinProcess(processes,statusProcess,currentTime);//Chỉ số có tiến trình được thực hiện là tiến trình đã đến và có thời gian thực thi ngắn nhất
        if (indexProcessing != -1)
        {
            numProcess--;//giảm số lượng tiến tình cần thực hiện
            statusProcess[indexProcessing] = false; //Chuyển trạng thái của tiến trình thành đã xử lý
            //Cập nhập các chỉ số của tiến trình đã thực hiện
            processes[indexProcessing].finishTime = currentTime + processes[indexProcessing].burstTime;
            processes[indexProcessing].turnaroundTime = processes[indexProcessing].finishTime - processes[indexProcessing].arrivalTime;
            processes[indexProcessing].waitTime = processes[indexProcessing].turnaroundTime - processes[indexProcessing].burstTime;
            currentTime += processes[indexProcessing].burstTime;
        }
        else
            currentTime++;
    }
    for (int i = 0;i < processes.size();i++)
    {
        cout << "ID: " << processes[i].id << endl;
        cout << "Thoi gian cho cua tien trinh la: " << processes[i].waitTime << endl;
        cout << "---------------------" << endl;
        totalWaitTime += processes[i].waitTime;
    }
    cout << "\n\n Thi gian cho trung binh cua moi tien trinh la: " << static_cast<float>(totalWaitTime) / processes.size() << endl;
}
int main()
{
    int n = 4;
    
    // cout << "Nhap vao so luong tien trinh muon lap lich: ";
    // cin >> n;
    vector<Process> processes;//Khai báo vector processes có kiểu dữ liệu cấu trúc Process với số lượng phần tử là n
    // for (int i = 0; i < n; i++)
    // {   int id,arrival,burst;
    //     cout << "Nhap vao id cua tien trinh P" << i + 1 << ": ";
    //     cin >> id;
    //     cout << "Nhap vao thoi gian den cua tien trinh P" << i + 1 << ": ";
    //     cin >> arrival;
    //     cout << "Nhap vao thoi gian thuc hien cua tien trinh P" << i + 1 << ": ";
    //     cin >> burst;
    //     processes.push_back({id, arrival, burst,0,0,0,0});
    // }
    processes.push_back(Process(1,0,7,7,0,0,0));
    processes.push_back(Process(2,2,4,4,0,0,0));
    processes.push_back(Process(3,4,1,1,0,0,0));
    processes.push_back(Process(4,5,4,4,0,0,0));

    sjfScheduling(processes);
    
    return 0;
}
