#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<vector<char>> nng(n);

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                nng[i].push_back(s[j]);
            }
        }

        vector<vector<int>> nums(2 * n);

        // 열 탐색 (각 행에 대해)
        for (int i = 0; i < n; i++) {
            int seq = 0;
            for (int j = 0; j < n; j++) {
                if (nng[i][j] == 'X') seq++;
                else {
                    if (seq != 0) {
                        nums[i].push_back(seq);  // 행 탐색 결과 저장
                        seq = 0;
                    }
                }
            }
            if (seq != 0) {
                nums[i].push_back(seq);
            }
        }

        // 행 탐색 (각 열에 대해)
        for (int i = 0; i < n; i++) {
            int seq = 0;
            for (int j = 0; j < n; j++) {
                if (nng[j][i] == 'X') seq++;
                else {
                    if (seq != 0) {
                        nums[n + i].push_back(seq);  // 열 탐색 결과 저장
                        seq = 0;
                    }
                }
            }
            if (seq != 0) {
                nums[n + i].push_back(seq);
            }
        }

        // 출력: 행 결과 먼저
        for (int i = 0; i < n; i++) {
            if (nums[i].empty()) cout << "0";
            else {
                for (auto a : nums[i]) {
                    cout << a << ' ';
                }
            }
            cout << '\n';
        }

        // 출력: 열 결과 나중에
        for (int i = 0; i < n; i++) {
            if (nums[n + i].empty()) cout << "0";
            else {
                for (auto a : nums[n + i]) {
                    cout << a << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
