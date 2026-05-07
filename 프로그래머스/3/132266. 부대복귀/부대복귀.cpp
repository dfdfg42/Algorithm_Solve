#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int INF = 987654321;
vector<int> dist;
vector<vector<int>> revRoads;


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    dist.resize(n+1,INF);
    revRoads.resize(n+1);
    
    for(int i=0; i<roads.size(); i++){
        
        revRoads[roads[i][1]].push_back(roads[i][0]);
        revRoads[roads[i][0]].push_back(roads[i][1]);
        
    }
    
    //지역의 수 100'000
    
    //다익스트라 n 지역 source  * E log V = 500 * 500'000 log 100'000
    //역방향 다익스트라 , destination 에서 역방향으로 다익스트라
    
    //간선이 1이라 그냥 bfs 해도 충분할 거 같음
    
    dist[destination] = 0;
    queue<int> q;
    q.push(destination);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        
        for(auto a : revRoads[now]){
            
            if(dist[a] == INF ){
                dist[a] = dist[now]+1;
                q.push(a);
            }

            
        }

    }
    

    
    for(auto s : sources){
        
        int val = dist[s] != INF ? dist[s] : -1;
        answer.push_back(val);
        
    }
    
    return answer;
}