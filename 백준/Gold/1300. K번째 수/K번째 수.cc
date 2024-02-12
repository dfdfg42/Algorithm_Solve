#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long k;
    cin >> N >> k;

    long long left = 1, right = (long long)N * N, ans = 0;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;
        
        // mid보다 작거나 같은 수의 개수를 계산
        for (int i = 1; i <= N; i++) {
            count += min(mid / i, (long long)N);
        }
        
        // k번째 수를 찾는 조건 검사
        if (count < k) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
