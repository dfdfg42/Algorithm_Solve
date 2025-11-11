#include <iostream>
#include <cmath> // ceil, sqrt 함수를 위해 포함

using namespace std;

// X, Y, c는 int 범위지만, 제곱하면 int 범위를 넘어설 수 있으므로
// long long 타입을 사용하는 것이 안전합니다.
long long X, Y, c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> X >> Y >> c;

	long long dist_sq = X * X + Y * Y;
	long long c_sq = c * c;

	if (dist_sq == 0) {
		cout << 0 << '\n';
	}
	else if (dist_sq == c_sq) {
		cout << 1 << '\n';
	}
	else if (dist_sq < c_sq) {
		cout << 2 << '\n';
	}
	else {
		double D = sqrt((double)dist_sq);

		int ans = (int)ceil(D / (double)c);
		cout << ans << '\n';
	}

	return 0;
}