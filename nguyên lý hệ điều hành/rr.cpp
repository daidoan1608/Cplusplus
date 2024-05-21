#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int burstTime;
    int waitTime;
    int endTime;

};

void rrScheduling(queue<Process> &processes, int q, int n)
{
    int totalWaitTime=0;
    int timeCPU= 0 ;
    queue<Process> processes1;
    while (!processes.empty())
    {
        Process currentProcess = processes.front();
        processes.pop();

        if (currentProcess.burstTime > q)
        {
            cout << '|'<< timeCPU << "     P" << currentProcess.id << "     ";
            currentProcess.waitTime += (timeCPU - currentProcess.endTime); //Thời gian chờ bằng thời gian chờ trước đó + thời gian của cpu hiện tại trừ đi thời gian kết thúc trước đó của tiến trình
            timeCPU += q; // thời gian hiện tại của cpu bằng thời gian của cpu trước khi thực hiện tiến trình công với thời gian định lượng
            currentProcess.endTime = timeCPU;
            currentProcess.burstTime -= q;
            processes.push(currentProcess);
        }
        else
        {
            cout << '|'<< timeCPU << "     P" << currentProcess.id << "     ";
            currentProcess.waitTime += (timeCPU - currentProcess.endTime);//Thời gian chờ bằng thời gian chờ trước đó + thời gian của cpu hiện tại trừ đi thời gian kết thúc trước đó của tiến trình
            timeCPU += currentProcess.burstTime;//Thời gian hiện tại của tiến trình bằng thời gian trước khi thực hiện tính trình cộng với thời gian thực hiện còn lại của tiến trình
            currentProcess.endTime = timeCPU;
            processes1.push(currentProcess);
        }
    }
    cout  << '|' << timeCPU << '\n';
    while (!processes1.empty())
    {
        Process currentProcess = processes1.front();
        processes1.pop();
        cout << "Thoi gian cho cua tien trinh P" << currentProcess.id << " la: " << currentProcess.waitTime << '\n';
        totalWaitTime += currentProcess.waitTime;
    }
    cout << "\n\nThoi gian cho trung binh la = " <<  static_cast<float>(totalWaitTime) / n << endl;

    
}
int main()
{
    int n,q;
    queue<Process> processes;
    cout << "Nhap vao so luong tien trinh muon lap lich: ";
    cin >> n;
    cout << "\nNhap vao thoi gian dinh luong q = " ;
    cin >> q; cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        Process newProcess;
        cout << "Nhap vao id cua tien trinh thu " << i << ": ";
        cin >> newProcess.id ;
        cout << "Nhap vao thoi gian cua tien trinh thu " << i << ": ";
        cin >> newProcess.burstTime;
        newProcess.endTime = 0;
        newProcess.waitTime = 0;

        processes.push(newProcess);//Đưa tiến trình vào hàng đợi
    }

    rrScheduling(processes,q,n);
    
    return 0;

}