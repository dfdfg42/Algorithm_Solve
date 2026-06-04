import java.util.Arrays;

class Solution
{
    public int solution(int []A, int []B)
    {
        int answer = 0;

        Arrays.sort(A);
        Arrays.sort(B);
        for (int i = 0, j = B.length - 1; i < j; i++, j--) {
            int tmp = B[i]; B[i] = B[j]; B[j] = tmp;
        }
        
        for(int i=0; i<A.length; i++){
            answer += A[i] * B[i];
        }
        

        return answer;
    }
}