#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int n, m, k;

vector<vector<char>> board;
vector<pair<int, int>> teachers;

bool can;

bool boundary(int y, int x) {
    if (0 > y || y >= n || 0 > x || x >= n) {
        return false;
    }
    else return true;
}

//선생들 감시
bool check(vector<vector<char>>& temp) {

    for (auto a : teachers) {
        int y = a.first;
        int x = a.second;
        for (int i = 0; i < 4; i++) {
            int ny = y;
            int nx = x;
            while (boundary(ny,nx)) {

                if (temp[ny][nx] == 'O') {
                    break;
                }
                if (temp[ny][nx] == 'S') {
                    return false;
                }

                ny += dy[i];
                nx += dx[i];
            }
        }
    }

    return true;
}

void dfs(int y, int x, int cnt, vector<vector<char>>& temp) {

    if (can) return;

    if (cnt == 3) {

        if (check(temp)) {
            can = true;

            //for (int i = 0; i < n; i++) {
            //    for (int j = 0; j < n; j++) {
            //        cout << temp[i][j];
            //    }
            //    cout << '\n';
            //}
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (temp[i][j] =='X') {
                temp[i][j] = 'O';
                dfs(i, j, cnt + 1, temp);
                temp[i][j] = 'X';
            }

        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    board.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'T') {
                teachers.push_back({ i,j });
            }
        }
    }

    can = false;
    for (int i = 0; i < n; i++) {
        if (can) break;
        for (int j = 0; j < n; j++) {
            if (!can) {
                vector<vector<char>> temp = board;
                dfs(i, j, 0, temp);
            }
        }
    }

    if (can) cout << "YES";
    else cout << "NO";


    return 0;
}