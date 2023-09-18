#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, r, c;
int ans;

void go(int x,int y,int size) {
	if (y == r && x == c) {
		cout << ans << '\n';
		return;
	}

	if (r <y+size && r>=y && c<x+size && c>= x) {

		go(x, y, size / 2);
		go(x + size / 2, y, size / 2);
		go(x, y + size / 2, size / 2);
		go(x + size / 2, y + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> N >> r >> c;
	go(0, 0, (1 << N));
	return 0;
}
