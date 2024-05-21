#include <bits/stdc++.h>

using namespace std;

// Khai báo cấu trúc tiến trình
struct Process
{
    int id;             // Tên tiến trình
    int arrivalTime;    // Thời gian vào
    int burstTime;      // Thời gian thực thi
    int priority;       // Độ ưu tiên
    int remainingTime;  // Thời gian thực thi còn lại để hoàn thành tiến trình
    int finishTime;     // Thời diểm kết thúc tiến trình
    int turnaroundTime; // finishTime - arrivalTime
    int waitTime;       // Thời gian chờ turnaroundTime - burstTime
};

bool comparePriority(const Process &a, const Process &b);                             // Hàm so sánh giá trị chỉ số ưu tiên
bool compareArrival(const Process &a, const Process &b);                              // Hàm so sánh giá trị chỉ số thời gian vào
int findMinProcess(vector<Process> processes, bool statusProcess[], int currentTime); // Hàm tìm tiến trình có thời gian thực thi ngắn nhất
void fcfsScheduling(queue<Process> &processes, int n);                                // Hàm mô phỏng giải thuật First-Come,First-Served
void sjfScheduling(vector<Process> processes);                                        // Hàm mô phỏng giải thuật SJF ko ưu tiên trước
void srtfScheduling(vector<Process> processes);                                       // Hàm mô phỏng giải thuật SJF có ưu tiên trước
void priorityScheduling(vector<Process> processes, int n);                            // Hàm mô phỏng giải thuật theo mức ưu tiên prority
void rrScheduling(queue<Process> &processes, int q, int n);                           // Hàm mô phỏng giải thuật Round-Robin
void replay();

//=== Chương trình chính===
int main()
{
    int choice = 0;
    do
    {
        cout << "\nSu dung:" << endl;
        cout << "1.Giai thuat First-Come,First-Served(FCFS)." << endl;
        cout << "2.Su dung giai thuat Shortest-Job-First(SJF)." << endl;
        cout << "3.Su dung giai thuat Shortest-Remaining-Time-First(SRTF)" << endl;
        cout << "4.Su dung giai thuat Priority" << endl;
        cout << "5.Su dung giai thuatPound-Robin(RR) " << endl;
        cout << "6.Thoat" << endl;
        cout << "\nNhap vao lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int n;
            queue<Process> processes;
            cout << "\nNhap vao so luong tien trinh muon lap lich: ";
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                Process newProcess;
                cout << "\nNhap vao id cua tien trinh thu " << i << ": ";
                cin >> newProcess.id;
                cout << "Nhap vao thoi gian su dung cua tien trinh thu " << i << ": ";
                cin >> newProcess.burstTime;
                processes.push(newProcess); // Đưa tiến trình vào hàng đợi
            }
            fcfsScheduling(processes, n); // Lập lịch những tiến trình đã nhập vào

            replay();

            break;
        case 2:
            int n;
            cout << "\nNhap vao so luong tien trinh muon lap lich: ";
            cin >> n;
            vector<Process> processes; // Khai báo vector processes có kiểu dữ liệu cấu trúc Process với số lượng phần tử là n
            for (int i = 0; i < n; i++)
            {
                Process newProcess;
                cout << "\nNhap vao id cua tien trinh thu " << i + 1 << ": ";
                cin >> newProcess.id;
                cout << "Nhap vao thoi gian den cua tien trinh thu " << i + 1 << ": ";
                cin >> newProcess.arrivalTime;
                cout << "Nhap vao thoi gian thuc hien cua tien trinh thu " << i + 1 << ": ";
                cin >> newProcess.burstTime;
                newProcess.remainingTime = newProcess.burstTime;
                newProcess.priority = 0;
                newProcess.finishTime = 0;
                newProcess.turnaroundTime = 0;
                newProcess.waitTime = 0;
                processes.push_back(newProcess);
            }
            sjfScheduling(processes);

            replay();

            break;
        case 3:
            int n;
            cout << "\nNhap vao so luong tien trinh muon lap lich: ";
            cin >> n;
            vector<Process> processes; // Khai báo vector processes có kiểu dữ liệu cấu trúc Process với số lượng phần tử là n
            for (int i = 0; i < n; i++)
            {
                Process newProcess;
                cout << "\nNhap vao id cua tien trinh thu " << i + 1 << ": ";
                cin >> newProcess.id;
                cout << "Nhap vao thoi gian den cua tien trinh thu " << i + 1 << ": ";
                cin >> newProcess.arrivalTime;
                cout << "Nhap vao thoi gian thuc hien cua tien trinh thu " << i + 1 << ": ";
                cin >> newProcess.burstTime;
                newProcess.remainingTime = newProcess.burstTime;
                newProcess.priority = 0;
                newProcess.finishTime = 0;
                newProcess.turnaroundTime = 0;
                newProcess.waitTime = 0;
                processes.push_back(newProcess);
            }

            srtfScheduling(processes);

            replay();

            break;
        case 4:
            int n;
            cout << "\nNhap vao so tien trinh can lap lich: ";
            cin >> n;
            vector<Process> processes;

            for (int i = 0; i < n; i++)
            {
                Process newProcess;
                cout << "\nNhap vao id cua tien trinh " << i + 1 << ": ";
                cin >> newProcess.id;
                cout << "Nhap vao do uu tien cua tien trinh " << i + 1 << ": ";
                cin >> newProcess.priority;
                cout << "Nhap vao thoi gian thuc hien cua tien trinh " << i + 1 << ": ";
                cin >> newProcess.burstTime;

                processes.push_back(newProcess);
            }
            priorityScheduling(processes, n);

            replay();

            break;
        case 5:
            int n, q;
            queue<Process> processes;
            cout << "\nNhap vao so luong tien trinh muon lap lich: ";
            cin >> n;
            cout << "Nhap vao thoi gian dinh luong q = ";
            cin >> q;
            cout << '\n';
            for (int i = 1; i <= n; i++)
            {
                Process newProcess;
                cout << "\nNhap vao id cua tien trinh thu " << i << ": ";
                cin >> newProcess.id;
                cout << "Nhap vao thoi gian cua tien trinh thu " << i << ": ";
                cin >> newProcess.burstTime;
                newProcess.finishTime = 0;
                newProcess.waitTime = 0;

                processes.push(newProcess); // Đưa tiến trình vào hàng đợi
            }
            rrScheduling(processes, q, n);

            replay();

            break;
        case 6:
            return 0;
        default:
            cout << "\nLua chon sai, vui long chon lai!" << endl;
            replay();
            break;
        }
    } while (1);
    return 0;
}

//===Định nghĩa hàm===
void replay()
{
    cout << "\nENTER de quay lai man hinh chon!";
    cin.ignore(1, '\n');
    getchar();

    system("cls");
}

bool compareArrival(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}

bool comparePriority(const Process &a, const Process &b)
{
    return a.priority < b.priority;
}

int findMinProcess(vector<Process> processes, bool statusProcess[], int currentTime)
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
}

void fcfsScheduling(queue<Process> &processes, int n)
{
    int waitTime = 0, totalWaitTime = 0;
    int *waitTimes = new int[n];
    int *ids = new int[n];
    int i = 0;
    cout << "\nBieu do Gantt:" << endl;
    while (!processes.empty()) // Kiểm tra hàng đợi tiến trình có trống hay ko
    {
        Process currentProcess = processes.front(); // Lấy ra tiến trình đến trước đưa vào tiến trình hiện tại
        processes.pop();                            // Xóa tiến trình đã lấy khỏi hàng đợi tiến trình
        waitTimes[i] = waitTime;
        ids[i] = currentProcess.id;
        i++;
        cout << waitTime << "|"
             << "     P" << currentProcess.id << "     ";
        totalWaitTime += waitTime;
        waitTime += currentProcess.burstTime; // Thoi gian cho cua tien trinh sau bằng thời gian chờ của tiến trình trước + thời gian thực hiên tiến trình trước
    }
    cout << waitTime << "|\n"
         << endl;

    for (int j = 0; j < n; j++)
    {
        cout << "ID: " << ids[j] << endl;
        cout << "Thoi gian cho cua tien trinh la: " << waitTimes[j] << endl;
        cout << "---------------------" << endl;
    }
    cout << "\nThoi gian cho trung binh cua cac tien trinh la: " << static_cast<float>(totalWaitTime) / n << endl;
}

void sjfScheduling(vector<Process> processes)
{
    int totalWaitTime = 0;
    int currentTime = 0;
    sort(processes.begin(), processes.end(), compareArrival); // Sắp xếp tiến trình tăng dần theo thời gian đến
    int numProcess = processes.size();                        // Khai báo số lượng tiến trình ban đầu bằng số lượng tiến trình trong vector
    bool statusProcess[numProcess];
    for (int i = 0; i < numProcess; i++)
    {
        statusProcess[i] = true;
    } // Cho trạng thái ban đầu của các tiến trình là chưa thực hiện
    cout << "\nBieu do Gantt: " << endl;
    while (numProcess)
    {
        int indexProcessing = findMinProcess(processes, statusProcess, currentTime); // Chỉ số có tiến trình được thực hiện là tiến trình đã đến và có thời gian thực thi ngắn nhất
        cout << '|' << currentTime << "     P" << processes[indexProcessing].id << "     ";
        if (indexProcessing != -1)
        {
            numProcess--;                           // giảm số lượng tiến tình cần thực hiện
            statusProcess[indexProcessing] = false; // Chuyển trạng thái của tiến trình thành đã xử lý
            // Cập nhập các chỉ số của tiến trình đã thực hiện
            processes[indexProcessing].finishTime = currentTime + processes[indexProcessing].burstTime;
            processes[indexProcessing].turnaroundTime = processes[indexProcessing].finishTime - processes[indexProcessing].arrivalTime;
            processes[indexProcessing].waitTime = processes[indexProcessing].turnaroundTime - processes[indexProcessing].burstTime;
            currentTime += processes[indexProcessing].burstTime;
        }
        else
            currentTime++;
    }
    cout << '|' << currentTime << '\n'
         << endl;
    for (int i = 0; i < processes.size(); i++)
    {
        cout << "ID: " << processes[i].id << endl;
        cout << "Thoi gian cho cua tien trinh la: " << processes[i].waitTime << endl;
        cout << "---------------------" << endl;
        totalWaitTime += processes[i].waitTime;
    }
    cout << "\nThoi gian cho trung binh cua moi tien trinh la: " << static_cast<float>(totalWaitTime) / processes.size() << endl;
}

void srtfScheduling(vector<Process> processes)
{
    int totalWaitTime = 0;
    int currentTime = 0;
    sort(processes.begin(), processes.end(), compareArrival); // Sắp xếp tiến trình tăng dần theo thời gian đến
    int numProcess = processes.size();                        // Khai báo số lượng tiến trình ban đầu bằng số lượng tiến trình trong vector
    bool statusProcess[numProcess];
    for (int i = 0; i < numProcess; i++)
    {
        statusProcess[i] = true;
    } // Cho trạng thái ban đầu của các tiến trình là chưa thực hiện
    cout << "\nBieu do Gantt: " << endl;
    while (numProcess)
    {
        int indexProcessing = findMinProcess(processes, statusProcess, currentTime); // Chỉ số có tiến trình được thực hiện là tiến trình đã đến và có thời gian thực thi ngắn nhất
        cout << '|' << currentTime << "     P" << processes[indexProcessing].id << "     ";
        if (indexProcessing != -1)
        {
            processes[indexProcessing].remainingTime--;        // Giảm thời gian cần thực hiện còn lại của tiến trình đi 1
            if (processes[indexProcessing].remainingTime == 0) // nếu giảm xong mà thời gian cần thực hiện bằng 0 thì tiến trình đã thực hiện xong
            {                                                  // thực hiện
                numProcess--;                                  // giảm số lượng tiến tình cần thực hiện
                statusProcess[indexProcessing] = false;        // Chuyển trạng thái của tiến trình thành đã xử lý
                // Cập nhập các chỉ số của tiến trình đã thực hiện
                processes[indexProcessing].finishTime = currentTime + 1;
                processes[indexProcessing].turnaroundTime = processes[indexProcessing].finishTime - processes[indexProcessing].arrivalTime;
                processes[indexProcessing].waitTime = processes[indexProcessing].turnaroundTime - processes[indexProcessing].burstTime;
            }
        }
        currentTime++;
    }
    cout << '|' << currentTime << '\n'
         << endl;
    for (int i = 0; i < processes.size(); i++)
    {
        cout << "ID: " << processes[i].id << endl;
        cout << "Thoi gian cho cua tien trinh la: " << processes[i].waitTime << endl;
        cout << "---------------------" << endl;
        totalWaitTime += processes[i].waitTime;
    }
    cout << "\nThoi gian cho trung binh cua moi tien trinh la: " << static_cast<float>(totalWaitTime) / processes.size() << endl;
}

void priorityScheduling(vector<Process> processes, int n)
{
    int currentTime = 0, totalWaitTime = 0;
    sort(processes.begin(), processes.end(), comparePriority);
    cout << "\nBieu do Gantt: " << endl;
    for (int i = 0; i < n; i++)
    {
        processes[i].waitTime = currentTime;
        cout << processes[i].waitTime << "|"
             << "     P" << processes[i].id << "     ";
        totalWaitTime += currentTime;
        currentTime += processes[i].burstTime;
    }
    cout << currentTime << '|' << "\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ID: " << processes[i].id << endl;
        cout << "Thoi gian cho cua tien trinh la: " << processes[i].waitTime << endl;
        cout << "---------------------" << endl;
    }
    cout << "\nThoi gian cho trung binh la = " << static_cast<float>(totalWaitTime) / n << endl;
}

void rrScheduling(queue<Process> &processes, int q, int n)
{
    int totalWaitTime = 0;
    int currentTime = 0;
    queue<Process> processes1;
    cout << "\nBieu do Gantt:" << endl;
    while (!processes.empty())
    {
        Process currentProcess = processes.front();
        processes.pop();

        if (currentProcess.burstTime > q)
        {
            cout << '|' << currentTime << "     P" << currentProcess.id << "     ";
            currentProcess.waitTime += (currentTime - currentProcess.finishTime); // Thời gian chờ bằng thời gian chờ trước đó + thời gian của cpu hiện tại trừ đi thời gian kết thúc trước đó của tiến trình
            currentTime += q;                                                     // thời gian hiện tại của cpu bằng thời gian của cpu trước khi thực hiện tiến trình công với thời gian định lượng
            currentProcess.finishTime = currentTime;
            currentProcess.burstTime -= q;
            processes.push(currentProcess);
        }
        else
        {
            cout << '|' << currentTime << "     P" << currentProcess.id << "     ";
            currentProcess.waitTime += (currentTime - currentProcess.finishTime); // Thời gian chờ bằng thời gian chờ trước đó + thời gian của cpu hiện tại trừ đi thời gian kết thúc trước đó của tiến trình
            currentTime += currentProcess.burstTime;                              // Thời gian hiện tại của tiến trình bằng thời gian trước khi thực hiện tính trình cộng với thời gian thực hiện còn lại của tiến trình
            currentProcess.finishTime = currentTime;
            processes1.push(currentProcess);
        }
    }
    cout << '|' << currentTime << "\n"
         << endl;
    while (!processes1.empty())
    {
        Process currentProcess = processes1.front();
        processes1.pop();
        cout << "ID: " << currentProcess.id << endl;
        cout << "Thoi gian cho cua tien trinh la: " << currentProcess.waitTime << endl;
        cout << "---------------------" << endl;
        totalWaitTime += currentProcess.waitTime;
    }
    cout << "\nThoi gian cho trung binh la = " << static_cast<float>(totalWaitTime) / n << endl;
}