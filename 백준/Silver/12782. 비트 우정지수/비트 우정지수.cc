#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]-'0' == 1 && b[i]-'0' == 0) cnt1++;
            if (b[i] - '0' == 1 && a[i] - '0' == 0) cnt2++;
        }

        int ans = abs(cnt1 - cnt2);
        if (cnt1 < cnt2) ans += cnt1;
        else ans += cnt2;

        cout << ans << '\n';
    }
    

    return 0;
}
