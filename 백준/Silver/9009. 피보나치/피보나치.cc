#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

typedef long long ll;

vector<ll> fibo;

void solve() {

	int n, t;
	cin >> n;

	vector<int> result;
	for (int i = 45; i >= 0; i--) {

		if (fibo[i] <= n) {
			n -= fibo[i];
			result.push_back(fibo[i]);
		}

		if (n == 0) break;

	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fibo.resize(46);
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i < 46; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
	
	
	return 0;
}