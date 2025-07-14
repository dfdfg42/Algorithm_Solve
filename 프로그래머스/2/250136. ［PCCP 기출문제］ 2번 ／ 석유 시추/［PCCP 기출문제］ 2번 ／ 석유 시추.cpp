#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<vector<int>> visited;
vector<vector<int>> g_land;
int maxPet;
int n, m;

map<int,int> clusters; // id ,사이즈

int solution(vector<vector<int>> land) {
    maxPet = 0;
    
    g_land = land;
    n = land.size();
    m = land[0].size();

    visited.clear();
    visited.resize(n,vector<int>(m,0));
    
    int cluster_id = 0;
    
    for(int j=0; j<m; j++){     
        for(int i=0; i<n; i++){            
            if(visited[i][j] == 0 && land[i][j] == 1){
                int tempPet =0;
                
                queue<pair<int,int>> q;
                queue<pair<int,int>> temp_q;
                
                q.push({i,j});
                temp_q.push({i,j});
                
                tempPet++;
                
                visited[i][j] = 1;
                
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    
                    
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k]; 
                        if(0<=nx && nx < m && 0 <= ny && ny <n){
                            if(visited[ny][nx] == 0 && land[ny][nx] == 1){
                                visited[ny][nx] = 1;
                                q.push({ny,nx});
                                temp_q.push({ny,nx});
                                tempPet++;
                            }
                        }
                    }                    
                }
                
                //찾은 클러스터의 사이즈 입력과 좌표입력
                while(!temp_q.empty()){
                    int y = temp_q.front().first;
                    int x = temp_q.front().second;
                    temp_q.pop();
                    land[y][x] = cluster_id;
                }
                map[cluster_id] = tempPet;
                cluster_id++;
            }

        }
        
        
    }
    
    for(int j=0; j<m; j++){
        int tempP = 0;
        for(int i=0; i<n; i++){
            c_id = -1;
            if(clusters[{i,j].find() != clusters.end()){
                
            }
        }
        
        
    }
    
    return maxPet;
}