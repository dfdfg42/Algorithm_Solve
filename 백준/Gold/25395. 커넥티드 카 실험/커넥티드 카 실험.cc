#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct car {
    int pos;
    int fuel;
    int num;
};

int n, s;
vector<car> cars;
bool visited[1000001];
vector<int> ans;

void bfs(int startIdx) {
    queue<int> q;
    q.push(startIdx);
    visited[startIdx] = true;

    int min_idx = startIdx;
    int max_idx = startIdx;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int curPos = cars[curr].pos;
        int curFuel = cars[curr].fuel;

        int leftRange = curPos - curFuel;
        int rightRange = curPos + curFuel;

        while (max_idx + 1 < n && cars[max_idx + 1].pos <= rightRange) {
            max_idx++; 
            if (!visited[max_idx]) {
                visited[max_idx] = true;
                q.push(max_idx);
            }
        }


        while (min_idx - 1 >= 0 && cars[min_idx - 1].pos >= leftRange) {
            min_idx--; 
            if (!visited[min_idx]) {
                visited[min_idx] = true;
                q.push(min_idx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    cars.resize(n);

    for (int i = 0; i < n; i++) cin >> cars[i].pos;
    for (int i = 0; i < n; i++) {
        cin >> cars[i].fuel;
        cars[i].num = i + 1;
    }

    bfs(s - 1);

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            ans.push_back(cars[i].num);
        }
    }

    sort(ans.begin(), ans.end());

    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}