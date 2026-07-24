import java.util.*;

class Solution {
    
    public boolean isCor(Deque<Character> dq){
        
        ArrayList<Character> stack = new ArrayList<>();
        
        for(char now : dq){
            
            if(now == '[' || now == '(' || now == '{'){
                stack.addLast(now);
            }else{
                    
                    if(stack.isEmpty()) return false;
                    char before = stack.getLast();
                    if((now == ']' && before != '[') ||
                       (now == ')' && before != '(') ||
                       (now == '}' && before != '{')){
                        return false;
                    }else stack.removeLast();
                }
            }
             return stack.isEmpty() == true ? true : false;
        }
        
        
    
    public int solution(String s) {
        int answer = 0;
        
        Deque<Character> dq = new ArrayDeque<>();
        
        for(int i=0; i<s.length(); i++){
            dq.addLast(s.charAt(i));
            continue;
        }
        
        for(int i=0; i<s.length(); i++){
            
            if(isCor(dq)){
                answer++;
            }
            
            char first = dq.removeFirst();
            dq.addLast(first);
                
        }
        
        return answer;
    }
}