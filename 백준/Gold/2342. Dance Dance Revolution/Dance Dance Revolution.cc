#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 사용
using namespace std;

const int INF = 1e9;
int dp[100001][5][5];

// 이동 비용 계산 함수
int moveCost(int from, int to) {
    if (from == 0) return 2; // 중앙에서 이동
    if (from == to) return 1; // 같은 위치
    if (abs(from - to) == 2) return 4; // 반대편 이동
    return 3; // 인접 이동
}

int solve(const vector<int>& vec, int step, int left, int right) {
    if (step == vec.size()) return 0; // 모든 지시 사항을 처리했을 경우
    if (dp[step][left][right] != -1) return dp[step][left][right]; // 이미 계산된 경우

    int next = vec[step];
    int toLeft = moveCost(left, next) + solve(vec, step + 1, next, right); // 왼쪽 발 이동
    int toRight = moveCost(right, next) + solve(vec, step + 1, left, next); // 오른쪽 발 이동

    return dp[step][left][right] = min(toLeft, toRight); // 최소 비용을 dp에 저장
}

int main() {
    vector<int> vec;
    int input;
    while (cin >> input && input) {
        vec.push_back(input);
    }

    memset(dp, -1, sizeof(dp)); // dp 배열 초기화
    cout << solve(vec, 0, 0, 0) << endl; // 최소 힘 계산 및 출력

    return 0;
}
