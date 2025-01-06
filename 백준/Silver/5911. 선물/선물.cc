#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, B;
	cin >> N >> B;

	vector<pair<ll, ll>> friends(N);  // (P, S)

	for (int i = 0; i < N; i++) {
		cin >> friends[i].first >> friends[i].second; // P(i), S(i)
	}

	ll answer = 0;


	for (int i = 0; i < N; i++) {
	
		vector<ll> cost(N);

		for (int j = 0; j < N; j++) {
			ll P = friends[j].first;
			ll S = friends[j].second;
			if (j == i) {
		
				cost[j] = (P / 2) + S;
			}
			else {
			
				cost[j] = P + S;
			}
		}

		
		sort(cost.begin(), cost.end());

		ll budget = B;
		ll cnt = 0;
		for (int k = 0; k < N; k++) {
			if (budget >= cost[k]) {
				budget -= cost[k];
				cnt++;
			}
			else {
				break;
			}
		}

		answer = max(answer, cnt);
	}

	cout << answer << "\n";
	return 0;
}