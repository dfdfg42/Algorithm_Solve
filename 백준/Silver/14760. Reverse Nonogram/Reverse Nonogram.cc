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

        // 각 행에 대해 숫자들을 저장하는 벡터
        vector<vector<int>> row_nums(n);
        // 각 열에 대해 숫자들을 저장하는 벡터
        vector<vector<int>> col_nums(n);

        // 열 탐색 (각 행에 대해서)
        for (int i = 0; i < n; i++) {
            int seq = 0;
            for (int j = 0; j < n; j++) {
                if (nng[i][j] == 'X') seq++;
                else {
                    if (seq != 0) {
                        row_nums[i].push_back(seq);
                        seq = 0;
                    }
                }
            }
            if (seq != 0) {
                row_nums[i].push_back(seq);
            }
        }

        // 행 탐색 (각 열에 대해서)
        for (int i = 0; i < n; i++) {
            int seq = 0;
            for (int j = 0; j < n; j++) {
                if (nng[j][i] == 'X') seq++;
                else {
                    if (seq != 0) {
                        col_nums[i].push_back(seq);
                        seq = 0;
                    }
                }
            }
            if (seq != 0) {
                col_nums[i].push_back(seq);
            }
        }

        // 결과 출력: 행부터 출력
        for (int i = 0; i < n; i++) {
            if (row_nums[i].empty()) cout << "0";
            else {
                for (auto a : row_nums[i]) {
                    cout << a << ' ';
                }
            }
            cout << '\n';
        }

        // 결과 출력: 열 출력
        for (int i = 0; i < n; i++) {
            if (col_nums[i].empty()) cout << "0";
            else {
                for (auto a : col_nums[i]) {
                    cout << a << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
