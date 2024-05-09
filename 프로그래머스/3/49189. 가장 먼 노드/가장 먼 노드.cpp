#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    
    vector<vector<int>> graph(n + 1);
    for ( auto e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]); 
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 0);

    queue<int> q;
    q.push(1); 

    visited[1] = true;

    int maxDist = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : graph[now]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                dist[next] = dist[now] + 1;
                maxDist = max(maxDist, dist[next]);
            }
        }
    }
    int count = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] == maxDist){
            count++;
        }
    }
    
    for(int a : dist){
        cout << a << ' ';
    }

    return count;
}