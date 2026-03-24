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

int N;
bool findAns = false;

void dfs(string  s) {

	if (findAns) {
		return;
	}
	//N 개를 채우면 반환

	//좋은 수열인지 체크
	int size = s.length();
	for (int i = 1; i <= size / 2; i++) {
		bool d = false;
		for (int j = 1; j <= i; j++) {
			if (s[size - j] != s[size - i - j]) {
				d = true;
				//return;
				break;
			}
			
		}
		if (!d) return;
	}

	if (s.length() == N) {

		cout << s << '\n';
		findAns = true;
		return;
	}

	//1,2,3 더하기

	string temp = s;
	dfs(temp + '1');
	dfs(temp + '2');
	dfs(temp + '3');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dfs("");
	


	return 0;
}