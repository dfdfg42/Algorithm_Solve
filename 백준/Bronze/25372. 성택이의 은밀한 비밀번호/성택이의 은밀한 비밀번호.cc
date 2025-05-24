#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string s;
    while (N--) {
        cin >> s;
        int len = s.size();
        // 비밀번호 길이 확인 (6 이상 9 이하)
        if (len >= 6 && len <= 9) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
