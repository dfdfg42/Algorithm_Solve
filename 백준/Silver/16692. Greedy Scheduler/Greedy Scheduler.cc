#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> times(c);
    for (int i = 0; i < c; i++) {
        cin >> times[i];
    }

    vector<int> cashier(n, 0);  // 각 계산대의 남은 시간
    vector<int> ans(c);  // 각 고객이 배정된 계산대 번호를 저장

    for (int i = 0; i < c; i++) {
        // 가장 빨리 비는 계산대를 찾기
        int min_time = cashier[0];
        int min_index = 0;

        for (int j = 1; j < n; j++) {
            if (cashier[j] < min_time) {
                min_time = cashier[j];
                min_index = j;
            }
        }

        // 고객을 가장 빨리 비는 계산대에 배치
        ans[i] = min_index + 1;
        cashier[min_index] += times[i];  // 해당 계산대의 남은 시간 갱신
    }

    // 결과 출력
    for (int a : ans) {
        cout << a << " ";
    }

    return 0;
}
