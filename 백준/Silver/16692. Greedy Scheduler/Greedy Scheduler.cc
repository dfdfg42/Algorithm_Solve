#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> t(c);
    for (int i = 0; i < c; i++) {
        cin >> t[i];
    }

    // 최소 힙을 사용하여 계산대의 남은 시간을 관리
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 처음에 모든 계산대는 비어있으므로, 0초로 초기화
    for (int i = 1; i <= n; i++) {
        pq.push({0, i});
    }

    vector<int> result;
    for (int i = 0; i < c; i++) {
        auto [available_time, cashier] = pq.top();
        pq.pop();

        // 고객을 이 계산대에 할당
        result.push_back(cashier);

        // 계산대의 남은 시간을 갱신
        pq.push({available_time + t[i], cashier});
    }

    // 결과 출력
    for (int cashier : result) {
        cout << cashier << " ";
    }

    return 0;
}
