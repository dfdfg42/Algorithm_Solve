#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;  // N의 값을 입력받습니다.

    vector<ll> liquids(N);

    for (int i = 0; i < N; i++) {
        cin >> liquids[i];
    }

    sort(liquids.begin(), liquids.end());

    ll closestSum = LLONG_MAX;
    int trueAnswers[3] = { -1, -1, -1 };

    // 첫 번째 용액을 고정합니다.
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;
        
        // 두 번째와 세 번째 용액을 탐색합니다.
        while (left < right) {
            ll sum = liquids[i] + liquids[left] + liquids[right];
            if (abs(sum) < abs(closestSum)) {
                closestSum = abs(sum);  // 최소 합을 업데이트합니다.
                trueAnswers[0] = liquids[i];
                trueAnswers[1] = liquids[left];
                trueAnswers[2] = liquids[right];
            }
            
            // 합을 조절하여 0에 더 가까운 조합을 찾습니다.
            if (sum > 0) {
                right--;
            } else {
                left++;
            }
        }
    }

    cout << trueAnswers[0] << " " << trueAnswers[1] << " " << trueAnswers[2] << '\n';
    return 0;
}
