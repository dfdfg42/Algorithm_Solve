#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int main() {
    
    int N;
    cin >> N;

    vector<int> seq(N + 1,0);
    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }

    vector<int> d(N + 1, INT_MAX);

    int maxLen = 1;
    for (int i = 1; i <= N; i++) {
        d[i] = 1;

        for (int j = 1; j < i; j++) {
            if (seq[j] > seq[i] && d[i] < d[j] + 1) {
                d[i] = d[j]+1;

                maxLen = max(d[i], maxLen);
            }
        }
    }
    
    cout << maxLen << "\n";

    return 0;
}
