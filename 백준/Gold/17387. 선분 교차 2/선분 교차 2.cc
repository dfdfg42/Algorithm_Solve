#include <iostream>
using namespace std;

typedef long long ll;
struct Point { ll x, y; };

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

bool between(Point a, Point b, Point c) {
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    ll c1 = ccw(p1, p2, p3);
    ll c2 = ccw(p1, p2, p4);
    ll c3 = ccw(p3, p4, p1);
    ll c4 = ccw(p3, p4, p2);

    if (c1 == 0 && between(p1, p2, p3)) { cout << 1; return 0; }
    if (c2 == 0 && between(p1, p2, p4)) { cout << 1; return 0; }
    if (c3 == 0 && between(p3, p4, p1)) { cout << 1; return 0; }
    if (c4 == 0 && between(p3, p4, p2)) { cout << 1; return 0; }

    if ((c1 > 0) != (c2 > 0) && (c3 > 0) != (c4 > 0)) cout << 1;
    else cout << 0;
}
