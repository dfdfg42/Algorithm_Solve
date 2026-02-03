import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        if (!st.hasMoreTokens()) return;
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];

        int count = 0;
        while (count < N) {
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                arr[count++] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = Integer.MIN_VALUE;
        
        for (int index = 0; index <= N - K; index++) {
            int min = Integer.MAX_VALUE;
            
            for (int i = index; i < index + K; i++) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            if (min > ans) {
                ans = min;
            }
        }

        System.out.println(ans);
    }
}