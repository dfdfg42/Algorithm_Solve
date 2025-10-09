#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>   
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

   
    vector<long long> v(n);
    bool all_same = true;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (i > 0 && v[i] != v[0]) {
            all_same = false;
        }
    }

    if (all_same) {
        std::cout << "INFINITY\n";
        return;
    }


    long long result_gcd = std::abs(v[1] - v[0]);
    for (int i = 2; i < n; ++i) {
        result_gcd = gcd(result_gcd, std::abs(v[i] - v[0]));
    }

    std::cout << result_gcd << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}