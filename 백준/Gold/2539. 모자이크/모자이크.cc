#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>

using namespace std;

int r, c;
int paperUse ,n;


vector<pair<int, int>> points;


//점을 전부 가려보기
bool hidePoint(int paperSize) {


	int beforePoint = points[0].first;
	int useCount = 1;
	//가려지지 않은 점의 맨아래에 종이를 붙이고 다음점들 가려질때까지 스킵
	for (int i = 0; i < n; i++) {
		
		if (points[i].second > paperSize) return false;

		if (points[i].first >= beforePoint + paperSize) {
			beforePoint = points[i].first;
			useCount++;
		}
		if (useCount > paperUse) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	cin >> paperUse;


	cin >> n;
	if (n == 0) {
		cout << 0 << '\n'; return 0;
	}
	points.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		points[i] = { b,a };
	}

	sort(points.begin(), points.end());

	int ans = 987654321;

	//종이의 크기 이분탐색 
	int l = 1, r = 1000'0000;
	
	while (l <= r) {
		int mid = (l + r) / 2;

		if (hidePoint(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}

	}

	cout << ans << '\n';


	return 0;
}