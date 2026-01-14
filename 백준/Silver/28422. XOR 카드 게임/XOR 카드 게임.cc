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


vector<int> dp; //  dp[i] = i번째카드까지 고려했을 때 최대값
vector<int> v;
int n;

int xorResult(int index, int cnt) {

	int point = 0;
	int val = 0;
	for (int i = 0; i < cnt; i++) {
		val ^= v[index + i]; // index부터 아래로  cnt 장 xor
	}

	for (int i = 0; i < 30; i++) { 
		if (val & (1 << i)) { // 0이 아니면 1이 있는 것임
			point++;
		}
	}
	

	return point;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n,-1);
	dp.resize(n + 1,-1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	dp[n] = 0;

	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}



	for (int i = n - 2; i >= 0; i--) {


		if (i + 2 <= n && dp[i + 2] != -1) {
			dp[i] = max(dp[i], dp[i + 2] + xorResult(i, 2));
		}

		if (i + 3 <= n && dp[i + 3] != -1) {
			dp[i] = max(dp[i], dp[i + 3] + xorResult(i, 3));
		}
	}

	if (dp[0] == -1) cout << 0 << '\n';
	else cout << dp[0] << '\n';
	

	return 0;
}