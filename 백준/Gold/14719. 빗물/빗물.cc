#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    vector<int> blocks(W);

    for (int i = 0; i < W; i++) {
        cin >> blocks[i];
    }

    vector<int> left_max(W), right_max(W);

    left_max[0] = blocks[0];
    for (int i = 1; i < W; i++) {
        left_max[i] = max(left_max[i - 1], blocks[i]);
    }

    right_max[W - 1] = blocks[W - 1];
    for (int i = W - 2; i >= 0; i--) {
        right_max[i] = max(right_max[i + 1], blocks[i]);
    }

    int waterResult = 0;

    for (int i = 0; i < W; i++) {
        waterResult += min(left_max[i], right_max[i]) - blocks[i];
    }

    cout << waterResult << "\n";

    return 0;
}
