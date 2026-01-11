import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int[] arr = new int[5];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 5; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int ans = Integer.MAX_VALUE;
        for(int i=0; i<5; i++){
            for(int j=i+1; j<5; j++){
                for(int k= j+1; k<5; k++){
                    int lcm = lcm(arr[i], lcm(arr[j], arr[k]));
                    ans = Math.min(ans,lcm);

                }
            }
        }


        bw.write(String.valueOf(ans));
        
        bw.flush();
        bw.close();
        br.close();
    }

    public static int lcm(int a, int b){
        return a*b / gcd(a,b);
    }

    public static int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
}
