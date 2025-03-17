#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ans(n + 1, 0);

    vector<bool> used(n + 1, false);

    // 2n 이하의 가장 큰 2의 거듭제곱을 찾는다.
    int power = 1;
    while (power <= 2 * n) {
        power *= 2;
    }
    power /= 2;


    while (power >= 2) {
        // i와 (power - i)가 모두 [1, n] 범위에 있을 조건: 
        // i >= max(1, power - n) and i <= floor((power-1)/2)
        int start = max(1, power - n);
        int end = (power - 1) / 2;
        for (int i = start; i <= end; i++) {
            int j = power - i;
            if (j <= n && !used[i] && !used[j]) {
                ans[i] = j;
                ans[j] = i;
                used[i] = used[j] = true;
            }
        }
        // power가 짝수인 경우, i = power/2 일 때 자기 자신과 페어링하는 경우
        if (power % 2 == 0) {
            int i = power / 2;
            if (i >= start && i <= n && !used[i]) {
                ans[i] = i;
                used[i] = true;
            }
        }
        power /= 2;
    }

    // 아직 페어링되지 않은 덩어리는 자기 자신과 페어링
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ans[i] = i;
        }
    }


    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
