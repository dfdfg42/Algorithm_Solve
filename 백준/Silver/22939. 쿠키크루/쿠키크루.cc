#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> Point;

int get_dist(Point a, Point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve_topping(vector<Point>& toppings, Point start, Point end) {
    int min_distance = 2e9;
    
    sort(toppings.begin(), toppings.end());

    do {
        int current_dist = 0;
        current_dist += get_dist(start, toppings[0]);
        current_dist += get_dist(toppings[0], toppings[1]);
        current_dist += get_dist(toppings[1], toppings[2]);
        current_dist += get_dist(toppings[2], end);

        if (current_dist < min_distance) {
            min_distance = current_dist;
        }

    } while (next_permutation(toppings.begin(), toppings.end()));

    return min_distance;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Point start, end;
    vector<Point> J, C, B, W;

    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'H') start = { i, j };
            else if (s[j] == '#') end = { i, j };
            else if (s[j] == 'J') J.push_back({ i, j });
            else if (s[j] == 'C') C.push_back({ i, j });
            else if (s[j] == 'B') B.push_back({ i, j });
            else if (s[j] == 'W') W.push_back({ i, j });
        }
    }

    int dist_J = solve_topping(J, start, end);
    int dist_C = solve_topping(C, start, end);
    int dist_B = solve_topping(B, start, end);
    int dist_W = solve_topping(W, start, end);

    int min_final = dist_J;
    string ans = "Assassin";

    if (dist_C < min_final) {
        min_final = dist_C;
        ans = "Healer";
    }
    
    if (dist_B < min_final) {
        min_final = dist_B;
        ans = "Mage";
    }

    if (dist_W < min_final) {
        min_final = dist_W;
        ans = "Tanker";
    }

    cout << ans << "\n";

    return 0;
}