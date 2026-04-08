#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

struct Point {
    int x;
    int y;

    bool operator<(const Point& other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;

    vector<Point> v(N);

    for (int i = 0; i < N; i++) {

        cin >> v[i].x >> v[i].y;

    }

    sort(v.begin(), v.end());
    ll count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            if (v[i].x != v[j].x && v[i].y != v[j].y) {

                Point p1 = { v[i].x , v[j].y };
                Point p2 = { v[j].x , v[i].y };

                if (binary_search(v.begin(), v.end(), p1) &&
                    binary_search(v.begin(), v.end(), p2)) {
                    count++;
                }

            }

        }
    }

    cout << count / 2 << '\n';



    return 0;
}