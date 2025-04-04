#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }
    int group_start = cards[0];
    long long score = 0;

    for (int i = 1; i < N; ++i) {

        if (cards[i] != cards[i - 1] + 1) {
            score += group_start;   
            group_start = cards[i]; 
        }
    }

    score += group_start;

    cout << score << "\n";
    return 0;
}
