#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<int> seq(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }

    vector<int> d(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        d[i] = seq[i];
        for (int j = 1; j < i; j++) {
            if (seq[j] < seq[i] && d[i] < d[j] + seq[i]) {
                d[i] = d[j] + seq[i];
            }
        }
    }
    
    cout << *max_element(d.begin(), d.end()) << "\n";

    return 0;
}
