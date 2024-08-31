#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1,vector<int>(n+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[m] = 0;
    q.push(m);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[x][i] == 0) {
                continue;
            }
            if (dist[i] != -1) continue;

            dist[i] = dist[x] + 1;
            q.push(i);

        }
    }

    int Maxdist = 0;
    for (int i = 1; i <= n; i++)
        Maxdist = max(Maxdist, dist[i]);

    for (int i = 0; i <= Maxdist; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[j] == i) cout << j << " ";

        }
        cout << '\n';

    }

    return 0;
}
