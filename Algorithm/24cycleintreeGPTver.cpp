#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

vector<vector<int> > graph;   // กราฟ
vector<bool> visited;        // เก็บสถานะการเยี่ยมชมโหนด
vector<int> parent;          // เก็บพ่อแม่ของโหนดเพื่อใช้ในการย้อนกลับวงจร

int n;  // จำนวนโหนด

// ฟังก์ชั่น DFS
bool dfs(int u, stack<int>& path) {
    visited[u] = true;
    path.push(u);  // เพิ่มโหนดลงใน stack (เส้นทางปัจจุบัน)

    for (int v : graph[u]) {
        if (!visited[v]) {  // ถ้าโหนดยังไม่เคยเยี่ยมชม
            parent[v] = u;
            if (dfs(v, path)) {
                return true;
            }
        } else if (v != parent[u]) {  // พบวงจร (ย้อนกลับมาโหนดที่ไม่ใช่พ่อแม่)
            // สร้างวงจร
            stack<int> cycle;
            cycle.push(v);
            while (path.top() != v) {
                cycle.push(path.top());
                path.pop();
            }
            cycle.push(v);

            // แสดงขนาดของวงจร
            cout << cycle.size() - 1 << endl;  // ใช้ size() - 1 เพื่อลดขนาดลง
            return true;
        }
    }

    path.pop();  // ลบโหนดออกจาก stack เมื่อไม่เจอวงจร
    return false;
}

int main() {
    cin >> n;

    // ตรวจสอบจำนวนโหนด
    if (n <= 0) {
        cout << "Number of nodes should be greater than 0" << endl;
        return 1;
    }

    // ปรับขนาดกราฟให้รองรับจำนวนโหนด
    graph.resize(n);
    visited.resize(n, false);
    parent.resize(n, -1);

    // อ่านกราฟ
    for (int i = 0; i < n; i++) { // ขอบจำนวนมากกว่า n-1
        int u, v;
        cin >> u >> v;

        // ตรวจสอบว่าค่าของ u, v อยู่ในช่วงที่ถูกต้องหรือไม่
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid node index. Node index should be between 0 and " << n - 1 << endl;
            return 1;
        }

        graph[u].push_back(v);
        graph[v].push_back(u); // กราฟที่มีขอบสองทิศทาง
    }

    // เรียก DFS จากโหนดแรก
    stack<int> path;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, path)) {
                return 0;  // เจอวงจรแล้วก็หยุด
            }
        }
    }

    cout << "No cycle" << endl;  // ถ้าไม่มีวงจร
    return 0;
}
