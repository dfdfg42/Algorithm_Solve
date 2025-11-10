#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

typedef long long ll;


void solve() {

	int k;
	cin >> k;

	priority_queue<ll , vector<ll> ,greater<ll>> pq;
	
	for (int i = 0; i < k; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}

	ll cost = 0;
	while (true) {
		
		ll first = pq.top();
		pq.pop();
		if (pq.empty()) break;

		ll second = pq.top();
		pq.pop();
		cost += first + second;
		//cout << "first " << first << " second " << second << '\n';
		pq.push(first + second);

	}

	cout << cost << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
	
}
