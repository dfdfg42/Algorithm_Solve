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


    //우로 증가하는 수열 길이
    vector<int> d(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        d[i] = 1;

        for (int j = 1; j < i; j++) {
            if (seq[j] < seq[i] && d[i] < d[j] + 1) {
                d[i] = d[j]+1;
            }
        }
    }

    //좌로 증가하는 수열 길이
    vector<int> p(N + 1, 1);
    for (int i = N; i >=1 ; i--) {
        p[i] = 1;

        for (int j = N; j > i; j--) {
            if (seq[j] < seq[i] && p[i] < p[j] + 1) {
                p[i] = p[j] + 1;
            }
        }
    }
    
    int maxLen = 1;

    for (int i = 1; i <= N; i++) {
        maxLen = max(d[i] + p[i] - 1, maxLen);
    }
    cout << maxLen << "\n";

    return 0;
}
