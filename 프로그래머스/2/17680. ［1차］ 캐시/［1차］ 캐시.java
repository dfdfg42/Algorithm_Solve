import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        
        if (cacheSize == 0) {
            return cities.length * 5;
        }
        
        int cs = 0;
        HashMap<String,Integer> m = new HashMap<>();
        
        
        int n = cities.length;
        int time = 0;
        for(int i=0; i<n; i++){
            
            String city = cities[i].toLowerCase();
            if(m.containsKey(city)){
                m.put(city,i);
                answer++;
            }
            else if(cs < cacheSize){
                answer += 5;
                m.put(city , i);
                cs++;
               
            }
            else{
                int min = 987654321;
                String s = "";
                for(Map.Entry<String,Integer> entry : m.entrySet()){
                    
                    String target = entry.getKey();
                    int val = entry.getValue();
                    
                    if(val < min){
                        s = target;
                        min = val;
                    }
                    
                }
                
                m.remove(s);
                answer += 5;
                m.put(city,i);
                
               
            }
        }
        
        return answer;
    }
}