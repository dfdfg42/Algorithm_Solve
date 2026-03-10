#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

typedef long long ll;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;
	int ans = a + b + c + d + e + f;
	ans *= 5;
	cout << ans << endl;


    return 0;
}