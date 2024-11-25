#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cows(n); // {소의 위치, 소의 원래 인덱스}
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cows[i] = { x, i };
    }

    sort(cows.begin(), cows.end()); // 소의 위치를 기준으로 정렬

    vector<int> to(n);       // 각 소가 공을 전달할 소의 인덱스
    vector<int> indegree(n); // 각 소의 진입 차수

    for (int i = 0; i < n; i++) {
        int left_dist = INT_MAX;
        int right_dist = INT_MAX;

        if (i > 0) {
            left_dist = cows[i].first - cows[i - 1].first;
        }
        if (i < n - 1) {
            right_dist = cows[i + 1].first - cows[i].first;
        }

        if (left_dist <= right_dist) {
            // 왼쪽 소에게 전달
            to[i] = i - 1;
        }
        else {
            // 오른쪽 소에게 전달
            to[i] = i + 1;
        }

        // 공을 받는 소의 진입 차수 증가
        indegree[to[i]]++;
    }

    // 초기 공을 받아야 하는 소의 수 계산
    int balls = 0;
    vector<bool> visited(n, false);

    // 진입 차수가 0인 소들을 방문하여 도달할 수 있는 모든 소들을 방문 표시
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            balls++;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = to[curr];
            }
        }
    }

    // 아직 방문하지 않은 소들을 탐색하여 사이클을 찾음
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            balls++; // 사이클마다 공 하나 추가
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = to[curr];
            }
        }
    }

    cout << balls << endl;

    return 0;
}
