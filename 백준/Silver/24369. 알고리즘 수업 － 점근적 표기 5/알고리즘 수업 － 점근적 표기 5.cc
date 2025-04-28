#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a2, a1, a0, c, n0;
    cin >> a2 >> a1 >> a0 >> c >> n0;

    // h(n) = f(n) - c·n² = (a2–c)n² + a1·n + a0  의 계수
    ll A = a2 - c;
    ll B = a1;
    ll C = a0;

    // 1) A < 0 이면 n→∞ 에서 h(n) → -∞ 이므로 무조건 실패
    if (A < 0) {
        cout << 0;
        return 0;
    }

    // 2) A == 0 이면 h(n) = B·n + C 가 1차식
    if (A == 0) {
        if (B < 0) {
            cout << 0;
        }
        else if (B == 0) {
            cout << (C >= 0);
        }
        else {
            cout << (B * n0 + C >= 0);
        }
        return 0;
    }

    // 3) A > 0 이면 위로 볼록인 이차식 → 허근인지, 아니면 실근이 나오는지 판별
    long double D = (long double)B * B - 4.0L * A * C;
    if (D <= 0) {
        cout << 1;
        return 0;
    }

    // 실근이 두 개 r1 ≤ r2 로 존재 
    long double sqrtD = sqrt(D);
    long double r2 = (-(long double)B + sqrtD) / (2.0L * A);

    // n ≥ n0 구간이 (r1,r2) 안으로 들어가지 않으려면 n0 ≥ r2 이어야 함
    if ((long double)n0 + 1e-15L >= r2) cout << 1;
    else                                cout << 0;

    return 0;
}
