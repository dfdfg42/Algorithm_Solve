#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

int N, M, A, B;
vector<pair<int, int>> section;
vector<int> visited;

bool can(int a) {

    for (int i = 0; i < M; i++) {
        if (section[i].first <= a && a <= section[i].second) {
            return false;
        }
    }

    return true;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


	cin >> N >> M >> A >> B;
    section.resize(M);
	visited.resize(N + 1, INT_MAX);


    for (int i = 0; i < M; i++) {
		cin >> section[i].first >> section[i].second;
    }

    queue<int> q;

    q.push(0);
	visited[0] = 0;

    while (!q.empty())
    {
        int now = q.front();
		q.pop();
        int nextA = now + A;
        int nextB = now + B;

        if(nextA <= N && can(nextA) && visited[nextA] > visited[now] + 1) {
            visited[nextA] = visited[now] + 1;
            q.push(nextA);
		}

        if (nextB <= N && can(nextB) && visited[nextB] > visited[now] + 1) {
            visited[nextB] = visited[now] + 1;
            q.push(nextB);
        }
        
    }

    if(visited[N] == INT_MAX) {
        cout << -1 << "\n";
    } else {
        cout << visited[N] << "\n";
	}

    return 0;
}