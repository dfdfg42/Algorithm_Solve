#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef long double ld;
int N, K;
vector<vector<ld>> board;
vector<vector<ld>> dist; // city, 매직포션 사용수
struct Node {
	int city;
	ld cost;
	int usePotion;
	bool operator<(const Node& other) const {
		return cost > other.cost;
	}
};
int main()
{
	cin >> N >> K;
	board.resize(N, vector<ld>(N));
	dist.assign(N, vector<ld>(K + 1, 1e18));
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	dist[0][0] = 0;
	priority_queue<Node, vector<Node>> pq;
	pq.push({ 0, 0, 0 });
	while (!pq.empty()) {
		int city = pq.top().city;
		ld cost = pq.top().cost;
		int usePotion = pq.top().usePotion;
		pq.pop();
		if (dist[city][usePotion] < cost) continue;
		for (int next = 0; next < N; next++) {
			if (next == city) continue;
			// 포션 미사용
			ld nextCost = dist[city][usePotion] + board[city][next];
			if (dist[next][usePotion] > nextCost) {
				dist[next][usePotion] = nextCost;
				pq.push({ next, dist[next][usePotion], usePotion });
			}
			// 포션 사용
			if (usePotion == K) continue;
			ld nextCostPotion = dist[city][usePotion] + board[city][next] / 2.0;
			if (dist[next][usePotion + 1] > nextCostPotion) {
				dist[next][usePotion + 1] = nextCostPotion;
				pq.push({ next, dist[next][usePotion + 1], usePotion + 1 });
			}
		}
	}
	ld ans = 1e18;
	for (int i = 0; i <= K; i++) {
		ans = min(ans, dist[1][i]);
	}
	cout << fixed;
	cout.precision(1);
	cout << ans << '\n';

	return 0;
}