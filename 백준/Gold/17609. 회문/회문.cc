#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

typedef long long ll;

void solve() {
	string s;
	cin >> s;

	//좌 우에서 비교
	
	//양 쪽에서 틀리면 좌 +1 이 우랑같지않으면 false
	// 우 -1 이 좌랑 같지않으면 false

	int len = s.length();

	int l = 0;
	int r = len - 1;

	int ans = 0;
	bool isErased = false;
	
	int ans2 = 0;
	int isErased2 = false;

	while (l < r) {
		//cout <<"l:" << l << "r : "<< r << '\n';
		if (s[l] == s[r]) {
			//cout << "1\n";
			l++;
			r--;
			continue;
		}
		else if (isErased == true) {
			ans = 2;
			break;
		}
		else {
			if (s[l + 1] == s[r]) {
				//cout << "! \n";
				l++;
				isErased = true;
				ans = 1;
				continue;
			}
			else if (s[l] == s[r - 1]) {
				//cout << "? \n";
			
				r--;
				isErased = true;
				ans = 1;
				continue;
			}
			ans = 2;
			break;
		}

		ans = 2;
		break;
	}


	 l = 0;
	 r = len - 1;
	 //cout << "=======\n";
	while (l < r) {
		//cout << "l:" << l << "r : " << r << '\n';
		if (s[l] == s[r]) {
			//cout << "1\n";
			l++;
			r--;
			continue;
		}
		else if (isErased2 == true) {
			ans2 = 2;
			break;
		}
		else {
			if (s[l] == s[r - 1]) {
				//cout << "? \n";

				r--;
				isErased2 = true;
				ans2 = 1;
				continue;
			}
			else if (s[l + 1] == s[r]) {
				//cout << "! \n";
				l++;
				isErased2 = true;
				ans2 = 1;
				continue;
			}
			
			ans2 = 2;
			break;
		}

		ans2 = 2;
		break;
	}

	if (ans2 == 0 || ans == 0) {
		cout << 0 << '\n';
	}
	else if (ans == 1 || ans2 == 1) {
		cout << 1 << '\n';
	}
	else {
		cout << 2 << '\n';
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
	
	return 0;
}