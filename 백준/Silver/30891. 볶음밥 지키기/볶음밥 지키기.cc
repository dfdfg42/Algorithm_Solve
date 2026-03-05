#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N,R;

int main()
{
	
	cin >> N >> R;

	vector<pair<int, int>> rices(N);

	for (int i = 0; i < N; i++) {

		cin >> rices[i].first >> rices[i].second;
	}


	int ans = 0;
	int ansY = 0;
	int ansX = 0;

	for (int i = -100; i <= 100; i++) {
		for (int j = -100; j <= 100; j++) {

			int temp = 0;
			for (int r = 0; r < N; r++) {
				//cout << r << '\n';
				int result = pow(i - rices[r].first, 2) + pow(j - rices[r].second, 2);
				
				if (result <= R * R) {
					temp++;
				}
			}

			if (ans < temp) {
				ansY = i;
				ansX = j;
				ans = temp;
			}

		}
	}
	
	
	cout << ansY << ' ' << ansX << '\n';

	

	return 0;
}