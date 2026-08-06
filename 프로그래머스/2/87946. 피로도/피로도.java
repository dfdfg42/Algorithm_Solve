class Solution {
    
    int[][] g_dungeons;
    int len;
    int answer;
    
    public void dfs(int index, int clear , int health , boolean[] visited){
        
        if(index == len){
            answer = Math.max(answer,clear);
            return;
        }
        
        for(int i=0; i<len; i++){
            
            if(visited[i]) continue;
            
            if(health >= g_dungeons[i][0]){
                
                visited[i] = true;
                dfs(index+1, clear+1, health - g_dungeons[i][1] , visited);
                visited[i] = false;
                
            }
            else if(health < g_dungeons[i][0]) {
                visited[i] = true;
                dfs(index+1, clear, health , visited);
                visited[i] = false;
                
            }
        }
        
        return;
        
    }
    
    public int solution(int k, int[][] dungeons) {
         answer = 0;
        
        g_dungeons = dungeons;
        len = dungeons.length;
        boolean[] vis = new boolean[len];
        dfs(0,0,k,vis);
        
        return answer;
    }
}