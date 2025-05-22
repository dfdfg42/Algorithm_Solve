#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m, k;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
bool check(int a) {
    if (0 <= a && a < n) {
        return true;
    }
    return false;
}
int dfs(int y, int x) { 
    int count = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (check(ny) && check(nx)) {
            if (!visited[ny][nx] && board[ny][nx] == 0) {
                visited[ny][nx] = true;
                count += dfs(ny, nx);
            }
        }
    }
    return count;
}
void solve() {
    cin >> n >> m >> k;
    board.resize(n + 1, vector<int>(n + 1));
    visited.resize(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int total_needed = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {  
            if (visited[i][j] == false && board[i][j] == 0) {
                visited[i][j] = true;
                int component_size = dfs(i, j);
                total_needed += (component_size + k - 1) / k; 
            }
        }
    }


    if (total_needed > m || total_needed == 0) { 
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        cout << "POSSIBLE" << '\n' << m - total_needed <<  
            '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}