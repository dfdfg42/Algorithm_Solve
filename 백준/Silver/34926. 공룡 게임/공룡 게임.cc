#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>

using namespace std;

typedef long long ll;

int N, P, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	string s;
	cin >> s;

	vector<bool> v(N + 1, false);

	v[1] = true;

	for (int i = 1; i <= N; i++) {

		if (v[i - 1] == true && s[i-1-1] != '#') {
			v[i] = true;
		}
		else if (i - K > 0 && v[i - K] == true && s[i-K-1] != '#') {
			v[i] = true;
		}

	}



	if (v[N] == true) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	
	return 0;
}