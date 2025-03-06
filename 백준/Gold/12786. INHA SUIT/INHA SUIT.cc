#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<vector<bool>> holes(N, vector<bool>(21, false));
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        for (int j = 0; j < M; ++j) {
            int h;
            cin >> h;
            holes[i][h] = true;
        }
    }

    // minT[나무][높이] = 여기까지 오는 데 필요한 최소 T 횟수
    vector<vector<int>> minT(N + 1, vector<int>(21, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    pq.push({0, {0, 1}}); // {T 사용 횟수, {현재 나무, 현재 높이}}
    minT[0][1] = 0;

    while (!pq.empty()) {
        int usedT = pq.top().first;
        int currentTree = pq.top().second.first;
        int currentH = pq.top().second.second;
        pq.pop();

        if (currentTree == N) {
            cout << usedT << '\n';
            return 0;
        }

        if (currentTree >= N) continue;

        // 다음 나무로 이동
        int nextTree = currentTree + 1;

        // O 기능
        if (holes[currentTree][currentH]) {
            if (minT[nextTree][currentH] > usedT) {
                minT[nextTree][currentH] = usedT;
                pq.push({usedT, {nextTree, currentH}});
            }
        }

        // A 기능
        if (currentH + 1 <= 20 && holes[currentTree][currentH + 1]) {
            if (minT[nextTree][currentH + 1] > usedT) {
                minT[nextTree][currentH + 1] = usedT;
                pq.push({usedT, {nextTree, currentH + 1}});
            }
        }

        // B 기능
        int nextB = (currentH >= 10) ? 20 : currentH * 2;
        if (nextB > 20) nextB = 20;
        if (holes[currentTree][nextB]) {
            if (minT[nextTree][nextB] > usedT) {
                minT[nextTree][nextB] = usedT;
                pq.push({usedT, {nextTree, nextB}});
            }
        }

        // C 기능
        if (currentH - 1 >= 1 && holes[currentTree][currentH - 1]) {
            if (minT[nextTree][currentH - 1] > usedT) {
                minT[nextTree][currentH - 1] = usedT;
                pq.push({usedT, {nextTree, currentH - 1}});
            }
        }

        // T 기능
        if (usedT < K) {
            for (int h = 1; h <= 20; ++h) {
                if (holes[currentTree][h] && minT[nextTree][h] > usedT + 1) {
                    minT[nextTree][h] = usedT + 1;
                    pq.push({usedT + 1, {nextTree, h}});
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}