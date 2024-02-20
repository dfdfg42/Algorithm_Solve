#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[20][20];

// 상하좌우 이동에 대한 인덱스
const int dx[4] = {-1, 1, 0, 0}; // 상, 하
const int dy[4] = {0, 0, -1, 1}; // 좌, 우

// 보드 상태를 복사하는 함수
void copyBoard(int src[20][20], int dest[20][20]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dest[i][j] = src[i][j];
        }
    }
}

// 블록 이동 및 합치기 로직
void moveAndMerge(int direction) {
    bool merged[20][20] = {false}; // 합쳐진 블록을 표시하기 위한 배열
    if (direction == 0 || direction == 2) { // 상, 좌 방향
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 0) continue;
                int x = i + dx[direction];
                int y = j + dy[direction];
                while (x >= 0 && x < N && y >= 0 && y < N) {
                    if (board[x][y] == 0) { // 빈 칸으로 이동
                        board[x][y] = board[x - dx[direction]][y - dy[direction]];
                        board[x - dx[direction]][y - dy[direction]] = 0;
                        x += dx[direction];
                        y += dy[direction];
                    } else if (board[x][y] == board[x - dx[direction]][y - dy[direction]] && !merged[x][y]) {
                        // 같은 값의 블록과 합치기
                        board[x][y] *= 2;
                        board[x - dx[direction]][y - dy[direction]] = 0;
                        merged[x][y] = true;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
    } else { // 하, 우 방향
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (board[i][j] == 0) continue;
                int x = i + dx[direction];
                int y = j + dy[direction];
                while (x >= 0 && x < N && y >= 0 && y < N) {
                    if (board[x][y] == 0) {
                        board[x][y] = board[x - dx[direction]][y - dy[direction]];
                        board[x - dx[direction]][y - dy[direction]] = 0;
                        x += dx[direction];
                        y += dy[direction];
                    } else if (board[x][y] == board[x - dx[direction]][y - dy[direction]] && !merged[x][y]) {
                        board[x][y] *= 2;
                        board[x - dx[direction]][y - dy[direction]] = 0;
                        merged[x][y] = true;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

int findMaxBlock() {
    int maxBlock = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            maxBlock = max(maxBlock, board[i][j]);
        }
    }
    return maxBlock;
}

int dfs(int depth) {
    if (depth == 5) { // 최대 이동 횟수에 도달
        return findMaxBlock();
    }

    int maxBlock = 0, backup[20][20];
    for (int direction = 0; direction < 4; ++direction) {
        copyBoard(board, backup); // 현재 상태 백업
        moveAndMerge(direction); // 이동 및 합치기
        maxBlock = max(maxBlock, dfs(depth + 1)); // 재귀적으로 최대 블록 값 찾기
        copyBoard(backup, board); // 백업에서 원래 상태로 복원
    }
    return maxBlock;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0) << endl;
    return 0;
}
