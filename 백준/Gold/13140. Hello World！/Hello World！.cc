#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
int n, m;
vector<vector<int>> board;

ll ans;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    char d, e, h, l, o, r, w;

    cin >> ans;
	bool used[10] = { false, };
    //l -> o -> 나머지 숫자
    for (int i = 0; i <= 9; i++) {
        l = i + '0';
		if (used[i]) continue;
		used[i] = true;
        for (int j = 0; j <= 9; j++) {
            o = j + '0';
			if (used[j]) continue;
			used[j] = true;
            for (int k = 1; k <= 9; k++) {
                h = k + '0';
				if (used[k]) continue;
				used[k] = true;
                for (int m = 0; m <= 9; m++) {
                    e = m + '0';
					if (used[m]) continue;
					used[m] = true;
                    for (int t = 0; t <= 9; t++) {
                        d = t + '0';
						if (used[t]) continue;
						used[t] = true;
                        for (int p = 0; p <= 9; p++) {
                            r = p + '0';
							if (used[p]) continue;
							used[p] = true;
                            for (int a = 1; a <= 9; a++) {
                                w = a + '0';
								if (used[a]) continue;
								used[a] = true;
                                string first = "";
								first += h;
								first += e;
								first += l;
								first += l;
								first += o;
								string second = "";
								second += w;
								second += o;
								second += r;
								second += l;
								second += d;

                                //cout << first << " " << second << '\n';
                                if (ans == stol(first) + stol(second)) {
									cout << "  " << stol(first) << '\n';

									cout << "+ " << stol(second) << '\n';
									cout << "-------\n";
									if (ans >= 100000) cout << " ";
									else cout << "  ";
									cout  << ans << '\n';
                                    return 0;
                                }

								used[a] = false;

                            }
							used[p] = false;
                        }
						used[t] = false;
                    }
					used[m] = false;
                }
				used[k] = false;
            }
			used[j] = false;
        }
		used[i] = false;
    }
	cout << "No Answer" << '\n';
    return 0;
}