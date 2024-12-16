#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> holes(N);
    for (int i = 0; i < N; i++) {
        cin >> holes[i];
    }

    long long ans = 0;
    long long sum = 0;
    int left = 0;

    for (int right = 0; right < N; right++) {
        // 현재 구멍 추가
        sum += holes[right];

        // 만약 합이 M을 초과한다면 left를 이동하며 sum 감소
        while (sum > M && left <= right) {
            sum -= holes[left++];
        }

        // 현재 sum이 M 이하이면 최대값 갱신
        if (sum <= M) {
            ans = max(ans, sum);
        }
    }

    cout << ans << "\n";

    return 0;
}
