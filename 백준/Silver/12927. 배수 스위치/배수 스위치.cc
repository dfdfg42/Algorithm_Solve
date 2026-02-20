#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        int index = i + 1;
        if (s[i] == 'Y') {
            for (int i = index-1; i < s.length(); i += index) {
                s[i] = (s[i] == 'Y') ? 'N' : 'Y';
            }
            ans++;
        }

    }
    cout << ans << '\n';
    return 0;
}