#include <iostream>
using namespace std;

typedef long long ll;

struct Point { ll x, y; };

ll ccw(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool opp_or_on(ll a, ll b) {
    if (a == 0 || b == 0) return true;
    return (a > 0) != (b > 0);
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

    cout << (opp_or_on(c1, c2) && opp_or_on(c3, c4) ? 1 : 0) << '\n';
    return 0;
}
