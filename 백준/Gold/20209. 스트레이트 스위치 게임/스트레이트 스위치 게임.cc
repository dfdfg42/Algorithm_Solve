#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

// 모든 큐브의 숫자가 동일한지 확인하는 함수
bool equal(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] != vec[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> cubes(n);
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }
    
    vector<vector<int>> switches(k);
    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        switches[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> switches[i][j];
            switches[i][j]--; // 1-based index를 0-based index로 변환
        }
    }

    // 중복 상태 관리를 위한 set
    set<vector<int>> visited;

    // 큐브 상태와 스위치를 누른 횟수를 저장할 큐
    queue<pair<vector<int>, int>> q;
    q.push({cubes, 0});
    visited.insert(cubes);

    while (!q.empty()) {
        vector<int> current = q.front().first;
        int moves = q.front().second;
        q.pop();

        // 모든 큐브의 숫자가 동일하면 정답 출력 후 종료
        if (equal(current)) {
            cout << moves << endl;
            return 0;
        }

        // 각 스위치를 한번씩 눌러보는 과정
        for (int i = 0; i < k; i++) {
            vector<int> next = current;
            for (int idx : switches[i]) {
                next[idx] = (next[idx] + (i + 1)) % 5; // 스위치에 따라 숫자 변경
            }

            // 이미 방문한 상태가 아니면 큐와 set에 추가
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, moves + 1});
            }
        }
    }

    // 모든 경우를 탐색했음에도 정답을 찾지 못한 경우
    cout << -1 << endl;
    return 0;
}
