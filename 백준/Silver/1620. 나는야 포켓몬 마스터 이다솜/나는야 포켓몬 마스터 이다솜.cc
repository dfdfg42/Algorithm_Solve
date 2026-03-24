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

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map<string, int > dic;
	map<int, string> dic2;

	int poketmonNum = 0;

	for (int i = 0; i < N; i++) {

		string s;
		cin >> s;
		dic[s] = ++poketmonNum;
		dic2[poketmonNum] = s;

	}

	for (int i = 0; i < M; i++) {

		string s;
		cin >> s;

		if (dic.find(s) != dic.end()) {
			cout << dic[s] << '\n';
		}
		else {
			cout <<  dic2[stoi(s)] <<'\n';
		}

	}
	
	return 0;
}