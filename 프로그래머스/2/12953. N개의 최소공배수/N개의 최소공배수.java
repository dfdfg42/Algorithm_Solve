class Solution {
    
    public int gcd(int a,int b){
        
        if(b != 0){
            return gcd(b , a%b);
        }
        else {
            return a;
        }
    }
    
    int lcm(int a, int b){
        return a*b / gcd(a,b);
    }
    
    public int solution(int[] arr) {
    
        int answer = arr[0];
        for(int i=1; i < arr.length; i++){
            answer = lcm(answer,arr[i]);
        }
        
        
        return answer;
    }
}