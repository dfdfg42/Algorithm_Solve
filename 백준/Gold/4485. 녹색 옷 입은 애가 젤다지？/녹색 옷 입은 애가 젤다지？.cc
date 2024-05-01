#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
    int pc = 1;
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<vector<int>> map(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int input;
                cin >> input;
                map[i][j] = input;
            }
        }

        priority_queue <pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        pq.push({ map[0][0],{0,0} });
        visited[0][0] = true;
        int result = 0;

        while (!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int ruppee = pq.top().first;

            pq.pop();

            if (x == n - 1 && y == n - 1) {
                result = ruppee;
                break;
            }


            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int new_cost = ruppee + map[nx][ny];
                    pq.push({ new_cost, {nx, ny} });
                }
            }
        }

      
        cout << "Problem " << pc << ": " << result << '\n';
        pc++;
    }

    return 0;
}
