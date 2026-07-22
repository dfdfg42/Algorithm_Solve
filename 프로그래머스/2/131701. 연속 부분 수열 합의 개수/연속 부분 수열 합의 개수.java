import java.util.*;

class Solution {
    public int solution(int[] elements) {
        
        int n = elements.length;
        int[] arr = new int[2*n];
        HashSet<Integer> s = new HashSet<>();
        
        for(int i=0; i<n; i++){
            arr[i] = elements[i];
            arr[n+i] = elements[i];
        }
        
        //길이
        for(int i=1; i<=n; i++){
            
            
            int l = 0;
            int sum = 0;
            
            for(int j=0; j<i; j++){
                sum += arr[j];
            }
            
            s.add(sum);
            
            for(int r= i; r<2*n; r++){
                
                sum += arr[r];
                sum -= arr[l++];
                
                s.add(sum);
                
            }
            
            
        }
        
        //System.out.println(s.toString());

        return s.size();
    }
}