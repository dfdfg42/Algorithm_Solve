#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int tc = 1; tc <= 10; tc++) {
        int n, start;
        cin >> n >> start;

        vector<vector<int>> nodes(101);
        vector<bool> visited(101, false);
        vector<int> dist(101, 0); 

        for (int i = 0; i < n / 2; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].push_back(b);
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;
        dist[start] = 1; 

        int maxLevel = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int nd : nodes[current]) {
                if (!visited[nd]) {
                    visited[nd] = true;
                    dist[nd] = dist[current] + 1;
                    q.push(nd);
                    maxLevel = max(maxLevel, dist[nd]); 
                }
            }
        }

        int answer = 0;
        
        for (int i = 1; i <= 100; i++) {
            if (dist[i] == maxLevel) {
                answer = max(answer, i); 
            }
        }

        cout << '#' << tc << " " << answer << '\n';
    }

    return 0;
}
