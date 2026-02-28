#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge {
	int to;
	double cost;
	bool operator>(const Edge& other) const {
		return cost > other.cost;
	}
};

int N, M;
pair<long long, long long> coords[1001];
vector<Edge> adj[1001];
bool visited[1001];

double getDistance(int i, int j) {
	long long dx = coords[i].first - coords[j].first;
	long long dy = coords[i].second - coords[j].second;
	return sqrt(dx * dx + dy * dy);
}

double prim() {
	double totalCost = 0;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	pq.push({ 1, 0.0 });

	while (!pq.empty()) {
		Edge curr = pq.top();
		pq.pop();

		if (visited[curr.to]) continue;
		visited[curr.to] = true;
		totalCost += curr.cost;

		for (auto& next : adj[curr.to]) {
			if (!visited[next.to]) {
				pq.push(next);
			}
		}
	}
	return totalCost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		cin >> coords[i].first >> coords[i].second;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({ v, 0.0 });
		adj[v].push_back({ u, 0.0 });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			double dist = getDistance(i, j);
			adj[i].push_back({ j, dist });
			adj[j].push_back({ i, dist });
		}
	}

	cout << fixed << setprecision(2);
	cout << prim() << endl;

	return 0;
}