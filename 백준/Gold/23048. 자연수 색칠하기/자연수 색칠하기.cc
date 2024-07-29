#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> colors(n + 1, 0); // 색을 저장할 벡터
    int color = 1;

    colors[1] = color; // 1에 색을 할당
    color++;

    for (int i = 2; i <= n; i++) {
        if (colors[i] == 0) { // 아직 색칠되지 않은 경우
            for (int j = i; j <= n; j += i) {
                if (colors[j] == 0) {
                    colors[j] = color;
                }
            }
            color++;
        }
    }

    cout << color - 1 << "\n"; // 사용된 색의 총 개수
    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    }

    return 0;
}
