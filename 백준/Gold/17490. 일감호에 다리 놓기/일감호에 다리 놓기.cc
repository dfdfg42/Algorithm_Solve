#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
long long K;
vector<int> parent;
vector<bool> broken; 

struct Edge {
	int u, v, cost;
	bool operator<(const Edge& other) const {
		return cost < other.cost;
	}
};

vector<Edge> edges;

int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A != B) {
		parent[A] = B;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	parent.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	edges.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		edges[i].u = 0;
		edges[i].v = i;
		cin >> edges[i].cost;
	}

	edges[0] = { 0, 0, 2000000000 };

	sort(edges.begin(), edges.end());

	broken.resize(N + 1, false);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		
		if ((a == 1 && b == N) || (a == N && b == 1)) {
			broken[N] = true;
		}
		else {
			broken[min(a, b)] = true;
		}
	}

	if (M <= 1) {
		cout << "YES\n";
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		if (!broken[i]) {
			int next_node = (i % N) + 1;
			Union(i, next_node);
		}
	}

	long long ans = 0;
	for (auto a : edges) {
		if (a.cost == 2000000000) continue;

		if (Find(a.u) == Find(a.v)) continue;

		Union(a.u, a.v);
		ans += a.cost;
		if (ans > K) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}