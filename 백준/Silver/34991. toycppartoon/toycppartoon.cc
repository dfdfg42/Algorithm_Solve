#include <iostream>
#include <vector>
#include <string>

using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string ori = "toycartoon";
	string s;
	cin >> s;

	string o = "";
	int o_pos = -1;
	// o 찾기 s의 접두사면서 toycartoon의 부분문자열 / 가장 긴거 , 가장앞에거
	for (int i = s.length(); i >= 1; i--) {
		string a = s.substr(0, i);

		size_t pos = ori.find(a);
		if (pos != string::npos) {
			o = a;
			o_pos = pos;
			break;
		}
	}

	string candidate;

	if (o.length() == 0) {
		candidate = "toycartoon_" + s;
	}
	else {
	
		string T = ori.substr(0, o_pos);
		string Y = ori.substr(o_pos + o.length());

		string s_rest = s.substr(o.length());


		int remove_len = 0;
		for (int i = s_rest.length(); i >= 1; i--) {
			string suffix = s_rest.substr(s_rest.length() - i); 
			string y_prefix = Y.substr(0, i);                   
			if (suffix == y_prefix) {
				remove_len = i;
				break;
			}
		}

		string new_Y = Y.substr(remove_len);
		candidate = T + s + new_Y;
	}

	if (candidate.length() > 20) {
		cout << "toycartoon" << endl;
	}
	else {
		cout << candidate << endl;
	}

	return 0;

	



	return 0;
}