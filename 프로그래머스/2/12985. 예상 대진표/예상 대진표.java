class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 0;
        
        // | 1 해주고 /2 
         
        while(a != b){
            if(a%2 != 0) a += 1;
            
            a /= 2;
            
            if(b%2 !=0 ) b += 1;
            
            b /=2;
            
            answer++;
            
        }
        
        

        return answer;
    }
}