#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;

int N, K;
int dist[MAX];
int ways[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < MAX; i++) {
        dist[i] = -1;
    }

    queue<int> q;
    dist[N] = 0;
    ways[N] = 1;
    q.push(N);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int next_pos[3] = { current - 1, current + 1, 2 * current };

        for (int i = 0; i < 3; i++) {
            int next = next_pos[i];

            if (next < 0 || next >= MAX) continue;

            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                ways[next] = ways[current];
                q.push(next);
            }
            else if (dist[next] == dist[current] + 1) {
                ways[next] += ways[current];
            }
        }
    }

    cout << dist[K] << "\n";
    cout << ways[K] << "\n";

    return 0;
}
