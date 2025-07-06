#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>  // std::pair

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll D;
    cin >> N >> D;

    vector<pair<ll, ll>> A(N);
    for (int i = 0; i < N; i++) {

        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end(),
        [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.first < b.first;
        }
    );

    ll curSum = 0;
    ll maxSum = 0;
    int l = 0;
    for (int r = 0; r < N; r++) {
        curSum += A[r].second;

        while (l <= r && A[r].first - A[l].first >= D) {
            curSum -= A[l].second;
            l++;
        }

        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }

    cout << maxSum << "\n";
    return 0;
}
