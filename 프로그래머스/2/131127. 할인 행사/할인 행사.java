import java.util.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        int need = 0;
        
        HashMap<String,Integer> m = new HashMap<>();
        
        for(int i=0; i<want.length; i++){
            m.put(want[i],number[i]);
            need += number[i];
        }
        
        int hit = 0;
        for(int i=0; i<10; i++){
            if(m.containsKey(discount[i])){
                m.put(discount[i] ,m.get(discount[i])-1);
                if(m.get(discount[i]) >=0)
                hit++;
 
            }
        }
        
        if(hit == need) answer++;
        
        int l = 0;
        
        for(int r= 10; r < discount.length; r++){
            if(m.containsKey(discount[r])){
                m.put(discount[r] ,m.get(discount[r])-1);
                if(m.get(discount[r]) >= 0)
                hit++;
                
            }
            if(m.containsKey(discount[l])){
                m.put(discount[l] ,m.get(discount[l])+1);
                if(m.get(discount[l]) > 0)
                hit--;

            }
            l++;
            
            if(hit == need) answer++;
            
        }
        
        return answer;
    }
}