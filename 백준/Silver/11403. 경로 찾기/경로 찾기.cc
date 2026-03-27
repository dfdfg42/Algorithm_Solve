#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<vector<bool>> road(N + 1, vector<bool>(N + 1, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			road[i][j] = (a == 1) ? 1 : 0;
		}
	}

	for (int i = 0; i < N; i++) {
		road[i][i] = 0;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (road[i][k] != false && road[k][j] != false) {
					road[i][j] = true;
				}

			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << road[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}