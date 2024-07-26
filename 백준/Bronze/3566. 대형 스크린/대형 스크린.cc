#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Monitor {
    int rh, rv, sh, sv, price;
};

int main() {
    int target_rh, target_rv, target_sh, target_sv;
    cin >> target_rh >> target_rv >> target_sh >> target_sv;

    int n;
    cin >> n;

    vector<Monitor> monitors(n);
    for (int i = 0; i < n; ++i) {
        cin >> monitors[i].rh >> monitors[i].rv >> monitors[i].sh >> monitors[i].sv >> monitors[i].price;
    }

    int min_cost = INT_MAX;

    for (const auto& monitor : monitors) {
        // (1) Monitor를 회전하지 않은 경우
        int configs[2][4] = {
            {monitor.rh, monitor.rv, monitor.sh, monitor.sv},
            {monitor.rv, monitor.rh, monitor.sv, monitor.sh}
        };

        for (int i = 0; i < 2; ++i) {
            int rh = configs[i][0];
            int rv = configs[i][1];
            int sh = configs[i][2];
            int sv = configs[i][3];

            // 필요한 가로, 세로 모니터 개수 계산
            int needed_h_monitors_res = (target_rh + rh - 1) / rh;
            int needed_v_monitors_res = (target_rv + rv - 1) / rv;
            int needed_h_monitors_size = (target_sh + sh - 1) / sh;
            int needed_v_monitors_size = (target_sv + sv - 1) / sv;

            // 해상도와 크기 중 더 큰 값으로 결정
            int needed_h_monitors = max(needed_h_monitors_res, needed_h_monitors_size);
            int needed_v_monitors = max(needed_v_monitors_res, needed_v_monitors_size);

            // 총 필요한 모니터 개수
            int needed_monitors = needed_h_monitors * needed_v_monitors;

            // 총 비용 계산
            int total_cost = needed_monitors * monitor.price;

            // 최소 비용 갱신
            min_cost = min(min_cost, total_cost);
        }
    }

    cout << min_cost << endl;

    return 0;
}
