#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<int>> maze;
vector<vector<int>> cost;
vector<vector<bool>> visited;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    maze.resize(n, vector<int>(m, 0));
    cost.resize(n, vector<int>(m, INF));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            maze[i][j] = s[j] - '0';
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({ 0, {0, 0} });
    cost[0][0] = 0;
    visited[0][0] = true;

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == n - 1 && y == m - 1) {
            cout << currentCost << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                int nextCost = currentCost + (maze[nx][ny] == 1 ? 1 : 0);
                if (!visited[nx][ny] || nextCost < cost[nx][ny]) {
                    visited[nx][ny] = true;
                    cost[nx][ny] = nextCost;
                    pq.push({ nextCost, {nx, ny} });
                }
            }
        }
    }

    return 0;
}
