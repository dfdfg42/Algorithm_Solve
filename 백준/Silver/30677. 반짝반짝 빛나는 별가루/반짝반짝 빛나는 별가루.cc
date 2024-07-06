#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, K, C, R;
    cin >> N >> K >> C >> R;

    vector<int> base(K);
    vector<int> s(K);
    vector<int> p(K);

    for (int i = 0; i < K; i++) {
        cin >> base[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> p[i];
    }

    vector<int> skill(K, 0);
    int combo = 0;
    int stress = 0;
    long long total_stardust = 0;  // Use long long to avoid overflow

    for (int i = 0; i < N; i++) {
        int act;
        cin >> act;

        if (act == 0) {
            stress -= R;
            if (stress < 0) stress = 0;
            combo = 0;
        } else {
            int idx = act - 1;
            stress += p[idx];
            if (stress > 100) {
                cout << -1 << '\n';
                return 0;
            }
            long long combo_bonus = 100 + combo * C;
            long long skill_bonus = 100 + skill[idx] * s[idx];
            long long delta_stardust = floor((base[idx] * combo_bonus * skill_bonus) / 10000.0);
            total_stardust += delta_stardust;
            combo++;
            skill[idx]++;
        }
    }

    cout << total_stardust << '\n';

    return 0;
}
