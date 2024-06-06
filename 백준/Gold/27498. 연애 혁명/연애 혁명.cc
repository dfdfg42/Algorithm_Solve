#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 100001;

int parent[MAX];

int Find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = Find(parent[a]); // 경로 압축 기법
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[b] = a; // 부모를 갱신하여 연결
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}

    // 부모 초기화
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }


    for (int i = 0; i < M; i++) {
        int u, v, weight, d;
        cin >> u >> v >> weight >> d;

        if (d == 1) {
            Union(u, v);
        }
        else {
            edges.push_back({ weight, {u, v} });
        }
    }

    int total_weight = 0;

    // 간선을 가중치 기준으로 내림차순 정렬
    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

    for (const auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (Find(u) != Find(v)) {
            Union(u, v);
        }
        else {
            total_weight += weight;
        }
    }

    cout << total_weight << "\n";

    return 0;
}
