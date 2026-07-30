import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        
        int n = progresses.length;
        int day = 0;
        int deployCnt = 0;
        
        ArrayList<Integer> ans =  new ArrayList<>();
        
        for(int i=0; i<n; i++){
            
            if(progresses[i] + speeds[i]*day < 100){
                if(deployCnt > 0) ans.add(deployCnt);
                deployCnt = 0;
                
                while(progresses[i] + (speeds[i]*day) < 100){
                    day++;
                }
                
                deployCnt++;
                
                
            }else{
                deployCnt++;
            }
        }
        if(deployCnt > 0) ans.add(deployCnt);
        
        answer = new int[ans.size()];
        for(int i=0; i<ans.size(); i++){
            answer[i] = ans.get(i);
        }
        
        return answer;
    }
}