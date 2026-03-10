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

int N, M;

vector<int> parent;
vector<int> rankVec;

int Find(int x) {

	if (parent[x] == x) {
		return x;
	}
	else return parent[x] = Find(parent[x]);

}

void Union(int a, int b) {

	int A = Find(a);
	int B = Find(b);

	if (A == B) return;
	else if (rankVec[A] > rankVec[B]) {
		parent[B] = A;
	}
	else if (rankVec[A] < rankVec[B]) {
		parent[A] = B;
	}
	else {
		parent[B] = A;
		rankVec[A]++;
	}

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	rankVec.resize(N + 1, 0);
	parent.resize(N + 1);
	int ans = 0;

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	int a; cin >> a;
	vector<int> know;

	for (int i = 0; i < a; i++) {
		int input;
		cin >> input;
		know.push_back(input);
	}

	for (int i = 0; i < a - 1; i++) {
		Union(know[i], know[i + 1]);
	}

	vector<vector<int>> parties(M);

	for (int i = 0; i < M; i++) {

		bool can = true;

		int cnt;
		cin >> cnt;

		
		for (int j = 0; j < cnt; j++) {
			
			int input;
			cin >> input;

			parties[i].push_back(input);
		}

		for (int j = 0; j < cnt - 1; j++) {
			Union(parties[i][j], parties[i][j + 1]);
		}


	}

	for (int i = 0; i < M; i++) {
		bool can = true;
		for (int j = 0; j < parties[i].size(); j++) {

			for (int k = 0; k < know.size(); k++) {
				if (Find(parties[i][j]) == Find(know[k])) {

					can = false;

					break;
				}
			}

			if (!can) break;
		}
		if (can) ans++;

	}

	cout << ans << '\n';
	
	return 0;
}