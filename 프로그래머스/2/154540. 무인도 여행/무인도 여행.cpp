#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<bool>> visited;
vector<string> g_maps;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int n,m;

int bfs(int by, int bx , int cnt){
    
    queue<pair<int,int>> q;
    q.push({by,bx});
    
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(0<=ny && ny<n && 0<= nx && nx <m){
                if(!visited[ny][nx] && g_maps[ny][nx] != 'X'){
                    visited[ny][nx] = true;
                    q.push({ny,nx});
                    cnt += g_maps[ny][nx] - '0';
                }
            }
        }
    }
    
    return cnt;
}

vector<int> solution(vector<string> maps) {
    
        
    vector<int> answer;
    g_maps = maps;
    
     n = maps.size();
     m = maps[0].length();
    
    visited.assign(n,vector<bool>(m,false));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && g_maps[i][j] != 'X'){
                visited[i][j] = true;
                answer.push_back(bfs(i,j,g_maps[i][j] - '0'));
            }
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }else
    sort(answer.begin(),answer.end() );

    return answer;
}