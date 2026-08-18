import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        //우선순위 가장 높은거 뭐인지 , 개수추적
        
        int topPri =  0;
        int turn = 0;
        ArrayList<int[]> ar = new ArrayList<>();
        
        for(int i=0; i<priorities.length; i++){
            topPri = Math.max(priorities[i],topPri);
            ar.add(new int []{priorities[i],i});
        }
        
        while(true){
            
            if(ar.get(0)[0] == topPri){
                if(ar.get(0)[1] == location){
                    return turn+1;
                }
                else{
                    ar.remove(0);
                    topPri = 0;
                    for(int i=0; i< ar.size(); i++){
                        if(topPri < ar.get(i)[0]){
                            topPri = ar.get(i)[0];
                        }
                    }
                    turn++;
                    continue;
                }
            }
            
            
            topPri = 0;
            for(int i=0; i< ar.size(); i++){
                if(topPri < ar.get(i)[0]){
                    topPri = ar.get(i)[0];
                }
            }
            
            ar.add(new int[]{ar.get(0)[0],ar.get(0)[1]});
            ar.remove(0);
            
        }
        
        
        
        //return answer;
    }
}