#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string K;
    if (!(cin >> N >> K)) return 0;

    long long even_cnt = 0, odd_cnt = 0;
    for (char c : K) {
        int d = c - '0';
        if (d % 2 == 0) ++even_cnt; // 0도 짝수
        else ++odd_cnt;
    }

    if (even_cnt > odd_cnt) cout << 0 << '\n';
    else if (odd_cnt > even_cnt) cout << 1 << '\n';
    else cout << -1 << '\n';

    return 0;
}
