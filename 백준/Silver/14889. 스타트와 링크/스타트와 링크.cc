#include <string>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int S[20][20];
bool visited[20];
int result = INT_MAX;

void calculateDifference() {
	int start_team = 0, link_team = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (visited[i] && visited[j]) {
				start_team += S[i][j] + S[j][i];
			}
			else if (!visited[i] && !visited[j]) {
				link_team += S[i][j] + S[j][i];
			}
		}
	}
	result = min(result, abs(start_team - link_team));
}

void dfs(int index, int count) {
	if (count == N / 2) {
		calculateDifference();
		return;
	}

	for (int i = index; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 1, count + 1);
			visited[i] = false;
		}
	}
	

}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	dfs(0, 0);

	cout << result << endl;
	return 0;
}
