#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>   
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

int n;
vector<int> width;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    width.resize(n);
    for (int i = 0; i < n; i++) {
        width[i] = a[i] - b[i];
    }

    vector<int> v(n, INT_MAX);

    int cur = width[0];
    for (int i = 0; i < n; i++) {
        cur = min(cur, width[i]);
        v[i] = cur;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int input;
        cin >> input;
        
        int l = 0, r = n - 1;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid] >= input) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        if (ans == 0 && v[0] < input) cout << 0 << '\n';
        else
        cout << ans +1  << '\n';
    }

    return 0;
}