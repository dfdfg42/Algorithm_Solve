#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>

using namespace std;

vector<int> primes;

void solve() {
	int k;
	cin >> k;


	int l = 0, r = primes.size() - 1;
	int ansIdx = 0; 

	while (l <= r) {
		int mid = (l + r) / 2;
		if (primes[mid] > k) {
			r = mid - 1;
		}
		else {
			ansIdx = mid;   
			l = mid + 1;
		}
	}

	if (primes[ansIdx] == k) {
		cout << 0 << '\n';
		return;
	}

	cout << primes[ansIdx + 1] - primes[ansIdx] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<bool> check(1299710, false);

	for (int i = 2; i <= 1299709; i++) {
		
		if (!check[i]) {
			primes.push_back(i);
			for (int j = i; j <= 1299709; j += i) {
				check[j] = true;
			}
		}

	}

	//for (auto a : primes) {
	//	cout << a << '\n';
	//}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}