#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int burstTime;
    int priority;
    int waitTime;
};
bool compareByPriority(const Process &a, const Process &b) {
    return a.priority < b.priority;
};
void priorityScheduling(Process* processes,int n)
{
    int timeCPU = 0, totalWaitTime=0;
    sort(processes,processes + n, compareByPriority);
    for (int i = 0; i < n; i++)
    {
        processes[i].waitTime = timeCPU;
        cout << processes[i].waitTime << "|" << "    P" << processes[i].id << "     ";
        totalWaitTime += timeCPU;
        timeCPU +=  processes[i].burstTime;    
    }
    cout << timeCPU << '|' << "\n\n";
    for (int i = 0; i < n; i++)
        cout << "Thoi gian cho cua tien trinh P" << processes[i].id << " la: " << processes[i].waitTime << '\n';
    
    cout << "\n\nThoi gian cho trung binh la = " <<  static_cast<float>(totalWaitTime) / n << "\n" << endl;
};
int main()
{
    int n;
    cout << "Nhap vao so tien trinh can lap lich: ";
    cin >> n;
    Process *processes =new Process[n];

    for (int i = 0; i < n; i++)
    {   
        cout << "Nhap vao id cua tien trinh " << i + 1 << ": ";
        cin >> processes[i].id;
        cout << "Nhap vao do uu tien cua tien trinh " << i + 1 << ": ";
        cin >> processes[i].priority;
        cout << "Nhap vao thoi gian thuc hien cua tien trinh " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }
    priorityScheduling(processes,n);
    
    return 0;
}