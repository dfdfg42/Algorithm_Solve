#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<bool> row_has_guard(N, false);
    vector<bool> col_has_guard(M, false);

    for (int i = 0; i < N; i++) {
        string status;
        cin >> status;
        for (int j = 0; j < M; j++) {
            if (status[j] == 'X') {
                row_has_guard[i] = true;
                col_has_guard[j] = true;
            }
        }
    }

    int empty_rows = 0;
    for (int i = 0; i < N; i++) {
        if (!row_has_guard[i]) empty_rows++;
    }

    int empty_cols = 0;
    for (int j = 0; j < M; j++) {
        if (!col_has_guard[j]) empty_cols++;
    }

    cout << max(empty_rows, empty_cols) << "\n";

    return 0;
}