#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef long double ld;
typedef long long ll;

int N;


vector<vector<ll>> dist;
vector<ll> planetDist;
vector<int> parent;
vector<int> rnk;

int Find(int x) {
	
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}

}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) {
		return;
	}
	else if (rnk[A] < rnk[B]) {

		parent[A] = B;
	}
	else if (rnk[B] > rnk[A]) {
		parent[B] = A;
	}
	else {

		parent[A] = B;
		rnk[B]++;

	}

}

int main()
{
	
	cin >> N;
	dist.resize(N+1, vector<ll>(N+1));
	parent.resize(N + 1);
	rnk.resize(N + 1);
	planetDist.resize(N + 1, INT_MAX);

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		rnk[i] = 0;
	}


	vector<pair<ll, pair<int, int>>> edges;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dist[i][j];
			edges.push_back({ dist[i][j] , {i,j } });
		}
	}

	sort(edges.begin(), edges.end());

	ll ans = 0;
	for (auto e : edges) {

		int cost = e.first;
		int u = e.second.first;
		int v = e.second.second;

		if (Find(u) != Find(v)) {

			Union(u, v);
			ans += cost;

		}

	}

	cout << ans << '\n';

	return 0;
}