import java.io.*;
import java.util.StringTokenizer;
import java.util.*;



public class Main {
	

	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer(" ");
	
	static int N,M;
	static int[][] board;
	static int[][] presum;

    
    public static void main(String args[]) throws IOException {
        
    	String[] ss = br.readLine().split(" "); 
    	N = Integer.parseInt(ss[0]);
    	M = Integer.parseInt(ss[1]);
    	board = new int[N+1][N+1];
    	presum = new int[N+1][N+1];
    	
    	for(int i=1; i<=N; i++) {
    		String[] ss2 = br.readLine().split(" ");
    		
    		for(int j=1; j<=N; j++) {
    			board[i][j] = Integer.parseInt(ss2[j-1]);
    		}
    	}
    	
    	for(int i=1; i<=N; i++) {
    		for(int j=1; j<=N; j++) {
    			presum[i][j] = presum[i][j-1] + presum[i-1][j] - presum[i-1][j-1] + board[i][j];
    		}
    	}
    	
//    	System.out.println();
//    	for(int i=1; i<=N; i++) {
//    		for(int j=1; j<=N; j++) {
//    			System.out.print(presum[i][j] + " ");
//    			
//    		}
//    		System.out.println();
//    	}
    	
    	for(int i=0; i<M; i++) {
    		int x1,y1,x2,y2;
    		String[] ss2 = br.readLine().split(" ");
    		x1 = Integer.parseInt(ss2[0]);
    		y1 = Integer.parseInt(ss2[1]);
    		x2 = Integer.parseInt(ss2[2]);
    		y2 = Integer.parseInt(ss2[3]);
    		
    		int ans = presum[x2][y2] - presum[x1-1][y2] - presum[x2][y1-1] + presum[x1-1][y1-1];
    		System.out.println(ans);
    	}
        
        return;
    }
}