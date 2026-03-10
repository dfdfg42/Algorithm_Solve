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

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);

	}

	int before = 0;
	int ans = -1;
	for (int i = 0; i < N; i++) {

		int a; 
		cin >> a;

		if (Find(a) != Find(before)) {
			ans++;
		}

		before = a;

	}

	cout << ans << '\n';
	
	return 0;
}