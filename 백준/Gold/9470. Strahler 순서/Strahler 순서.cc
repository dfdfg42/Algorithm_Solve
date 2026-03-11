#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>

using namespace std;


vector<int> indegree;
vector<int> strahler;
vector<pair<int, int>> inCount; //max 순서 , 개수
vector<vector<int>> graph;
int K, M, P;

void solve() {

	cin >> K >> M >> P;

	indegree.clear();
	strahler.clear();
	inCount.clear();
	graph.clear();

	strahler.resize(M+1,1);
	indegree.resize(M + 1,0);
	graph.resize(M + 1);
	inCount.resize(M + 1, { 1,0 });

	for (int i = 0; i < P; i++) {

		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		indegree[b]++;

	}

	queue<int> q;
	
	for (int i = 1; i <= M; i++) {

		if (indegree[i] == 0) {
			q.push(i);
		}

	}

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		for (auto next : graph[now]) {

			indegree[next]--;

			if (inCount[next].first < inCount[now].first) {
				inCount[next].first = inCount[now].first;
				inCount[next].second = 1;
			}
			else if(inCount[next].first == inCount[now].first) {
				
				inCount[next].second++;

			}

			if (indegree[next] == 0) {

				if (inCount[next].second >= 2) {
					inCount[next].first = inCount[next].first + 1;
				}
				q.push(next);

			}
			
		}

	}

	cout << K <<' ' ;

	int ans = 0;
	for (auto ic : inCount) {
		ans = max(ans, ic.first);
	}

	cout << ans << '\n';

}

int main()
{
	int T;
	cin >> T;

	while (T--) {

		solve();
	}


	return 0;
}