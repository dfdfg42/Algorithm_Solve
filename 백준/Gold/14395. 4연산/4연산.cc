#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;


//방문최소 배열
set<ll> visited;

int s, t;

bool can(ll input) {

	if (input <= 1'000'000'000 && input > 0 && visited.find(input) == visited.end()) {
		return true;
	}

	return false;

}

string bfs() {

	//숫자 , 연산순서
	queue < pair<int, string>> q;
	
	q.push({ s,""});

	visited.insert({s});

	while (!q.empty()) {

		ll val = q.front().first;
		string ops = q.front().second;
		if (val == t) {

			return ops;
		}

		q.pop();

		char nextOps[4] = { '*','+','-','/' };

		for (int i = 0; i < 4; i++) {

			if (nextOps[i] == '*') {
				if (can(val * val)) {
					visited.insert(val * val);
					q.push({ val * val , ops + nextOps[i]});
				}

			}else if (nextOps[i] == '+') {
				if (can(val + val)) {
					visited.insert(val + val);
					q.push({ val + val , ops + nextOps[i] });
				}

			}else if (nextOps[i] == '-') {
				if (can(val - val)) {
					visited.insert(val - val);
					q.push({ val - val , ops + nextOps[i] });
				}

			}else if (nextOps[i] == '/') {
				if (can(val / val)) {
					visited.insert(val / val);
					q.push({ val / val , ops + nextOps[i] });
				}

			}

		}


	}
	return "";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> t;

	if (s == t) {
		cout << 0 << '\n';
		return 0;
	}

	string ans = bfs();
	if (ans == "") cout << -1 << '\n';
	else
	cout << ans << '\n';

	return 0;
}