#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

typedef long long ll;

struct subject {
	int a, b, c;
};

const int INF = 987654321;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<subject> subjects;

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {

		int a, b, c;
		cin >> a >> b >> c;

		subjects.push_back({ a,b,c });
	}

	ll ans = 0;
	ll sum = 0;

	sort(subjects.begin(), subjects.end(), [](const subject& s1, const subject& s2) {
		return (s1.a + s1.b) > (s2.a + s2.b);
	});


	for (int i = 0; i < K; i++) {
		sum += (subjects[i].a + subjects[i].b);
	}
	ans = max(ans, sum);
	sum = 0;

	sort(subjects.begin(), subjects.end(), [](const subject& s1, const subject& s2) {
		return (s1.b + s1.c) > (s2.b + s2.c);
	});

	ans = max(ans, sum);
	sum = 0;

	for (int i = 0; i < K; i++) {
		sum += (subjects[i].b + subjects[i].c);
	}

	ans = max(ans, sum);
	sum = 0;

	sort(subjects.begin(), subjects.end(), [](const subject& s1, const subject& s2) {
		return (s1.a + s1.c) > (s2.a + s2.c);
	});

	for (int i = 0; i < K; i++) {
		sum += (subjects[i].a + subjects[i].c);
	}

	ans = max(ans, sum);
	sum = 0;

	cout << ans << '\n';


	return 0;
}