import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int n = numbers.length;
        
        int[] answer = new int[n];
        
        for(int i=0; i<n; i++){
            answer[i] = -1;
        } 
        
        Stack<Integer> stack = new Stack<>();
        
        for(int i=0; i<n; i++){
            
            while(!stack.isEmpty() && numbers[stack.peek()]< numbers[i]){
                    int top = stack.peek();
                    answer[top] = numbers[i];
                    stack.pop();
                }
            
            stack.push(i);
            
            
        }
        
        return answer;
    }
}