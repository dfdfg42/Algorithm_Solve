#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	if (!(cin >> N)) return 0;

	vector<int> tang(N);

	vector<int> cnt(11, 0);

	for (int i = 0; i < N; i++) {
		cin >> tang[i];
	}

	int fruitType = 0;
	int ans = 0;
	int l = 0;

	for (int r = 0; r < N; r++) {

		if (cnt[tang[r]] == 0) {
			fruitType++;
		}
		cnt[tang[r]]++;


		while (fruitType > 2) {
			cnt[tang[l]]--;

			if (cnt[tang[l]] == 0) {
				fruitType--;
			}
			l++;
		}

		ans = max(ans, r - l + 1);
	}

	cout << ans << '\n';

	return 0;
}