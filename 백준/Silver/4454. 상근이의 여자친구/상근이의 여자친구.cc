#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;


ld ans;

void solve() {

    ld a, b, c, d, m,t;

    while (cin >> a >> b >> c >> d >> m >> t) {
        ld l = 0;
        ld r = 1e9;

        ld prev = 0;
        while (l < r) {
            ld mid = (l + r) / 2;

            if (prev == mid) {
                break;
            }

            //cout << "mid : " << mid << "\n";

            // 소모되는 기름의 양
            ld v = a * (mid * mid * mid * mid) + b * (mid * mid * mid) + c * (mid * mid) + d * mid;

            // 기름이 남는지 확인
            ld s = m / mid; //거리 /속도 = 시간

            //시간 * 기름필요양 <= 총 기름
            if (s * v <= t) {
                l = mid;
                ans = mid;
                prev = mid;

            }
            else {
                r = mid;
                prev = mid;
            }


        }

        ld truncated = floor(ans * 100.0L) / 100.0L;

        cout << fixed;
        cout.precision(2);
        cout << truncated << "\n";

    }
	

   

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();



    return 0;
}