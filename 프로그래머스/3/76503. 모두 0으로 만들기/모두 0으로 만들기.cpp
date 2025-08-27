#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;


ll total = 0;
vector<vector<int>> graph;
vector<ll> long_a;
int ans;

void dfs(int current,int parent){
    
    for(int neighbor :graph[current]){
        if(neighbor != parent){
            dfs(neighbor,current);
        }
    }
    
    //자식노드 탐색끝나고 부모노드에게 가중치 이동
    total += abs(long_a[current]);
    
    if(parent != -1){
        long_a[parent] += long_a[current];
    }
    
}



long long solution(vector<int> a, vector<vector<int>> edges) {
    
    
    //가중치를 음수쪽으로 얼마만큼 빠르게 전달시키냐
    //음수노드와 양수노드의 거리
    //음수노드들을 저장해두고 , 각 양수노드들이 음수노드로 전달시키면된다.
    // 간선 * 이동할가중치의 양  = 이동횟수
    //양수가 음수의 총량보다 적으면 불가능
    //리프노드서부터 중간으로 모은다 -> dfs로 순회 ->리프노드에 도달하면 합치기
    
    
    //1. 모든 노드의 합을 확인
    ll sum =0;
    for(auto au : a){
         sum += (ll)au;
    }
    if(sum != 0){
        return -1;
    }
    
    //2. 
    int n = a.size();
    total = 0;
    graph.assign(n,vector<int>());
    long_a.assign(a.begin(),a.end());
    
    for(auto& edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    dfs(0,-1);

    return total;
}