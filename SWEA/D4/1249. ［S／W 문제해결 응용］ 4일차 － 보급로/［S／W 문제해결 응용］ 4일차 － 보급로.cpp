#include <iostream>
#include <stack>
#include <cctype> 
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,-1,0,0, };
int dy[4] = { 0,0,1,-1 };

vector<vector<int>> mapVec;
vector<vector<int>> visited;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;

    for (int k = 1; k <= tc; k++) {
        int n;
        cin >> n;

        //맵 할당
        mapVec.clear();
        visited.clear();
        mapVec.resize(n, vector<int>(n, 0));
        visited.resize(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                mapVec[i][j] = s[j] - '0';
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({ 0,{0,0} });
        visited[0][0] = 1;
        int totalCost = 0;

        while (!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int cost = pq.top().first;
            if (x == n - 1 && y == n - 1) {
                totalCost = cost;
                break;
            }
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (0 <= ny && ny < n && 0 <= nx && nx < n && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    pq.push({ cost + mapVec[nx][ny] ,{nx,ny} });
                }
            }
        }

        cout << '#' << k << ' ' << totalCost << '\n';
    }

    return 0;
}
