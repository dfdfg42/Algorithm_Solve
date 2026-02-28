#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

typedef long long ll;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    string s;
    cin >> s;

    int cnt = 0;
    
    while (s.length() > 1) {
        ll temp = 0;
        for (int i = 0; i < s.length(); i++) {
            temp += s[i] - '0';
        }
		s = to_string(temp);
		//cout << "temp :" << temp << '\n';
        cnt++;
    }

    cout << cnt << '\n';
	//cout << "s[0] %3 = " << (s[0] - '0') % 3 << '\n';
    if ((s[0] - '0') % 3 == 0 && s[0] != 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }


    return 0;
}