#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int n;
	cin >> n;

	int stairs[10'000];

	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}

	int dp[10'000];
	dp[0] = stairs[0];
	dp[1] = max(stairs[0] + stairs[1], stairs[1]);
	dp[2] = max(stairs[2] + stairs[0],stairs[1]+stairs[2]);


	for (int i = 3; i < n; i++) {

		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);

	}
	
	cout << dp[n - 1] << "\n";


}