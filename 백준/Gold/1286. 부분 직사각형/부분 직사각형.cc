#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>

using namespace std;

typedef long long ll;


int n, k;


vector<vector<char>> board;
vector<ll> charCnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	charCnt.resize(26, 0);

	cin >> n >> k;

	board.resize(2 * n, vector<char>(2 * k));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		for (int j = 0; j < k; j++) {
			board[i][j] = s[j];
			board[i][j + k] = s[j];
			board[i+n][j] = s[j];
			board[i+n][j + k] = s[j];
		}
		
	}

	//for (int i = 0; i < 2 * n; i++) {
	//	for (int j = 0; j < 2 * k; j++) {
	//		cout << board[i][j];
	//	}
	//	cout << '\n';
	//}


	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * k; j++) {
			ll plus = 1;


			//위쪽
			if (i != 0) {
				plus *= i + 1;
				//cout << "1 : " << i + 1 << '\n';
			}
			//아래쪽
			if (i != 2 * n - 1) {
				plus *= (2 * n - i);
				//cout << "2 : " << (2 * n - i) << '\n';
			}
			//왼쪽
			if (j != 0)  {
				plus *= j + 1;
				//cout << "3 :" << j + 1 << '\n';
			}
			//오른쪽
			if (j != 2 * k - 1) {
				//cout << "4 : " << (2 * k - j) << '\n';
				plus *= (2 * k - j);
			}
			charCnt[board[i][j] - 'A'] += plus;
			
			//cout << "check " << i << ' ' << j << '\n';;
			//cout << plus <<'\n';
		}
	}
	
	for (int i = 0; i < 26; i++) {
		cout << charCnt[i] << '\n';
	}

	return 0;
}