#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C, E;
    cin >> N >> C >> E;

    vector<vector<int>> grid(N, vector<int>(N, 0));

    // 1. 1번 영역 채우기 (i+j가 작은 순서부터)
    int countC = 0;
    for (int k = 0; k <= 2 * (N - 1); ++k) {
        for (int i = 0; i < N; ++i) {
            int j = k - i;
            if (j >= 0 && j < N && countC < C) {
                grid[i][j] = 1;
                countC++;
            }
        }
    }

    // 2. 2번 영역 채우기 (i+j가 큰 순서부터)
    int countE = 0;
    for (int k = 2 * (N - 1); k >= 0; --k) {
        for (int i = N - 1; i >= 0; --i) {
            int j = k - i;
            if (j >= 0 && j < N && grid[i][j] == 0) {
                // 상하좌우에 1이 있는지 체크
                bool adjTo1 = false;
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && grid[ni][nj] == 1) {
                        adjTo1 = true;
                        break;
                    }
                }

                if (!adjTo1 && countE < E) {
                    grid[i][j] = 2;
                    countE++;
                }
            }
        }
    }

    // 결과 출력
    if (countE < E) {
        cout << -1 << "\n";
    } else {
        cout << 1 << "\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}