import java.util.*;

class Solution {
    
    int[] g_clothes;
    int n;
    int answer;
    HashMap<String,Integer> m;
    
    public void dfs(int index){
        
        if(index == n){
            answer++;
            return;
        }
        
        for(int i=0; i<=g_clothes[index]; i++ ){
            dfs(index+1);
        }
        
    }
    
    public int solution(String[][] clothes) {
        answer = 0;
        
        
        m = new HashMap<>();
        
        for(int i=0; i<clothes.length; i++){
            m.put(clothes[i][1] , m.getOrDefault(clothes[i][1],0)+1);
        }
        
        g_clothes = new int[m.size()+1];
        int cnt = 0;
        for(Map.Entry<String,Integer> entry : m.entrySet()){
            String key = entry.getKey();
            int val = entry.getValue();
            g_clothes[cnt++] = val;
        }
        
        n = cnt;
        
        dfs(0);
        
        return answer-1;
    }
}