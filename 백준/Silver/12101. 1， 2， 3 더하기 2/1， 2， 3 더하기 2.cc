#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>

using namespace std;

typedef long long ll;

ll n ,k;
bool findAns;

void dfs(ll& index ,int now ,vector<int>comb) {

	if (now == n) {
		index++;
		if (index == k) {
			for (int i = 0; i < comb.size(); i++) {
				if (i != comb.size() - 1) {
					cout << comb[i] << '+';
				}
				else cout << comb[i];
			}
			cout << '\n';
			findAns = true;
		}
		
		return;
	}

	if (now < n) {

		if (now + 1 <= n) {
			comb.push_back(1);
			dfs(index, now + 1, comb);
			comb.pop_back();
		}

		if (now + 2 <= n) {
			comb.push_back(2);
			dfs(index, now + 2, comb);
			comb.pop_back();
		}

		if (now + 3 <= n) {
			comb.push_back(3);
			dfs(index, now + 3, comb);
			comb.pop_back();
		}
	}


}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> k;
	vector<int> temp;
	ll index = 0;
	dfs(index, 0, temp);

	if (!findAns)cout << -1 << '\n';

	return 0;
}