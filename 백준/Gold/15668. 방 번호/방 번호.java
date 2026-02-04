import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    static long N_val;
    static int len;
    static boolean visited[] = new boolean[10];
    static boolean find = false;
    

    static boolean check(long B) {

        if (B <= 0) return false;

        boolean[] currentBUsed = new boolean[10];
        while (B > 0) {
            int digit = (int)(B % 10);
            if (visited[digit] || currentBUsed[digit]) return false; 
            currentBUsed[digit] = true;
            B /= 10;
        }
        return true;
    }
    
    static void dfs(long make, int depth) {
        if (find) return;
        
        if (depth > 0) {
            long resultB = N_val - make;
            if (check(resultB)) {
                System.out.println(make + " + " + resultB);
                find = true;
                return;
            }
        }

        if (depth >= 10 || depth >= len) return;
        
        for (int i = 0; i <= 9; i++) {

            if (depth == 0 && i == 0) continue;
            if (visited[i]) continue;
            
            visited[i] = true;
            dfs(make * 10 + i, depth + 1);
            visited[i] = false;
            
            if (find) return;
        }
    }

    public static void main(String args[]) throws IOException {
        String input = br.readLine();
        if (input == null) return;
        
        N_val = Long.parseLong(input);
        len = input.length();
        
        // DFS 시작
        dfs(0, 0);
        
        if (!find) {
            System.out.println(-1);
        }
    }
}