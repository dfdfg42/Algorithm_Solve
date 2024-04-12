#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void zoneSetting(vector<vector<int>>& zone, int y1, int y2, int x1, int x2, int type) {
    for (int i = min(y1, y2); i <= max(y1, y2); i++) {  // 범위를 정확하게 설정
        for (int j = min(x1, x2); j <= max(x1, x2); j++) {
            zone[i][j] = type;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //0 안전 1 위험 2 죽음
    vector<vector<int>> zone(501, vector<int>(501, 0));
    vector<vector<bool>> visited(501, vector<bool>(501, false));

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x2 >> y1 >> x1 >> y2;
        zoneSetting(zone, y1, y2, x1, x2, 1);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x2 >> y1 >> x1 >> y2;
        zoneSetting(zone, y1, y2, x1, x2, 2);
    }

    //for (int i = 0; i <= 500; i++) {
    //    for (int j = 0; j <= 500; j++) {
    //        cout << zone[i][j];

    //    }
    //    cout << '\n';
    //}

    deque<pair<pair<int, int> , int>> d;
    d.push_back({ { 0, 0 } , 0 });
    visited[0][0] = true;
    int goalLife = 0;
    bool goal = false;

    while (!d.empty()) {
        int bx = d.front().first.first;
        int by = d.front().first.second;
        int life = d.front().second;
        if (bx == 500 && by == 500) {
            goal = true;
            goalLife = life;
            break;
        }

        d.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = bx + dx[i];
            int ny = by + dy[i];

            if (0 <= nx && nx <= 500 && 0 <= ny && ny <= 500 && !visited[nx][ny]) {
                visited[nx][ny] = true; 
                if (zone[nx][ny] == 0) {
                    d.push_front({ { nx, ny }, life });
                }
                else if (zone[nx][ny] == 1) {
                    d.push_back({ { nx, ny },life +1});
                }
            }
        }
    }

    if (goal) {
        cout << goalLife << '\n';
    }
    else {
        cout << -1 << '\n';
    }


    return 0;
}
