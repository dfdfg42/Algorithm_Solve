#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;


    vector<vector<int>> hear(N, vector<int>(M));

    vector<int> total(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> hear[i][j];
            total[i] += hear[i][j];
        }
    }

    vector<int> order(N);
    for (int i = 0; i < N; i++) order[i] = i;
    sort(order.begin(), order.end(), [&](int a, int b) {
        return total[a] > total[b];
        });

    for (int j = 0; j < M; j++) {
        bool seenZero = false;
        for (int idx : order) {
            if (hear[idx][j] == 0) {
                seenZero = true;
            }
            else if (seenZero && hear[idx][j] == 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}
