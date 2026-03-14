#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef long double ld;

const int INF = 987654321;
int N, M,ans;

vector<vector<int>> board;
vector<pair<int, int>> virus;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool check(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N) {
		return false;
	}

	return true;
}

void gameLoop(vector<pair<int, int>>& chosen) {

	//초를 세야함
	//거리배열 만들어서 다익스트라
	vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

	queue<pair<int, int>> q;

	//고른 바이러스 넣어주기
	for (auto a : chosen) {

		int y = a.first;
		int x = a.second;

		q.push({ y,x });
		dist[y][x] = 0;

	}

	int minTime = 0;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int d = 0; d < 4; d++) {

			int ny = y + dy[d];
			int nx = x + dx[d];

			if (!check(ny, nx)) continue;
			if (board[ny][nx] == 1) continue;

			//방문한적있으면 그게 최선임
			if (dist[ny][nx] != INT_MAX) continue;

			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny,nx });

		}

		//바이러스 만나면 활성바이러스에 넣어줘야함? -> 필요 없을듯 

	}

	//모든 비활성 바이러스의 최대 거리를 구하면 됨


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) {
				minTime = max(minTime, dist[i][j]);
			}
		}
	}
	

	ans = min(ans, minTime);
}

void dfs(int depth, int index , vector<pair<int,int>>& chosen) {

	//전부 수집한후 전파하기
	if (depth == M) {


		gameLoop(chosen);

		return;
	}

	for (int i = index; i < virus.size(); i++) {

		chosen.push_back(virus[i]);
		dfs(depth + 1, i + 1, chosen);
		chosen.pop_back();

	}

}





int main()
{


	cin >> N >> M;

	int zeroCount = 0;
	board.resize(N, vector<int>(N));
	//바이러스 수집
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i,j });
			}
			if (board[i][j] == 0) zeroCount++;
		}
	}

	ans = INF;

	if (zeroCount == 0) {
		cout << 0 << '\n';
		return 0;
	}

	//바이러스 고르기
	vector<pair<int,int>> temp;
	dfs(0, 0, temp);

	if (ans == INF) {
		cout << -1 << '\n';
	}else
	cout << ans << '\n';

	//전파할게 없는경우  바이러스 숫자 = M

	return 0;
}