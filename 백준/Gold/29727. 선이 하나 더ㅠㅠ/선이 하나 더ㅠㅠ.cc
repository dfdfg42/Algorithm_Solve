#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // max, min 사용을 위해

using namespace std;

typedef long long ll;

ll comb(ll n) {
    if (n < 2) return 0;
    return n * (n - 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;


    ll base_lines = comb(N + 1);
    ll ans = base_lines * base_lines;

    if (xa == xb || ya == yb) {

        ll valid_lines_count = 0;

        if (xa == xb) {
            int start_y = min(ya, yb) + 1;
            int end_y = max(ya, yb);

            int real_start = max(start_y, 0);
            int real_end = min(end_y, N);

            if (real_end >= real_start) {
                valid_lines_count = real_end - real_start + 1;
            }
        }
        else {
            int start_x = min(xa, xb) + 1;
            int end_x = max(xa, xb);

            int real_start = max(start_x, 0);
            int real_end = min(end_x, N);

            if (real_end >= real_start) {
                valid_lines_count = real_end - real_start + 1;
            }
        }

       
        ans += comb(valid_lines_count) * (N + 1);
    }

    cout << ans << '\n';

    return 0;
}