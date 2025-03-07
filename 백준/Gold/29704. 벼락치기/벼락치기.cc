#include <iostream>
#include <vector>
#include <climits>

const int INF = INT_MAX;

using namespace std;
int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> hw(n);
	vector<int> ts(n);
	int totalFine = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ts[i] >> hw[i];
		totalFine += hw[i];
	}

	vector<vector<int>> dp(1001, vector<int> (1001,totalFine)); 
	// dp[i][j] = i번째 과제까지 고려했을때 j일의 최소 벌금
	dp[0][0] = totalFine;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j >= ts[i]) {
				dp[i + 1][j] = min(dp[i][j - ts[i]] - hw[i], dp[i][j]);
			}
			else {
				dp[i + 1][j] = dp[i][j];
			}
		}
	}

	cout << dp[n][t] << '\n';
	return 0;
}

