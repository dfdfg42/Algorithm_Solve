#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>

using namespace std;

typedef long long ll;

struct Node {

	int u, v;
	int cost;

	bool operator<(const Node&  other) const {
		
		return cost > other.cost;
	}

};

const int INF = 987654321;
int N, D;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> D;

	vector<int> dist(10001, INF);

	for (int i = 0; i <= D; i++) {
		dist[i] = i;
	}

	vector<Node> graph;

	for (int i = 0; i < N; i++) {
		int u, v, cost;

		cin >> u >> v >> cost;
		graph.push_back({ u,v,cost });

	}

	bool update = true;

	while (update) {
		update = false;

		for (auto a : graph) {

			int u = a.u;
			int v = a.v;
			int cost = a.cost;

			if (dist[v] > dist[u] + cost) {
				dist[v] = min(dist[u] + cost, dist[v]);
				update = true;
			}
			

		}

		for (int j = 1; j <= D; j++) {
			if (dist[j] > dist[j - 1] + 1) {
				dist[j] = min(dist[j], dist[j - 1] + 1);
				update = true;
			}
			
		}

	}

	


	
	cout << dist[D] <<'\n';
	
	return 0;
}