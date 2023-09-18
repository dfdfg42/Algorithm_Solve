#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> computer[101];
bool check[101];
int virusCount;

void dfs(int node) {
	check[node] = true;
	virusCount++;

	for (int i = 0; i < computer[node].size(); i++) {
		int nextNode = computer[node][i];
		if (check[nextNode] == false) {
			dfs(nextNode);
		}
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int n1;
	cin >> n1;
	virusCount = 0;

	for (int i = 0; i < n1; i++) {
		int u, v;
		cin >> u >> v;

		computer[v].push_back(u);
		computer[u].push_back(v);
	}
	dfs(1);

	cout << virusCount-1 << endl;
	return 0;
}
