#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

int N;
vector<vector<int>> board;
vector<pair<int, int>> cores;

int maxConnected;
int minWires;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool check(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N) {
		return false;
	}

	return true;
}

void dfs(int index, vector<vector<int>>&temp, int wires, int connected) {

	if (index == cores.size()) {

		if (connected > maxConnected) {
			minWires = wires;
			maxConnected = connected;
		}
		else if (connected == maxConnected) {
			minWires = min(minWires, wires);
		}
		return;
	}


	int y = cores[index].first;
	int x = cores[index].second;

	bool already = false;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (!check(ny, nx)) {
			already = true;
			break;
		}
	}

	if (already) {
		dfs(index + 1, temp, wires, connected + 1);
		return;
	}


	for (int d = 0; d < 4; d++) {

		vector<pair<int, int>> setWires;
		int ny = y + dy[d];
		int nx = x + dx[d];

		int tempWires = 0;
		bool can = true;
		while (check(ny, nx)) {


			if (temp[ny][nx] != 0) {
				can = false;
				break;
			}

			temp[ny][nx] = 2;
			setWires.push_back({ ny,nx });

			tempWires++;
			ny += dy[d];
			nx += dx[d];

		}



		if (can) {
			dfs(index + 1, temp, wires + tempWires, connected + 1);
		}

		for (auto a : setWires) {
			temp[a.first][a.second] = 0;
		}
	}

	dfs(index + 1, temp, wires, connected);



}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		board.clear();
		board.resize(N, vector<int>(N, 0));
		cores.clear();

		minWires = INT_MAX;
		maxConnected = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1) {
					cores.push_back({ i,j });
				}
			}
		}

		dfs(0, board, 0, 0);

		if (minWires == INT_MAX) {
			cout << '#' << test_case << ' ' << -1 << '\n';
		}
		else {
			cout << '#' << test_case << ' ' << minWires << '\n';
		}

	}
	return 0;
}