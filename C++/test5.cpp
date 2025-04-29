#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//Lưu trữ đồ thị dưới dạng danh sách kề bằng unordered_map
unordered_map<char, vector<char>> graph;

// Hàm tìm kiếm theo chiều sâu
void dfs(char start, char goal) {
    stack<char> open;                  // Stack lưu trữ các nút chưa được duyệt
    vector<char> closed;               // Vector lưu trữ các nút đã được duyệt    
    open.push(start);                  // Thêm nút bắt đầu vào stack

    while (!open.empty()) {
        char u = open.top();           // Lấy nút đầu tiên trong stack Open
        open.pop();                    // Xóa nút đó khỏi stack
        // Kiểm tra xem nút u có phải là nút đích không
        if (u == goal) {
            closed.push_back(u);
            cout << "Tim thay dich: " << u << endl;
            cout << "Duong di: ";
            for (char c : closed) {
                cout << c << " ";
            }
            cout << endl;
            return;
        }
        // Nếu u kp đích thì thêm u vector Closed
        closed.push_back(u);
      
        // Duyệt các nút con của nút u theo thứ tự từ đầu đến cuối
        for (auto it = graph[u].rbegin(); it != graph[u].rend(); ++it) {
            char v = *it;
            if (find(closed.begin(), closed.end(), v) == closed.end()) { //Kiểm tra xem các con đã được duyệt trong closed chưa
                open.push(v);      // Nếu nút con chưa được duyệt thì thêm vào stack Open
            }
        }
    }

    cout << "Khong tim thay dich" << endl;
}

int main() {
    // Example graph with character nodes
    graph = {
        {'A', {'B', 'C', 'D'}},    // Node A
        {'B', {'E', 'F'}},         // Node B
        {'C', {'G', 'H'}},         // Node C
        {'D', {'I', 'J'}},         // Node D
        {'E', {'K', 'L'}},         // Node E
        {'F', {'L', 'M'}},         // Node F
        {'G', {'N'}},              // Node G
        {'H', {'O', 'P'}},         // Node H
        {'I', {'P', 'Q'}},         // Node I
        {'J', {'R'}},              // Node J
        {'K', {'S'}},              // Node K
        {'L', {'T'}},              // Node L
        {'P', {'U'}},              // Node P
        {'S', {}},                 // Node S
        {'T', {}},                 // Node T
        {'U', {}},                 // Node U
        {'M', {}},                 // Node M
        {'N', {}},                 // Node N
        {'O', {}},                 // Node O
        {'Q', {}},                 // Node Q
        {'R', {}},                 // Node R
    };
    char start;
    char goal;
    cout << "Nhập vào đỉnh bắt đầu" << endl;
    cin >> start;
    cout << "Nhập vào đỉnh kết thúc" << endl;
    cin >> goal;
    // Call DFS
    dfs(start, goal);
    
    return 0;
}
