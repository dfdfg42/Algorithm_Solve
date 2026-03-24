#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

deque<int> d;

void solve() {


	//실행할 함수의 길이 100'000;
	string p;
	cin >> p;

	// 배열의 길이 100'000  , 뒤집기 전부하면 시간초과
	int n;
	cin >> n;
	d.clear();

	string s;
	cin >> s;
	s = s.substr(1, s.length() - 2);


	stringstream ss(s);
	string token;
	while (getline(ss, token, ',')) {
		d.push_back(stoi(token));
	}

	//현재 뒤집어졋는지 뒤집어지지 않았는지 추적
	bool isReverse = false;
	bool isError = false;

	
	//뒤집어졋으면 뒤에 지우고 , 안뒤집어졋으면 앞에 지움
	for (int i = 0; i < p.length(); i++) {
		char order = p[i];

		if (order == 'R') {
			isReverse = !isReverse;
		}
		else if (order == 'D') {

			if (isReverse) {

				//비어있으면 에러
				if (d.size() == 0) {
					isError = true;
					break;
				}
				else {
					d.pop_back();
				}

			}
			else {
				//비어있으면 에러
				if (d.size() == 0) {
					isError = true;
					break;
				}
				else {
					d.pop_front();
				}
			}

		}
	}

	//뒤집어졋으면 뒤에서부터 출력
	//안뒤집어졋으면 앞에서부터 출력

	int dSize = d.size();
	if (isError) {
		cout << "error\n";
	}
	else if (isReverse) {
		cout << "[";
		for (int i = dSize-1; i >=0; i--) {
			cout << d.back();
			d.pop_back();
			if (i != 0) {
				cout << ",";
			}
		}
		cout << "]\n";
	}
	else {
		cout << "[";
		for (int i = 0; i < dSize; i++) {
			cout << d.front();
			d.pop_front();
			if (i != dSize-1) {
				cout << ",";
			}
		}
		cout << "]\n";
		
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	

	while (t--) {
		solve();
	}


	return 0;
}