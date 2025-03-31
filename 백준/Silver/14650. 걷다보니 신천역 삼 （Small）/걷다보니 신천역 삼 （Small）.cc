#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int nums[3] = { 0,1,2 };

int n;
int ans;
void dfs(int index, string s) {
    if (index == n) {
        if (stol(s) % 3 == 0) ans++;
        return;
    }

    for (int i = 0; i < 3; i++) {
		if (index == 0 && i == 0) continue;
        s += to_string(nums[i]);
		dfs(index + 1 ,s);
		s.pop_back();
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ans = 0;

	dfs(0, "");

	cout << ans << '\n';

    return 0;
}
