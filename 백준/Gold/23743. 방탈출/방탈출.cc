#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> parent;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<Edge> edges;

int Find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

bool Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);
    if (A != B) {
        parent[A] = B;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({ u, v, c });
    }

    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        edges.push_back({ 0, i, t });
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;
    int cnt = 0;

    for (auto& edge : edges) {
        if (Union(edge.u, edge.v)) {
            ans += edge.cost;
            cnt++;
            if (cnt == N) break;
        }
    }

    cout << ans << "\n";

    return 0;
}