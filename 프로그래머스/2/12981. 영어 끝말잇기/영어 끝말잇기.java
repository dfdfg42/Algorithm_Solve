import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        
        HashSet<String> s = new HashSet<>();
        int wlength = words.length;
        String prevWord = words[0];
        s.add(words[0]);
        
        for(int i=1; i<wlength; i++){
            
            int people = i % n;
            
            if(s.contains(words[i]) || words[i].charAt(0) != prevWord.charAt(prevWord.length()-1)){
                System.out.println(i);
                return new int[] {i%n +1 ,(i+n)/n};
            }else{
                s.add(words[i]);
                prevWord = words[i];
            }
            
            
        }

        return new int[]{0,0};
    }
}