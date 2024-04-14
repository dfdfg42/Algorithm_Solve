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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    maze.resize(n, vector<int>(n, 0));
    cost.resize(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            maze[i][j] = s[j] - '0';
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});
    cost[0][0] = 0;

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == n - 1 && y == n - 1) {
            cout << currentCost << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                int nextCost = currentCost + (maze[nx][ny] == 1 ? 0 : 1);
                if (nextCost < cost[nx][ny]) {
                    cost[nx][ny] = nextCost;
                    pq.push({nextCost, {nx, ny}});
                }
            }
        }
    }

    return 0;
}
