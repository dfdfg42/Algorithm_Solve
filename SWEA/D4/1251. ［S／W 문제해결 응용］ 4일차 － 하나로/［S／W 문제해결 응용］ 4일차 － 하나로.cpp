#include <bits/stdc++.h>
using namespace std;


static const int MAXN = 1001;
int parentSet[MAXN];
int rankSet[MAXN];

struct Edge {
    int u, v;        
    long double cost; 
};

int Find(int x) {
    if (parentSet[x] == x) return x;
    parentSet[x] = Find(parentSet[parentSet[x]]);
    return parentSet[x];
}


void Union(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);
    if (rootA == rootB) return;

    if (rankSet[rootA] < rankSet[rootB]) {
        parentSet[rootA] = rootB;
    }
    else if (rankSet[rootA] > rankSet[rootB]) {
        parentSet[rootB] = rootA;
    }
    else {
        parentSet[rootB] = rootA;
        rankSet[rootA]++;
    }
}

// 초기화 함수
void initUnionFind(int n) {
    for (int i = 0; i < n; i++) {
        parentSet[i] = i;
        rankSet[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 테스트 케이스 수
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;  // 섬의 개수
        cin >> N;

        vector<long long> X(N), Y(N);

        for (int i = 0; i < N; i++) {
            cin >> X[i];
        }

        for (int i = 0; i < N; i++) {
            cin >> Y[i];
        }

        // 환경 부담 세율 E
        long double E;
        cin >> E;

        initUnionFind(N);


        vector<Edge> edges;
        edges.reserve((long long)N * (N - 1) / 2); 

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                long long dx = X[i] - X[j];
                long long dy = Y[i] - Y[j];
                long double dist2 = (long double)dx * dx + (long double)dy * dy;
                long double cost = dist2 * E;
                edges.push_back({ i, j, cost });
            }
        }

        // 간선 비용 오름차순 정렬
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.cost < b.cost;
            });


        long double totalCost = 0.0L;
        int edgeCount = 0; 

        for (auto& edge : edges) {
         
            if (Find(edge.u) != Find(edge.v)) {
                Union(edge.u, edge.v);
                totalCost += edge.cost;
                edgeCount++;
            
                if (edgeCount == N - 1) break;
            }
        }


        long long answer = (long long)llround(totalCost);

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}