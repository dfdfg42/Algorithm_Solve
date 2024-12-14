#include <iostream>
#include <numeric> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    int ans = 0;

    for (int x1 = 0; x1 <= N; x1++) {
        for (int y1 = 0; y1 <= M; y1++) {
            for (int x2 = 0; x2 <= N; x2++) {
                for (int y2 = 0; y2 <= M; y2++) {
                    // 같은 점이면 무시
                    if (x1 == x2 && y1 == y2) continue;

                    // (x1,y1) < (x2,y2) 조건을 통해 중복 방지
                    if (x1 > x2 || (x1 == x2 && y1 > y2)) continue;

                    int dx = x2 - x1;
                    int dy = y2 - y1;

                    int g = gcd(abs(dx), abs(dy));
                    // 선분 위 격자점 개수: g + 1
                    if (g + 1 == K) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
