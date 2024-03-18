#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
using namespace std;

const int MAX = 100;
double dist[MAX][MAX];
bool selected[MAX];
double minDist[MAX];

double getDistance(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double prim(int n) {
    double result = 0;
    minDist[0] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int current;
        double distance;
        tie(distance, current) = pq.top();
        pq.pop();

        if (selected[current]) continue;
        selected[current] = true;
        result += distance;

        for (int i = 0; i < n; i++) {
            double nextDist = dist[current][i];
            if (!selected[i] && minDist[i] > nextDist) {
                minDist[i] = nextDist;
                pq.push({ nextDist, i });
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<pair<double, double>> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> stars[i].first >> stars[i].second;
        minDist[i] = 1e9;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = getDistance(stars[i], stars[j]);
        }
    }

    cout << fixed << setprecision(2) << prim(n) << endl;
    return 0;
}
