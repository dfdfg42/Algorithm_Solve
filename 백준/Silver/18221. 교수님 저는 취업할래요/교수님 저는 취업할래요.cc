#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;

vector<vector<int>> board;
pair<int, int> prof, sung;
int n;

// 학생을 세는 함수
bool CountingStudents(int ys, int ye, int xs, int xe, bool sameLine) {
    int count = 0;
    if (sameLine) {
        // 같은 행 또는 같은 열일 경우
        if (xs == xe) { // 같은 행
            for (int j = ys; j <= ye; j++) {
                if (board[xs][j] == 1) {
                    count++;
                }
            }
        } else { // 같은 열
            for (int i = xs; i <= xe; i++) {
                if (board[i][ys] == 1) {
                    count++;
                }
            }
        }
    } else {
        // 직사각형 내 모든 셀
        for (int i = xs; i <= xe; i++) { // 행 반복
            for (int j = ys; j <= ye; j++) { // 열 반복
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    return count >= 3;
}

int main() {
    cin >> n;
    board.resize(n, vector<int>(n));

    // 입력 받기 및 교수님과 성규의 위치 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 5) prof = {i, j};
            if (board[i][j] == 2) sung = {i, j};
        }
    }

    // 거리 계산 (제곱 거리 사용)
    int dist = pow(abs(sung.first - prof.first), 2) + pow(abs(sung.second - prof.second), 2);

    if (dist >= 25) {
        // 교수님과 성규의 위치를 기준으로 직사각형 정의
        int xs = min(prof.first, sung.first);
        int xe = max(prof.first, sung.first);
        int ys = min(prof.second, sung.second);
        int ye = max(prof.second, sung.second);

        // 같은 행 또는 같은 열인지 확인
        bool sameLine = false;
        if (prof.first == sung.first || prof.second == sung.second) {
            sameLine = true;
        }

        // 학생 수 세기
        if (CountingStudents(ys, ye, xs, xe, sameLine)) {
            cout << 1 << '\n';
            return 0;
        } else {
            cout << 0 << '\n';
            return 0;
        }
    } else {
        cout << 0 << '\n';
        return 0;
    }

    return 0;
}
