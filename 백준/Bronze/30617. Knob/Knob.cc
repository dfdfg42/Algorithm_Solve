#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int l_prev = 0, r_prev = 0;
    int l, r;
    int fun_score = 0;

    for (int i = 0; i < T; i++) {

        cin >> l >> r;

        if (i > 0) {
            // 재미도 계산
            if (l != 0 && l == l_prev) {
                fun_score++;
            }
            if (r != 0 && r == r_prev) {
                fun_score++;
            }

        }
        if (r != 0 && l == r) {
            fun_score++;
        }

        // 현재 상태를 이전 상태로 업데이트
        l_prev = l;
        r_prev = r;
    }

    cout << fun_score << endl;
    return 0;
}
