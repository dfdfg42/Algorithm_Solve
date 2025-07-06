#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    // 1. R의 개수 누적 합 계산
    vector<int> r_prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        r_prefix_sum[i + 1] = r_prefix_sum[i] + (s[i] == 'R' ? 1 : 0);
    }

    // R로만 이루어진 경우를 초기 최댓값으로 설정
    int max_len = r_prefix_sum[n];
    if (max_len == n && n > 0) { // 전부 R인 경우
        cout << n << endl;
        return 0;
    }
    if (max_len == 0) { // R이 하나도 없는 경우
        cout << 0 << endl;
        return 0;
    }


    int l = 0;
    int r = n - 1;
    int k_count = 0; // K의 개수 (쌍이 아니므로 1씩 증가)

    while (l < r) {
        // 2. 양쪽에서 K를 찾음
        while (l < n && s[l] != 'K') {
            l++;
        }
        while (r >= 0 && s[r] != 'K') {
            r--;
        }

        // 포인터가 엇갈리면 더 이상 K 쌍을 만들 수 없음
        if (l >= r) {
            break;
        }

        // K 쌍을 찾음
        k_count += 2;

        // 3. 현재 K 쌍을 기준으로 최대 길이 계산
        // 현재 k_count개의 K와 그 사이에 있는 R들의 합
        int r_between = r_prefix_sum[r] - r_prefix_sum[l + 1];
        if (r_between > 0) {
            max_len = max(max_len, k_count + r_between);
        }

        // 다음 쌍을 찾기 위해 포인터 이동
        l++;
        r--;
    }

    cout << max_len << endl;

    return 0;
}