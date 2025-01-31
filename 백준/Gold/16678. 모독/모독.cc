#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> honor(N);
    for (int i = 0; i < N; i++) {
        cin >> honor[i];
    }

    sort(honor.begin(), honor.end());

    ll cost = 0;

    if (honor[0] != 1) {
        cost += honor[0] - 1; 
        honor[0] = 1;
    }
    for (int i = 1; i < N; i++) {
        
        if (honor[i-1] < honor[i]) {
            cost += honor[i] - (honor[i - 1] + 1);
            honor[i] = honor[i - 1] + 1;
        }
        
    }

    cout << cost << "\n";
    return 0;
}