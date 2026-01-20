#include <iostream>
#include <string>

using namespace std;

int prefix_sum[26][200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    string S, T;
    cin >> S >> T;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            prefix_sum[j][i + 1] = prefix_sum[j][i];
        }
        prefix_sum[S[i] - 'a'][i + 1]++;
    }

    long long total_similarity = 0;
    int diff = N - M;

    for (int j = 0; j < M; j++) {
        int char_idx = T[j] - 'a';
        int L = j;
        int R = j + diff;
        total_similarity += (prefix_sum[char_idx][R + 1] - prefix_sum[char_idx][L]);
    }

    cout << total_similarity << "\n";

    return 0;
}