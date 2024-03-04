#include <iostream>
#include <cstring> 
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
const int INF = 1e9;

vector<pair<int, int>> graph[MAX];
bool visited[MAX];

int prim(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int totalCost = 0;
    int connected = 0;

    pq.push({ 0,start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;
        totalCost += cost;
        connected++;

        if (connected == MAX) break;

        for (auto& edge : graph[current]) {
            int next = edge.first;
            int nextCost = edge.second;
            if (!visited[next]) pq.push({ nextCost,next });
        }
    }
    return totalCost;
}

int main() {
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    fill(visited, visited + MAX, false);
    
    cout << prim(1) << endl; 
    
    return 0;
}
