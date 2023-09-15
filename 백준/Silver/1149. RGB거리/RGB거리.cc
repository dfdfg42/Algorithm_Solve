#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	int n; cin >> n;
	int house_cost[1001][3] = { 0 };
	int result[1001][3] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house_cost[i][j];
		}
	}

	result[0][0] = house_cost[0][0];
	result[0][1] = house_cost[0][1];
	result[0][2] = house_cost[0][2];

	for (int i = 1; i <= n; i++) {
		result[i][0] = min(result[i-1][1],result[i-1][2]) + house_cost[i][0];
		result[i][1] = min(result[i - 1][0], result[i - 1][2]) + house_cost[i][1];
		result[i][2] = min(result[i - 1][0], result[i - 1][1]) + house_cost[i][2];

	}
	int min = 123456789;
	for (int i = 0; i < 3; i++) {
		if (result[n][i] < min) {
			min = result[n][i];
		}
	}
	cout << min << endl;
}