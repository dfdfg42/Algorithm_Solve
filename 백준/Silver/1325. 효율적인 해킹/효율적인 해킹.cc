#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> nodes(N + 1);
    vector<int> rank(N + 1, 0); 
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        nodes[b].push_back(a); 
    }

    int maxRank = 0;
    for (int start = 1; start <= N; start++) {
        vector<bool> visited(N + 1, false); 
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int next : nodes[current]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                    rank[start]++;
                }
            }
        }
        maxRank = max(maxRank, rank[start]);
    }

    
    for (int i = 1; i <= N; i++) {
        if (rank[i] == maxRank) {
            cout << i << ' ';
        }
    }

    return 0;
}
