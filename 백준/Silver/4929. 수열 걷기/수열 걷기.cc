#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;

void solve() {
    while (true) {
        string s1, s2;
        getline(cin, s1);
        if (s1 == "0") return;
        getline(cin, s2);

        // 첫 번째 수열 파싱
        istringstream ss1(s1);
        vector<int> v1;
        int num;
        while (ss1 >> num) {
            v1.push_back(num);
        }

        // 두 번째 수열 파싱
        istringstream ss2(s2);
        vector<int> v2;
        while (ss2 >> num) {
            v2.push_back(num);
        }

        // 첫 번째 원소는 길이이므로 제거
        int n1 = v1[0], n2 = v2[0];
        v1.erase(v1.begin());
        v2.erase(v2.begin());

        // 교차점 찾기
        map<int, int> pos1, pos2; // 값 -> 인덱스
        for (int i = 0; i < n1; i++) {
            pos1[v1[i]] = i;
        }
        for (int i = 0; i < n2; i++) {
            pos2[v2[i]] = i;
        }

        vector<int> intersections;
        for (int i = 0; i < n1; i++) {
            if (pos2.count(v1[i])) {
                intersections.push_back(v1[i]);
            }
        }

        // DP로 최대 합 계산
        ll result = 0;
        int prev1 = -1, prev2 = -1;
        ll sum1 = 0, sum2 = 0;

        for (int intersection : intersections) {
            int curr1 = pos1[intersection];
            int curr2 = pos2[intersection];

            // 이전 교차점부터 현재 교차점까지의 구간 합 계산
            for (int i = prev1 + 1; i <= curr1; i++) {
                sum1 += v1[i];
            }
            for (int i = prev2 + 1; i <= curr2; i++) {
                sum2 += v2[i];
            }

            // 더 큰 합을 선택
            ll maxSum = max(sum1, sum2);
            result = maxSum;

            // 다음 구간을 위해 초기화
            sum1 = sum2 = maxSum;
            prev1 = curr1;
            prev2 = curr2;
        }

        // 마지막 교차점 이후 남은 구간 처리
        ll remaining1 = 0, remaining2 = 0;
        for (int i = prev1 + 1; i < n1; i++) {
            remaining1 += v1[i];
        }
        for (int i = prev2 + 1; i < n2; i++) {
            remaining2 += v2[i];
        }

        result += max(remaining1, remaining2);

        cout << result << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}