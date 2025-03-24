#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
	vector<int> dp(n + 1, 0);
    vector<int> vec(n + 1);
    
    
    
    for (int i = 0; i < n; i++) {
		cin >> vec[i];
    }

	dp[0] = vec[0];

	//dp[i] = dp[j] + vec[i] (j < i)

    for (int i = 1; i < n; i++) {
		dp[i] = vec[i];
		for (int j = 0; j < i; j++) {
			if (vec[j] < vec[i]) {
				dp[i] = max(dp[i], dp[j] + vec[i]);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
 

    return 0;
}
