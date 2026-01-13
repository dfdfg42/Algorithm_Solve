#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;


	ll l = 0, r = n/2;

	bool ans = false;
	while (l <= r) {
		ll mid = (l + r) / 2;

		ll temp = (mid + 1) * (n - mid + 1);
		if (temp == k) {
			ans = true;
			break;
		}
		else if (temp > k) r = mid - 1;
		else l = mid + 1;

	}

	if (ans) cout << "YES";
	else cout << "NO";
	return 0;

	return 0;
}