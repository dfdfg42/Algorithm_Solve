#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

typedef long long ll;


int n;
vector<vector<int>> board;


int xs, ys, xe, ye, dx, dy;

int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> xs >> ys;
    cin >> xe >> ye >> dx >> dy;

    //  dy/dx 의 크기로 이동이 가능함 -> dy dx의 최소공배수로 나눈만큼 최소 이동가능

    int gcd = GCD(dx, dy);
    //cout << gcd  << '\n';


    int ddx = dx / gcd, ddy = dy / gcd;
    //cout << "ddx: " << ddx << " ddy: " << ddy << '\n';

    int dist = INT_MAX;
    pair<int, int> ans;
    while (-100 <= xe && xe <= 100 && -100 <= ye && ye <= 100) {

        //cout << xe << ' ' << ye << '\n';
        int temp = (xs - xe) * (xs - xe) + (ys - ye) * (ys - ye);
        if (temp <= dist) {
            ans = { xe,ye };
            //cout << "check :" << xe << ' ' << ye << '\n';
            //cout << "temp: " << temp << '\n';
            dist = temp;
        }
        xe += ddx;
        ye += ddy;
    }
    
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}
