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


int n, m;
int limit;

vector<vector<int>> board;
vector<vector<int>> presum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n >> m;
	board.resize(n + 1, vector<int>(m + 1));
	presum.resize(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			presum[i][j] = board[i][j] + presum[i][j - 1] + presum[i - 1][j] - presum[i - 1][j - 1];
		}
	}

	int ans = INT_MIN;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < i; k++)
			{
				for (int t = 0; t < j; t++)
				{
					ans = max(ans, presum[i][j] - presum[k][j] - presum[i][t] + presum[k][t]);
				}
			}
		}
	}

	cout << ans;
}
