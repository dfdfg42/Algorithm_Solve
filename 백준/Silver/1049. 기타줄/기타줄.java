import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int minSix = Integer.MAX_VALUE;
        int minOne = Integer.MAX_VALUE;

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            minSix = Math.min(minSix, a);
            minOne = Math.min(minOne, b);


        }
        

        if (minSix > minOne * 6) {
            minSix = minOne * 6;
        }


        int result = (n / 6) * minSix; 
        

        if ((n % 6) * minOne > minSix) {
            result += minSix; 
        } else {
            result += (n % 6) * minOne; 
        }

        sb.append(result);
        System.out.println(sb);
    }
}
