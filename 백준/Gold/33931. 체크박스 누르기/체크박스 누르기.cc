#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, m;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int a = M / N;
	int b = M % N;

	int ans = 0;
	if (a % 2 == 0) ans = b;
	else ans = N - b;

	cout << ans;

    return 0;
}