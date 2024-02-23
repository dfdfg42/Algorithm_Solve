#include <iostream>
#include <vector>
using namespace std;

int M, N, K;
int counting;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(vector<vector<int>> &map, vector<vector<bool>> &check ,int x, int y) {
    
    check[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (map[nx][ny] == 1 && check[nx][ny] == false) {
                dfs(map, check, nx, ny);
            }
        }

    }

}

int main() {
    

    int T;
    cin >> T;

    while (T--) {
        counting = 0;
        cin >> M >> N >> K;
        vector<vector<int>> map(M, vector<int>(N, 0));
        vector<vector<bool>> check(M, vector<bool>(N, false));
        vector<pair<int, int>> cabbages;

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;

            map[x][y] = 1;
            cabbages.push_back({ x,y });
        }

        for (pair<int, int> a : cabbages) {
            if (check[a.first][a.second] == false) {
                counting++;
                dfs(map, check, a.first, a.second);
            }
        }
        cout << counting << '\n';
    }



    return 0;
}
