import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str = br.readLine(); 
        
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            
            if (c == 'H') {
                stack.push(1);
            } else if (c == 'C') {
                stack.push(12);
            } else if (c == 'O') {
                stack.push(16);
            } else if (c == '(') {
                stack.push(-1); 
            } else if (c == ')') {
                int tempSum = 0;
               
                while (!stack.isEmpty() && stack.peek() != -1) {
                    tempSum += stack.pop();
                }
                stack.pop();
                stack.push(tempSum); 
            } else if (c >= '2' && c <= '9') {
                int top = stack.pop();
                stack.push(top * (c - '0'));
            }
        }
        
        int totalWeight = 0;
        while (!stack.isEmpty()) {
            totalWeight += stack.pop();
        }
        
        System.out.println(totalWeight);
    }
}