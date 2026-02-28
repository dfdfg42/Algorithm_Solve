#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>

using namespace std;

int N, M;
int islandNum;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct Edge {
	int u;
	int v;
	int cost;
	bool operator<(const Edge& other) const {
		return cost < other.cost;
	}
};

vector<Edge> Edges;


vector<int> parent;

int Find(int x) {
	if (parent[x] != x) {
		parent[x] = Find(parent[x]);
	}
	return parent[x];
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
		parent[a] = b;
	}
}

bool check(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return false;

	return true;
}

void flood (int startY, int startX) {

	queue<pair<int, int>> q;
	q.push({ startY,startX });

	board[startY][startX] = islandNum;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (check(ny, nx) &&  board[ny][nx] == 1) {
				board[ny][nx] = islandNum;
				q.push({ ny,nx });
			}
		}
	}

	islandNum++;
}

void tryBridge(int startY, int startX) {

	//일직선으로 놓아야되고 2개 이상놓아야됨
	
	int startIslandNum = board[startY][startX];

	for (int i = 0; i < 4; i++) {

		int bridgeCount = 0;
		int ny = startY + dy[i];
		int nx = startX + dx[i];

		while (check(ny, nx)) {
			if (board[ny][nx] == 0) {
				bridgeCount++;
			}
			else if (board[ny][nx] != 0) {
				if (board[ny][nx] == startIslandNum) break;

				if (board[ny][nx] != startIslandNum && bridgeCount >= 2) {
					//cout << " startY " << startY << " startX " << startX << " ny " << ny << " nx " << nx << '\n';
					Edges.push_back({startIslandNum, board[ny][nx],bridgeCount});
					break;
				}
				else {
					break;
				}

				//cout << ny << ' ' << nx << '\n';
			}

			ny += dy[i];
			nx += dx[i];
		}

	}

}

void showBoard() {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	board.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	//섬을 돌면서 플러드 필로 섬을 구분 -> 정수로 섬 구분
	islandNum = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				flood(i, j);
			}
		}
	}

	//showBoard();

	//플러드필 완료하면 섬의 좌표들을 돌면서 상하좌우로 다리놓기 시도 (일직선에 방향 꺾이면 안됨)
	// -> 다리가 놓아지면 간선 추가
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			
			tryBridge(i, j);
		}
	}

	sort(Edges.begin(), Edges.end());


	//크루스칼로 최소 스패닝 트리 완성
	
	parent.resize(islandNum+3);
	for (int i = 0; i <= islandNum + 2; i++) {
		parent[i] = i;
	}

	int ans = 0;
	for (int i = 0; i < Edges.size(); i++) {
		if (Find(Edges[i].u) != Find(Edges[i].v)) {
			Union(Edges[i].u, Edges[i].v);
			ans += Edges[i].cost;
		}
	}

	//cout << "islandNum : " << islandNum << '\n';
	for (int i = 2; i < islandNum -1; i++) {
		if (Find(i) != Find(i+1)) {
			//cout << i << ' ' << i+1 << '\n';
			cout << -1 << '\n';
			return 0;
		}

	}

	cout << ans << '\n';


	return 0;
}