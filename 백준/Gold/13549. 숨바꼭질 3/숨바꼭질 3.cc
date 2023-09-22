#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;

int N, K;
int dist[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < MAX; i++) {
        dist[i] = -1;
    }

    priority_queue<pair<int, int>> pq;
    dist[N] = 0;
    pq.push({0, N});

    while (!pq.empty()) {
        int time = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current == K) {
            cout << time << "\n";
            return 0;
        }

        int next_pos[3] = {current - 1, current + 1, 2 * current};

        for (int i = 0; i < 3; i++) {
            int next = next_pos[i];

            if (next < 0 || next >= MAX) continue;

            int next_time = time + (i == 2 ? 0 : 1);

            if (dist[next] == -1 || dist[next] > next_time) {
                dist[next] = next_time;
                pq.push({-next_time, next});
            }
        }
    }

    return 0;
}
