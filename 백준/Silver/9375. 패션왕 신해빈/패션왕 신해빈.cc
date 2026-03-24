#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>

using namespace std;

typedef long long ll;

int T;

void solve() {

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
		return;
	}

	int ans = 1;
	map<string, int> clothes;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		clothes[b]++;
	}

	//전부 n+1 곱하고 -1 빼주기  = 아무것도 안입는 방법 
	
	for (auto a : clothes) {

		ans *= a.second + 1;

	}
	cout << ans - 1 << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		solve();
	}
	
	
	return 0;
}