#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> w(n + 1), psum(n + 1);

    // 입력받으며 누적합 계산
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        psum[i] = psum[i - 1] + w[i];
    }

    long long minDiff = LLONG_MAX; 
    long long ans = 0;          

    // mid를 기준으로 왼쪽 [left..mid], 오른쪽 [mid+1..right] 구간을 확장
    for (int mid = 1; mid < n; mid++) {
        int left = mid;
        int right = mid + 1;

        while (left >= 1 && right <= n) {
           
            long long leftSum = psum[mid] - psum[left - 1];

            long long rightSum = psum[right] - psum[mid];

            long long diff = llabs(leftSum - rightSum);


            if (diff < minDiff) {
                minDiff = diff;
                ans = leftSum + rightSum;
            }
            else if (diff == minDiff && (leftSum + rightSum) > ans) {
                ans = leftSum + rightSum;
            }


            if (leftSum > rightSum) right++;
            else                   left--;
        }
    }

    cout << ans << "\n";
    return 0;
}
