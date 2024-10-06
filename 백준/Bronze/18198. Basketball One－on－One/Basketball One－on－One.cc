#include <iostream>
#include <string>

using namespace std;

int main() {
    string record;
    cin >> record;

    int alice_score = 0;
    int barbara_score = 0;

    // 기록을 두 문자씩 (A1, B2 등) 확인
    for (size_t i = 0; i < record.size(); i += 2) {
        char player = record[i];       // A 또는 B
        int points = record[i + 1] - '0'; // 득점 (1 또는 2)

        // 점수 업데이트
        if (player == 'A') {
            alice_score += points;
        } else {
            barbara_score += points;
        }

        // 11점 이상일 때 승리자 결정 (단, 10-10 이후는 별도 처리)
        if (alice_score >= 11 && alice_score - barbara_score >= 2) {
            cout << 'A' << endl;
            return 0;
        }
        if (barbara_score >= 11 && barbara_score - alice_score >= 2) {
            cout << 'B' << endl;
            return 0;
        }
    }

    return 0;
}
