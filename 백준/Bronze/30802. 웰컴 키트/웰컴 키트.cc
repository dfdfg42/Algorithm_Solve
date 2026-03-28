#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(6);

    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }

    int T, P;
    cin >> T >> P;

    int ansT = 0;

    for (int i = 0; i < 6; i++) {

        ansT += v[i] / T;
        if (v[i] % T != 0) ansT++;

    }

    int ansP = 0;

    cout << ansT << '\n' << N / P << ' ' << N % P << '\n';

    return 0;
}