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


vector<vector<char>> board;


int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans = 0;

void showBoard() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

void fall() {
	for (int i = 0; i < 6; i++) {

		int bottom = 11;

		for (int j = 11; j >= 0; j--) {
			if (board[j][i] != '.') {
				if (j != bottom) {
					board[bottom][i] = board[j][i];
					board[j][i] = '.';
				}
				bottom--;
			}
			
		}

	}
}

bool boundary(int y, int x) {
	if (0 > y || y >= 12 || 0 > x || x >= 6) {
		return false;
	}

	return true;
}

int bfs(vector<vector<bool>> & visited , int i, int j, set<pair<int,int>> & beRemove) {


	queue<pair<int, int>> q;

	q.push({ i,j });
	vector<pair<int, int>> visitedBlocks;
	visitedBlocks.push_back({ i,j });

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		visited[y][x] = true;

		//cout << y << ' ' << x << '\n';
		q.pop();

		for (int t = 0; t < 4; t++) {
			int ny = y + dy[t];
			int nx = x + dx[t];

			if (!boundary(ny, nx)) {
				continue;
			}

			if (board[ny][nx] == board[i][j] && !visited[ny][nx]) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
				visitedBlocks.push_back({ ny,nx });
			}
		}

	}

	if (visitedBlocks.size() >= 4) {

		for (int k = 0; k < visitedBlocks.size(); k++) {
			//cout << visitedBlocks[k].first << ' ' << visitedBlocks[k].second << '\n';
			beRemove.insert(visitedBlocks[k]);
		}
		return 1;
	}
	return 0;
}

bool activate() {

	int cnt = 0;
	vector<vector<bool>> visited;
	set <pair<int, int>> beRemove;
	
	visited.resize(12, vector<bool>(6, false));
	bool isPopped = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {

			if (board[i][j] != '.' && !visited[i][j]) {
				if (bfs(visited, i, j, beRemove) == 1) {
					isPopped = true;
				}
			}



		}
	}

	for (auto a : beRemove) {
		board[a.first][a.second] = '.';
	}
	
	if (isPopped) ans++;

	return isPopped;
}





int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	board.resize(12, vector<char>(6));

	for (int i = 0; i < 12; i++) {
		string s;
		cin >> s; 
		for (int j = 0; j < 6; j++) {
			board[i][j] = s[j];
		}
	}
	
	//연쇄작용 
	//bfs로 4개 이상이면 set에 위치 저장했다가 삭제 아니면 그냥 방문처리
	while (activate()) {
		fall();
	}


	//showBoard();

	cout << ans << '\n';
	
	return 0;
}