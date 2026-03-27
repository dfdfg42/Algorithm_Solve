#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

typedef long long ll;

const int INF = 987654321;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	ll ans = 0;
	int anger = 0;
	for (int i = 0; i < n; i++) {

		int a;
		cin >> a;
		
		if (a == 1) {
			anger++;
			ans += anger;
		}
		else {
			anger -= 1;
			ans += anger;
		}

	}
	
	cout << ans << '\n';

	return 0;
}