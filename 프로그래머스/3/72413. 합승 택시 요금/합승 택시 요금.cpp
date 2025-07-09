#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

const int INF = 1e9;
int N;
vector<vector<ll>> dist;

void floyd(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    N=n;
    dist.resize(n+1,vector<ll>(n+1,INF));
    
    for(auto a : fares){
        dist[a[0]][a[1]] = a[2];
        dist[a[1]][a[0]] = a[2];
    }
    
    for(int i=1; i<=n; i++){
        dist[i][i] =0;
    }
    
    floyd();
    
    ll answer = INF;
    
    //도착지점 브루트포스
    for(int i=1; i<=n; i++){
        ll temp = 0;
        temp += dist[s][i];
        temp += dist[i][a];
        temp += dist[i][b];
        //cout << temp <<'\n';
        answer = min(temp,answer);
    }
    
    
    return answer;
}
