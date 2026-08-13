import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        HashSet<String> s = new HashSet<>();
        for(int i=0; i<phone_book.length; i++){
            s.add(phone_book[i]);
        }
        
        for(int i=0; i<phone_book.length; i++){
            
            int len = phone_book[i].length();
            String str = phone_book[i];
            
            for(int j=0; j<len; j++){
                
                String temp = str.substring(0,j);
                    
                if(s.contains(temp)) return false;
                
            }
        }
        
        return answer;
    }
}