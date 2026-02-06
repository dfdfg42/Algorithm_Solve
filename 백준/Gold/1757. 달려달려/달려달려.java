import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    static int N,M;
 
    static int dp[][];
    static int D[];
   
    public static void main(String args[]) throws IOException {
       	StringTokenizer st = new StringTokenizer(br.readLine());
       	StringBuilder sb = new StringBuilder();
       	
       	int N = Integer.parseInt(st.nextToken());
       	int M = Integer.parseInt(st.nextToken());
       	
       	D = new int[N+1];
       	dp = new int[N+1][M+1]; //분,지침지수 일때 최대거리
       	
       	for(int i=1; i<=N; i++) {
       		st = new StringTokenizer(br.readLine());
       		D[i] = Integer.parseInt(st.nextToken());
       	}
       	
       	for(int i=1; i<=N; i++) {
			dp[i][0] = Math.max(dp[i][0], dp[i-1][0]);
       		for(int j=0; j<=M; j++) { //지침계수 0인경우에는 간거리 0
       			
       			//쉬는경우
   				if(i-j>=0)
       			dp[i][0] = Math.max(dp[i-j][j],dp[i][0]);
       			//현재 분 + 지침계수가 N 초과면 불가능함 
       			if(i+j <= N) {


           			//뛰는경우 연속으로 뛰어야함
       				if(j>0)
           			dp[i][j] = Math.max(dp[i-1][j-1] + D[i] ,dp[i][j]);
       				


       			}

       			 
       		}
       	}
       	
       	int ans = 0;
       	for(int i=1; i<=N; i++) {
       		for(int j=0; j<=M; j++) {
       			if(i+j<=N ) {
       				ans = Math.max(ans,dp[i][j]);
       				//System.out.println(i + " " + j );
       			}
       		}
       	}
       	
       	System.out.println(ans);

    }
}