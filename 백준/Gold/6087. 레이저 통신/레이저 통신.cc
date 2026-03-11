#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int W, H;
int cy1, cx1, cy2, cx2;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

vector<vector<char>> board;
vector<vector<vector<int>>> dist;


struct Node {
	int y;
	int x;
	int cost;
	int bd;

	bool operator< (const Node& other) const {

		return cost > other.cost;

	}
};


int main()
{
	
	cin >> W >> H;

	board.resize(H, vector<char>(W));
	// y, x, bd
	vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, INT_MAX)));

	bool find = false;

	for (int i = 0; i < H; i++) {

		string s;
		cin >> s;

		for (int j = 0; j < W; j++) {
			board[i][j] = s[j];

			if (board[i][j] == 'C') {
				if (!find) {
					cy1 = i;
					cx1 = j;
					find = true;
				}
				else {
					cy2 = i;
					cx2 = j;
				}
			}
		}
	}
	priority_queue<Node, vector<Node>> pq;

	pq.push({ cy1,cx1,0 ,0 });
	pq.push({ cy1,cx1,0 ,1 });
	pq.push({ cy1,cx1,0 ,2 });
	pq.push({ cy1,cx1,0 ,3 });
	for (int d = 0; d < 4; d++)
		dist[cy1][cx1][d] = 0;

	while (!pq.empty()) {

		int y = pq.top().y;
		int x = pq.top().x;
		int cost = pq.top().cost;
		int bd = pq.top().bd;
		pq.pop();
		if (cost > dist[y][x][bd]) continue;


		for (int d = 0; d < 4; d++) {

			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (board[ny][nx] == '*') continue;

			int nextCost = (bd == d) ? dist[y][x][bd] : dist[y][x][bd] + 1;
				
				
			if (dist[ny][nx][d] > nextCost) {
				dist[ny][nx][d] = nextCost;
				pq.push({ ny, nx, nextCost, d });
			}


		}

	}
				

	int ans = INT_MAX;
	for (int d = 0; d < 4; d++)
		ans = min(ans, dist[cy2][cx2][d]);
	cout << ans << '\n';


	
	
	


	return 0;
}