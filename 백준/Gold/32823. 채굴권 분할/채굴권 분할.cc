#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;

#define M_PI 3.14159265358979323846

int ccw(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
    ld crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (crossProduct > 0) {
        return 1; 
    } else if (crossProduct < 0) {
        return -1; 
    } else {
        return 0;
    }
}

// 메인 함수
int main() {
    int n;
    vector<pair<pair<ld, ld>, pair<ld, ld>>> lines;

    cin >> n;

    for (int i = 0; i < n; i++) {
        ld a, b;
        cin >> a >> b;
        ld radianA = (a * M_PI) / 1800.0;
        ld radianB = (b * M_PI) / 1800.0;
        ld transX1 = cos(radianA) * 1000;
        ld transY1 = sin(radianA) * 1000;
        ld transX2 = cos(radianB) * 1000;
        ld transY2 = sin(radianB) * 1000;
        lines.push_back({{transX1, transY1}, {transX2, transY2}});
    }

    int crossCount = 0;

    ld p1, p2, p1Length, p2Length;

    cin >> p1 >> p1Length >> p2 >> p2Length;

    ld radianP1 = (p1 * M_PI) / 1800.0;
    ld radianP2 = (p2 * M_PI) / 1800.0;
    ld p1X = cos(radianP1) * p1Length;
    ld p1Y = sin(radianP1) * p1Length;
    ld p2X = cos(radianP2) * p2Length;
    ld p2Y = sin(radianP2) * p2Length;

    for (int i = 0; i < lines.size(); i++) {
        ld x1 = lines[i].first.first, y1 = lines[i].first.second;
        ld x2 = lines[i].second.first, y2 = lines[i].second.second;

        int thirdCCW = ccw(x1, y1, x2, y2, p1X, p1Y);
        int fourthCCW = ccw(x1, y1, x2, y2, p2X, p2Y);

        if (thirdCCW == 0 || fourthCCW == 0) {
            continue;
        }

        if (thirdCCW * fourthCCW < 0) {
            crossCount++;
        }
    }

    cout << ((crossCount % 2) == 0 ? "YES" : "NO");

    return 0;
}
