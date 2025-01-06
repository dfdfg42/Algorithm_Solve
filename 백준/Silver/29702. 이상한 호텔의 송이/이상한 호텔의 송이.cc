#include <iostream>
#include <vector>
#include <string>
using namespace std;


static long long sumUpTo[61];

string makeRoomNumber(int floorNum, long long roomIndex) {

	string fStr = to_string(floorNum);
	string iStr = to_string(roomIndex);
	int padSize = 18 - (int)iStr.size();
	string zeroPadding(padSize, '0');
	iStr = zeroPadding + iStr;

	return fStr + iStr;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	sumUpTo[0] = 0;
	for (int f = 1; f <= 60; f++) {

		long long val = (1ULL << f) - 1;
		sumUpTo[f] = val;
	}

	int T;
	cin >> T;
	while (T--) {
		long long N;
		cin >> N;


		int f = 1;
		while (f <= 60 && sumUpTo[f] < N) {
			f++;
		}

		long long prevSum = (f == 1) ? 0 : sumUpTo[f - 1];  
		long long i = N - prevSum;                       

														
		vector<string> path;
		int curFloor = f;
		long long curIndex = i;
		while (curFloor >= 1) {
	
			path.push_back(makeRoomNumber(curFloor, curIndex));
			if (curFloor == 1 && curIndex == 1) {
				break; 
			}

			curIndex = (curIndex + 1) / 2;
			curFloor--;
		}


		for (auto &room : path) {
			cout << room << "\n";
		}
	}
	return 0;
}
