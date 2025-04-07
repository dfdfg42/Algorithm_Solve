#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <tuple>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    //가장 많이 선택할 수 있는 노드의 개수 구하기
    vector<pair<ll,ll>> graphs(n);

	for (int i = 0; i < n; ++i) {
		cin >> graphs[i].second >> graphs[i].first;
	}

	sort(graphs.begin(), graphs.end());

    int ans = 0;

	ll prev = LLONG_MIN;
	for (int i = 0; i < n; ++i) {
		if (prev <= graphs[i].second) {
			ans++;
			prev = graphs[i].first;
		}
	}

    

	cout << ans << '\n';

    
    return 0;
}
