#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<vector<int>> dist;
vector<vector<char>> g_board;



int solution(vector<string> board) {
    
    int n = board.size();
    int m = board[0].length();
    g_board.resize(n,vector<char>(m));

    pair<int,int> start;
    pair<int,int> end;
    
    for(int i=0; i<n; i++){
        string s = board[i];
        for(int j=0; j<s.length(); j++){
            g_board[i][j] = s[j];
            if(g_board[i][j] == 'R'){
                start = {i,j};
            }else if(g_board[i][j] == 'G'){
                end = {i,j};
            }
        }
    }
    
    
    dist.resize(n,vector<int>(m,INT_MAX));
    
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    dist[start.first][start.second] = 0;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<=ny && ny <n && 0<=nx && nx <m && g_board[ny][nx] != 'D'){
                while( (0 <=  ny + dy[i] && ny + dy[i] <  n && 0 <= nx + dx[i] && nx + dx[i] < m) 
                      && (g_board[ny + dy[i]][nx + dx[i]] != 'D')){
                    
                    ny += dy[i];
                    nx += dx[i];
                }
                
                if(dist[ny][nx] > dist[y][x] + 1){
                    dist[ny][nx] = dist[y][x] +1;
                    q.push({ny,nx});
                }
            }

        }
    }

    
    if(dist[end.first][end.second] == INT_MAX){
        return -1;
    }else{
        return dist[end.first][end.second];
    }

}