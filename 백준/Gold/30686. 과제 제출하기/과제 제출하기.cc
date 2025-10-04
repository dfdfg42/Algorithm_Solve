#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

	vector<int> d(n+1);
	for (int i = 0; i < n; ++i) {
		cin >> d[i+1];
	}
	vector<vector<int>> problems(m, vector<int>());
	vector<int> num;

	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int p;
			cin >> p;
			problems[i].push_back(p);
		}
		num.push_back(i + 1);
	}

	int ans = INT_MAX;


	do {
		//for (auto b : num) cout << b << ' ';
		//cout << '\n';

		vector<int> lastSolve(n + 1, 0);
		int temp = 0;
		int day = 0; 
		for (int i = 0; i < m; i++) {
			int cur = i + 1;
			day++;
			for (auto a : problems[num[i]-1]) {
				//cout << a << ' ';
				
				if (lastSolve[a] <= day) {
					temp++;
					lastSolve[a] = day + d[a];
				}
				//cout << lastSolve[a] << '\n';
			}
		}

		ans = min(temp, ans);

	} while (next_permutation(num.begin(), num.end()));
	
	cout << ans << '\n';

    return 0;
}