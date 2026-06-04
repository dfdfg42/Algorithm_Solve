class Solution {
    boolean solution(String s) {
        boolean answer = true;

        int openCount = 0;
        int n = s.length();
        
        for(int i=0; i<n; i++){
            
            char c = s.charAt(i);
            if(c == '('){
                openCount++;
            }else{
                if(openCount <=0) {
                    return false;
                }
                else{
                    openCount--;
                }
            }
            
        }
        
        

        return openCount == 0 ? true : false;
    }
}