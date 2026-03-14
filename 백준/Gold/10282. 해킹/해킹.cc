#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>
#include <map>
using namespace std;

const int INF = 987654321;
typedef long double ld;
typedef long long ll;

int N, D, C;
				// 다음정점 , 가중치
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void solve() {

	cin >> N >> D >> C;
	graph.clear();
	graph.resize(N + 1);
	dist.clear();
	dist.resize(N + 1, INF);

	for (int i = 0; i < D; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		graph[v].push_back({ u,c });

	}

	// 가중치, 현재 번호
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push({ 0,C });
	dist[C] = 0;


	while (!pq.empty()) {

		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost > dist[now]) continue;

		for (auto e : graph[now]) {

			int nextCost = e.second;
			int next = e.first;

			if (dist[next] > dist[now] + nextCost) {
				dist[next] = dist[now] + nextCost;
				pq.push({ dist[next], next });
			}

		}


	}

	//감염된 개수랑 총 시간 구하기
	int inffectCount = 0;
	int  time = 0;
	for (int i = 1; i <= N; i++) {

		if (dist[i] == INF)continue;

		inffectCount++;
		time = max(time, dist[i]);

	}

	cout << inffectCount << ' ' << time << '\n';

	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	

	return 0;
}