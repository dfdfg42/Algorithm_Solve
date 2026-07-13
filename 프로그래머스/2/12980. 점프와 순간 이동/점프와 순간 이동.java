import java.util.*;

public class Solution {
    public int solution(int n) {
        int cnt = 0;
        
        while(n != 1){
            if(n%2 != 0){
                n--;
                cnt++;
            }
            n /=2;
        }
        
        

        return cnt+1;
    }
}