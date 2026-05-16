#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;
vector<int> rnk;

int Find(int x){
    
    if(parent[x] == x){
        return x;
    }
    else return parent[x] = Find(parent[x]);
    
}

void Union(int a, int b){
    
    int A = Find(a);
    int B = Find(b);
    
    if(A != B){
        if(rnk[A] < rnk[B]){
          parent[A] = B;
            
        }else if(rnk[B] < rnk[A]){
            parent[B] = A;
        }else {
            parent[B] = A;
            rnk[A]++;
        }
    }
    
}




int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //최소 스패닝 트리 사용하기
    parent.resize(n+1);
    rnk.resize(n+1,0);
    
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
    
    //costs 를 세번째 원소 기준으로 정렬
    
    vector<pair<int,pair<int,int>>> edges;
    
    for(auto c : costs){
        edges.push_back({c[2],{c[0],c[1]}});
    }
    
    sort(edges.begin(),edges.end());
    

    for(auto e : edges){
        
        int cost = e.first;
        int a = e.second.first;
        int b =  e.second.second;
        
        if(Find(a) != Find(b) ){
            Union(a,b);
            answer += cost;
        }
        
    }
    
    
    return answer;
}