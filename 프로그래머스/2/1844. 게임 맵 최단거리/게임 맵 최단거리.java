import java.util.*;

class Solution {
    
    int dy[] = {-1,0,1,0};
    int dx[] = {0,1,0,-1};
    
    public int solution(int[][] maps) {
        int answer = 0;
        
        int n = maps.length;
        int m = maps[0].length;
        
        Queue<int[]> q = new LinkedList<>();
        
        int[][] dist = new int[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dist[i][j] = 987654321;
            }
        }
        dist[0][0] = 1;
        q.add(new int[]{0,0});
        
        while(!q.isEmpty()){
            
            int[] now = q.poll();
            int y = now[0];
            int x = now[1];
            
            for(int d=0; d<4; d++){
                
                int ny = y + dy[d];
                int nx = x + dx[d];
                
                if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                if(maps[ny][nx] == 0 ) continue;
                
                if(dist[ny][nx] > dist[y][x] +1){
                    
                    q.add(new int[]{ny,nx});
                    dist[ny][nx] = dist[y][x] +1;
                    
                }
                
            }
            
        }
        
        
        return dist[n-1][m-1] != 987654321 ? dist[n-1][m-1] : -1;
    }
}