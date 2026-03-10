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

int N;

vector<vector<int>> graph;
vector<int> indegree;
queue<int> q;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	graph.resize(N + 1);
	indegree.resize(N + 1, 0);
	vector<bool> visited(N + 1, false);

	for (int i = 0; i < N; i++) {

		int a, b;
		cin >> a >> b;
		graph[i+1].push_back(a);
		graph[i + 1].push_back(b);
		indegree[a]++;
		indegree[b]++;

	}




	for (int i = 1; i <= N; i++) {

		if (indegree[i] < 2) {
			q.push(i);
			
		}

	}

	while (!q.empty()) {

		int now = q.front();
		q.pop();
		if (visited[now]) continue;
		visited[now] =  true;
		for (auto a : graph[now]) {
			

			indegree[a]--;
			if (indegree[a] < 2) {
				q.push(a);
			
			}

		}


	}

	int ans = 0;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 2) {
			ans++;
			v.push_back(i);
		}
		
	}

	cout << ans << '\n';
	for (auto a : v) {
		cout << a << ' ';
	}

	return 0;
}