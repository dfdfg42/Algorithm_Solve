#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, k;
    cin >> n >> k;

    vector<int> dolls(n);
    for (int i = 0; i < n; i++) {
        cin >> dolls[i];
    }

    int left = 0;
    int count = 0;
    int ans = INT_MAX;
    for (int right = 0; right < n; right++) {

        if (dolls[right] == 1) {
            count++;
        }

        while (count >= k && left <= right) {

            ans = min(ans, right - left+1);

            if (dolls[left] == 1) {
                count--;
            }
            left++;
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << '\n';
    }
    else cout << ans << '\n';

    return 0;
}
