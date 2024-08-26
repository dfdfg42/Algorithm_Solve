#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int N) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dist(N, vector<int>(N, INF));

    // 자기 자신으로의 거리는 0으로 초기화
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;
        A--; // 0-based index
        B--; // 0-based index
        dist[A][B] = 1;
        dist[B][A] = 1;
    }

    floydWarshall(dist, N);

    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] > 6) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag) {
        cout << "Small World!" << '\n';
    } else {
        cout << "Big World!" << '\n';
    }

    return 0;
}
