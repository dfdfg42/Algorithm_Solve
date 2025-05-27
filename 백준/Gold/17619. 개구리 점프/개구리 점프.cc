#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100001;
int parent[MAX_N];

struct Log {
    int x1, x2, y, idx;
};

int Find(int x) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<Log> logs(n);
    
    for (int i = 0; i < n; i++) {
        cin >> logs[i].x1 >> logs[i].x2 >> logs[i].y;
        logs[i].idx = i + 1;
        parent[i + 1] = i + 1;
    }
    

    sort(logs.begin(), logs.end(), [](const Log& a, const Log& b) {
        return a.x1 < b.x1;
    });
    
    // 두 통나무가 연결될 수 있는 조건:
    // 1. x 범위가 겹침: max(x1_a, x1_b) <= min(x2_a, x2_b)
    // 2. 겹치는 x 범위에서 두 y 좌표 사이에 다른 통나무가 없음
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (logs[j].x1 > logs[i].x2) break;
            
 
            int left = max(logs[i].x1, logs[j].x1);
            int right = min(logs[i].x2, logs[j].x2);
            if (left > right) continue;
            
     
            Union(logs[i].idx, logs[j].idx);
        }
    }
    
    // 쿼리 처리
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        if (Find(a) == Find(b)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    
    return 0;
}