#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    vector<vector<ld>> a(4, vector<ld>(4));
    vector<ld>b(4);

    //입력
    int bIndex = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            if (j == 4) {
                cin >> b[bIndex];
                bIndex++;
            }
            else {
                cin >> a[i][j];
            }
        }
    }

    //detA 구하기
    ld detA = a[1][1] * (a[2][2] * a[3][3] - a[2][3] * a[3][2]) -
        a[1][2] * (a[2][1] * a[3][3] - a[2][3] * a[3][1]) +
        a[1][3] * (a[2][1] * a[3][2] - a[2][2] * a[3][1]);

    
    vector<ld> x(4);
    cout.precision(0);
    for (int i = 1; i <= 3; i++) {
        vector<vector<ld>> tempA = a;
        for (int j = 1; j <= 3; j++) {
            tempA[j][i] = b[j];
        }
        ld detTempA = tempA[1][1] * (tempA[2][2] * tempA[3][3] - tempA[2][3] * tempA[3][2]) -
            tempA[1][2] * (tempA[2][1] * tempA[3][3] - tempA[2][3] * tempA[3][1]) +
            tempA[1][3] * (tempA[2][1] * tempA[3][2] - tempA[2][2] * tempA[3][1]);
        cout << detTempA << ' ';
        x[i] = detTempA / detA;
    }
    cout << detA << ' ';
    cout << '\n';

    cout.precision(3);
    for (int i = 1; i <= 3; i++) {
        if (x[i] == 0.0) {

            x[i] = abs(x[i]);
            //cout << " 발동 ! \n";
        }
    }

    if (detA == 0) {
        cout << "No unique solution\n";
        cout << '\n';
    }
    else {
        cout << "Unique solution:";
        cout << " " << x[1] << " " << x[2] << " " << x[3] << "\n";
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        cout << fixed;
        solve();
    }
    return 0;
}