#include <iostream>
#include <queue>

using namespace std;

int go() {

}

int main() {

	int n; cin >> n;

	int tile[1001] = { 0 };
	
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2])%10007;
	}
	cout << tile[n];

	return 0;
}