#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int N;

int main()
{
	
	cin >> N;
	cin.ignore();
	
	
	vector<bool> used(26, false);
	vector<string> v (N);

	
	for (int i = 0; i < N; i++) {
		bool found = false;
		int targetIdx = -1;
		getline(cin , v[i]);

		for (int j = 0; j < v[i].length(); j++) {

			if (j == 0 || v[i][j - 1] == ' ') {
				if (!isalpha(v[i][j])) continue;

				char c = toupper(v[i][j]);
				if (used[c-'A'] == false) {
					used[c - 'A'] = true;
					targetIdx = j;
					found = true;
					break;
				}

			}
			
		}

		if (!found) {

			for (int j = 0; j < v[i].length(); j++) {
				if (!isalpha(v[i][j])) continue;
				char c = toupper(v[i][j]);
				if (used[c - 'A'] == false) {
					used[c - 'A'] = true;
					targetIdx = j;
					break;
				}

			}

		}

		if (targetIdx != -1){
			v[i].insert(targetIdx, "[");
			v[i].insert(targetIdx + 2, "]");
		}
		cout << v[i] << '\n';

	}

	

	return 0;
}