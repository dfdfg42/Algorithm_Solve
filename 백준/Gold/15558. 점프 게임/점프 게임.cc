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

    
    int n, k;

	cin >> n >> k;

	vector<string> lines(2);
	cin >> lines[0] >> lines[1];

	//padding 추가
	for (int i = 0; i < 2*k; i++) {
		lines[0] += '1';
		lines[1] += '1';
	}

	queue<pair<pair<int, int>, int>> q; // <라인, 위치>, 시간

	vector<vector<int>> visited(2, vector<int>(n+1, INT_MAX));

	q.push({ {0, 0}, 0 });
	
	bool canWin = false;
	while (!q.empty()) {
		int line = q.front().first.first;
		int pos = q.front().first.second;
		int time = q.front().second;

		//cout << line << ' ' << pos << ' ' << time << '\n';

		if (pos > n) {
			canWin = true;
			break;
		}
		q.pop();
		if (visited[line][pos] <= time) continue;

		visited[line][pos] = time;

		if (lines[line][pos + 1] == '1') {
			q.push({ {line, pos + 1}, time + 1 });
		}
		if (pos > 1) {
			if (lines[line][pos - 1] == '1' && pos-1 > time ) {
				q.push({ {line, pos - 1}, time + 1 });
			}
		}
		//건너편
		if (lines[line ^ 1][pos + k] == '1') {
			q.push({ {line ^ 1, pos + k}, time + 1 });
		}
	}

	if (canWin) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}

    return 0;
}
