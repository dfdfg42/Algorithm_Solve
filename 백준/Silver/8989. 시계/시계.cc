#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

double computeAngle(const string& time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    double hour_angle = (hh % 12) * 30.0 + mm * 0.5;
    double minute_angle = mm * 6.0;
    double diff = fabs(hour_angle - minute_angle);
    return min(diff, 360 - diff);
}

bool cmp(const string& a, const string& b) {
    double angleA = computeAngle(a);
    double angleB = computeAngle(b);
    if (fabs(angleA - angleB) < 1e-9)
        return a < b;
    return angleA < angleB;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        vector<string> times(5);
        for (int i = 0; i < 5; i++) {
            cin >> times[i];
        }
        sort(times.begin(), times.end(), cmp);
        
        cout << times[2] << "\n";
    }

    return 0;
}
