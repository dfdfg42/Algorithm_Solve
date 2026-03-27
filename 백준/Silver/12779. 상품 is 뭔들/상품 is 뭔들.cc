#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const int INF = 987654321;

ll a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	int cnt = 0;
	for (ll i = sqrt(a); i*i <= b; i++) {

		cnt += i * i > a ? 1 : 0;

	}
	if (cnt == 0) {
		cout << 0 << endl;
		return 0;
	}

	//cout << cnt << '\n';

	//a b 사이의 약수가 홀수인거의 개수 /  전체 범위  -> 기약분수로 표현

	ll m = b - a;
	ll g = gcd(b - a, cnt);
	cout << cnt / g << "/" << m / g << '\n';

	return 0;
}