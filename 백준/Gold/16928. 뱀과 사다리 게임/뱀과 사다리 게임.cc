#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

typedef long long ll;

const int INF = 987654321;

int N, M;

vector<int> ladders;
vector<int> snakes;
vector<int> dist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	ladders.resize(101, -1);
	snakes.resize(101, -1);
	dist.resize(101, INF);

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		ladders[a] = b;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		snakes[a] = b;
	}

	queue<int> q;

	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {

		int now = q.front();
		//cout << " now : " << now << '\n';
		q.pop();

		int next;
		if (ladders[now] != -1) {

			next = ladders[now];

			if (dist[next] > dist[now]) {
				dist[next] = dist[now];

				q.push(next);
			}

		}

		if (snakes[now] != -1) {

			next = snakes[now];

			if (dist[next] > dist[now]) {
				dist[next] = dist[now];

				q.push(next);
			}

		}


		if (ladders[now] != -1 || snakes[now] != -1) continue;

		for (int i = 1; i <= 6; i++) {

			int next = now + i;


			if (next <= 100 && dist[next] > dist[now] +1 ) {

				dist[next] = dist[now] + 1;

				q.push(next);
			}


		}


	}

	cout << dist[100] << '\n';

	return 0;
}