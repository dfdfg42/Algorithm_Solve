#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

// 방향 정보 (동, 남, 서, 북)
int dx[4] = { 0, 1, 0, -1 }; // x 변화 (오른쪽, 아래, 왼쪽, 위)
int dy[4] = { 1, 0, -1, 0 }; // y 변화

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));

    // 사과 위치 입력
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 사과가 있는 위치는 1로 설정
    }

    int l;
    cin >> l;
    vector<pair<int, char>> moves;

    // 방향 전환 정보 입력
    for (int i = 0; i < l; i++) {
        int x;
        char d;
        cin >> x >> d;
        moves.push_back({ x, d });
    }

    deque<pair<int, int>> snake; // 뱀의 위치를 저장할 deque
    snake.push_back({ 1, 1 }); // 뱀의 초기 위치 (1, 1)

    int dir = 0; // 초기 방향은 동쪽 (dx, dy의 0번째 인덱스)
    int time = 0;
    int moveIndex = 0; // 다음에 참조할 방향 전환 정보

    while (true) {
        time++; // 시간 증가

        // 뱀의 머리 위치
        int headX = snake.front().first;
        int headY = snake.front().second;

        // 새로운 머리 위치
        int newX = headX + dx[dir];
        int newY = headY + dy[dir];

        // 벽에 부딪히거나 뱀의 몸과 충돌했는지 확인
        if (newX <= 0 || newX > n || newY <= 0 || newY > n ||
            find(snake.begin(), snake.end(), make_pair(newX, newY)) != snake.end()) {
            break; // 벽 또는 몸과 부딪히면 게임 종료
        }

        // 머리를 새로운 위치에 추가
        snake.push_front({ newX, newY });

        // 이동한 위치에 사과가 있으면 사과를 먹고 꼬리는 그대로
        if (board[newX][newY] == 1) {
            board[newX][newY] = 0; // 사과를 먹으면 사과가 사라짐
        }
        else {
            // 사과가 없으면 꼬리를 줄임
            snake.pop_back();
        }

        // 방향 전환 정보가 있으면 방향을 변경
        if (moveIndex < l && moves[moveIndex].first == time) {
            if (moves[moveIndex].second == 'L') {
                dir = (dir + 3) % 4; // 왼쪽 회전
            }
            else if (moves[moveIndex].second == 'D') {
                dir = (dir + 1) % 4; // 오른쪽 회전
            }
            moveIndex++;
        }
    }

    cout << time << '\n'; // 게임이 끝난 시간을 출력

    return 0;
}
