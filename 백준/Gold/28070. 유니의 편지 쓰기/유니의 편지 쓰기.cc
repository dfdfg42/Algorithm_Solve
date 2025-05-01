#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    const int BASE = 2000;

    vector<pair<int, int>> ranges;
    ranges.reserve(N);
    int max_idx = 0;

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        int sy = stoi(a.substr(0, 4));
        int sm = stoi(a.substr(5, 2));
        int ey = stoi(b.substr(0, 4));
        int em = stoi(b.substr(5, 2));

        int si = (sy - BASE) * 12 + (sm - 1);
        int ei = (ey - BASE) * 12 + (em - 1);
        ranges.emplace_back(si, ei);
        max_idx = max(max_idx, ei);
    }


    vector<int> diff(max_idx + 2, 0);
    for (auto& r : ranges) {
        diff[r.first] += 1;
        diff[r.second + 1] -= 1;
    }


    int best_cnt = 0, best_idx = 0, cur = 0;
    for (int i = 0; i <= max_idx; i++) {
        cur += diff[i];
        if (cur > best_cnt) {
            best_cnt = cur;
            best_idx = i;
        }
    }


    int year = BASE + best_idx / 12;
    int month = best_idx % 12 + 1;
    cout << year << '-'
        << setw(2) << setfill('0') << month
        << '\n';

    return 0;
}
