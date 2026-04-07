#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,k;
    cin >> n >> k ;
    vector<int> stones(n);

    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    sort(stones.begin(), stones.end());

    long long activate = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {

        sum += activate * stones[i];

        activate = min(k, ++activate);
    }

    cout << sum << '\n';

    return 0;
}