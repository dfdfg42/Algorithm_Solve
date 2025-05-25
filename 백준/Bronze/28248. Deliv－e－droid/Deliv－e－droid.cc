#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P, C;
    cin >> P >> C;

    // 기본 점수 계산
    long long score = 50LL * P - 10LL * C;
    // 보너스 조건
    if (P > C) {
        score += 500;
    }

    cout << score << "\n";
    return 0;
}
