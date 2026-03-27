#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	ll pow2 = 1;
	while (pow2 * 2 < n) pow2 *= 2;

	ll baseCuts = pow2 - 1;
	ll extraCuts = (n + 1) / 2;

	cout << baseCuts + extraCuts;

	return 0;
}