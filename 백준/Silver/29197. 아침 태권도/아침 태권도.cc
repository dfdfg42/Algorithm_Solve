#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> slopes;
    int z = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x == 0) {
            // 수직선에 있는 경우
            z |= (y > 0 ? 1 : 2); // y > 0이면 1, y < 0이면 2
        } else if (y == 0) {
            // 수평선에 있는 경우
            z |= (x > 0 ? 4 : 8); // x > 0이면 4, x < 0이면 8
        } else {
            // 기울기 정규화 및 사분면 구분
            int g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;
            if (x < 0) { // x를 양수로 정규화
                x = -x;
                y = -y;
            }
            slopes.insert({x, y});
        }
    }

    int result = slopes.size();
    if (z & 1) result++; // 양의 y축 방향
    if (z & 2) result++; // 음의 y축 방향
    if (z & 4) result++; // 양의 x축 방향
    if (z & 8) result++; // 음의 x축 방향

    cout << result << '\n';

    return 0;
}
