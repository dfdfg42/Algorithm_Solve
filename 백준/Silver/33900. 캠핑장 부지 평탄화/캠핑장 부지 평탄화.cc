#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;


int N, M, R, C;
int ans;

vector<vector<int>> board;
vector<vector<int>> rc;


bool checkFlat(int y, int x) {

    int val = board[y][x] - rc[0][0];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j <  C; j++) {
            if (board[y + i][x + j] - rc[i][j] != val) {
                return false;
            }
        }
    }

    //cout <<"find : " <<  y << x << '\n';

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R >> C;

    board.resize(N, vector<int>(M));
    rc.resize(R, vector<int>(C));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> rc[i][j];
        }
    }

    for (int i = 0; i <= N - R; i++) {
        for (int j = 0; j <= M - C; j++) {
           //cout << " i j : " << i << ' ' << j << '\n';
            if (checkFlat(i, j)) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}