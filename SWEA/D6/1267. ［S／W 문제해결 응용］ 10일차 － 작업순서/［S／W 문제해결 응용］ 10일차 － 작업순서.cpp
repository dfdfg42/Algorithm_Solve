#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int main()
{
     
    for (int T = 1; T <= 10; T++) {
        int V, E;
        cin >> V >> E;
 
        vector<vector<int>> graph(V + 1);
        vector<int> indegree(V + 1, 0);
 
        for (int i = 1; i <= E; i++) {
 
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            indegree[v]++;
 
        }
 
        queue<int> q;
 
        cout << '#' << T << ' ';
 
        for (int i = 1; i <= V; i++) {
            if (indegree[i] == 0) {
                cout << i << ' ';
                q.push(i);
            }
        }
 
 
  
       
        while (!q.empty()) {
            int front = q.front();
            q.pop();
 
            for (auto nextNode : graph[front]) {
 
                indegree[nextNode] --;
 
                if (indegree[nextNode] == 0) {
                    cout << nextNode << ' ';
                    q.push(nextNode);
                }
            }
 
        }
 
 
        cout << '\n';
   }
 
}