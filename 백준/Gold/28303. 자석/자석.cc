#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = -987654321;

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> left(n,0);
    //좌측 누적합
    left[0] = v[0] + 1 * k;
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], v[i] + (i + 1) * k);
        ans = max(ans, left[i - 1] - v[i] - (i + 1) * k);
    }
    //우측
    vector<int> right(n, 0);
    right[n - 1] = v[n - 1] - n* k;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], v[i] - (i + 1) * k);
        ans = max(ans, right[i + 1] - v[i] + (i + 1) * k);
    }

    
    cout << ans << '\n';

    return 0;
}