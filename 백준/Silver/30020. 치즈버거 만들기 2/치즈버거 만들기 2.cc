#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// PBDS

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll A, B;
    cin >> A >> B;

    // 조건을 만족하지 않는 경우
    if (A <= B || A > 2 * B) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    vector<string> ans;

    // A와 B의 차이가 1이 될 때까지 'aba'를 추가
    while (B + 1 != A) {
        ans.push_back("aba");
        A -= 2;
        B -= 1;
    }

    // 정답의 개수 출력
    cout << ans.size() + 1 << "\n";

    // 저장된 'aba' 문자열 출력
    for (string s : ans) {
        cout << s << "\n";
    }

    // 남은 패티와 치즈로 'ab'를 반복 출력하고 마지막에 'a' 추가
    for (int i = 0; i < B; ++i) {
        cout << "ab";
    }
    cout << "a" << "\n";

    return 0;
}
