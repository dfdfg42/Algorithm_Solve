import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static int bs(int val, int B[], int M) {
        int l = 0;
        int r = M - 1;
        int idx = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (B[mid] >= val) {
                idx = mid;
                r = mid - 1;
            } else {
                idx = mid; 
                l = mid + 1;
            }
        }

        int res = B[idx];
        for (int i = idx - 1; i <= idx + 1; i++) {
            if (i < 0 || i >= M) continue;
            
            long curDiff = Math.abs((long)B[i] - val);
            long resDiff = Math.abs((long)res - val);
            
            if (curDiff < resDiff) {
                res = B[i];
            } else if (curDiff == resDiff) {
                if (B[i] < res) res = B[i];
            }
        }
        return res;
    }

    public static void main(String args[]) throws IOException {
        String firstLine = br.readLine();
        if (firstLine == null) return;
        
        int t = Integer.parseInt(firstLine.trim());
        
        for(int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            
            int A[] = new int[N];
            int B[] = new int[M];
            
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                A[j] = Integer.parseInt(st.nextToken());
            }
            
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                B[j] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(B);

            long ans = 0; 
            for(int j = 0; j < N; j++) {
                ans += (long)bs(A[j], B, M);
            }
            
            System.out.println(ans);
        }
    }
}