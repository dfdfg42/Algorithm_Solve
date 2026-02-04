#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll N, M;
string s1, s2;

ll cnt = 0;
int arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> s1 >> s2;
	int i = 0;
	for (int i2 = 0; i2 < N + M; i2++) {
		if (s1[i2] == '1') arr[i++] = i2;
	}
	i = 0;
	for (int i2 = 0; i2 < N + M; i2++) {
		if (s2[i2] == '1') cnt += abs(i2 - arr[i++]);
	}

	cout << (cnt / 2) * (cnt / 2) + (cnt - cnt / 2) * (cnt - cnt / 2);
}