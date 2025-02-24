#include <iostream>
using namespace std;

int main() {
    int S, M, L;  // 작은 간식(S), 중간 간식(M), 큰 간식(L) 개수

    // 입력 받기
    cin >> S >> M >> L;

    // 행복 점수 계산
    int happiness_score = S * 1 + M * 2 + L * 3;

    // 결과 출력
    if (happiness_score >= 10) {
        cout << "happy" << endl;
    } else {
        cout << "sad" << endl;
    }

    return 0;
}
