#include <iostream>
#include <vector>
using namespace std;

int N, answer = 0;
vector<int> row; // row[i]는 i번째 행의 퀸의 위치 (열 번호)

// 현재 위치에 퀸을 놓을 수 있는지 체크
bool isPromising(int currentRow) {
    for (int i = 0; i < currentRow; ++i) {
        // 같은 열 또는 대각선 상에 퀸이 있는지 확인
        if (row[i] == row[currentRow] || abs(row[currentRow] - row[i]) == abs(currentRow - i)) {
            return false;
        }
    }
    return true;
}

// 백트래킹을 이용하여 모든 경우의 수 탐색
void solve(int currentRow) {
    if (currentRow == N) { // 모든 행에 퀸을 놓았다면
        ++answer; // 경우의 수 증가
    } else {
        for (int i = 0; i < N; ++i) {
            row[currentRow] = i; // 현재 행에 퀸을 놓음
            if (isPromising(currentRow)) { // 유효한 위치라면 다음 행으로
                solve(currentRow + 1);
            }
        }
    }
}

int main() {
    cin >> N;
    row.resize(N);
    solve(0); // 0번 행부터 시작
    cout << answer;
    return 0;
}
