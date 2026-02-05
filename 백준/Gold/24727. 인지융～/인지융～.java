import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    static int N;
    static int A, B;
    static int board[][];
    static int dyA[] = {0,0,1};
    static int dxA[] = {1,-1,0};
    
    static int dyB[] = {0,0,-1};
    static int dxB[] = {-1,1,0};
    
    static int dy[] = {-1,0,1,0};
    static int dx[] = {0,1,0,-1};
     
    static int lastBy;
    static int lastBx;
    
    static boolean check(int y, int x) {
    	if(y<0 || y>=N || x<0 || x>=N) return false;
    	
    	return true;
    }
    
    static void dfsA(int y, int x ) {
		board[y][x] = 2;
		A--;
    	if(A == 0 ) return;
    		
    	for(int i=0;i<3; i++) {
    		int ny = y + dyA[i];
    		int nx = x + dxA[i];
    		
    		if(!check(ny,nx)) continue;
    		
    		if( board[ny][nx] != 0) continue;
    		


    		dfsA(ny,nx);
    		
    		break;
    	}
    	
    	return;
    }
    
    static void dfsB(int y, int x ) {
    	board[y][x] = 1;
    	lastBy = y;
    	lastBx = x;
    	
		B--;
    	if(B == 0 ) return;
		
    	for(int i=0;i<3; i++) {
    		int ny = y + dyB[i];
    		int nx = x + dxB[i];
    		
    		if(!check(ny,nx)) continue;
    		
    		if( board[ny][nx] != 0) continue;
    		
    		dfsB(ny,nx);
    		
    		break;
    	}
    	
    	return;
    }
    
    static boolean can() {
    	
    	for(int i=0; i<4; i++) {
    		int ny = lastBy +dy[i];
    		int nx = lastBx + dx[i];
    		
    		if(!check(ny,nx)) continue;
    		
    		if(board[ny][nx] == 2) return false;
    	}
    	
    	return true;
    }
    
   
    public static void main(String args[]) throws IOException {
       	StringTokenizer st = new StringTokenizer(br.readLine());
       	StringBuilder sb = new StringBuilder();
       	
       	N = Integer.parseInt(st.nextToken());
       	
       	board = new int[N][N];
       	
       	st = new StringTokenizer(br.readLine());
       	A = Integer.parseInt(st.nextToken());
       	B = Integer.parseInt(st.nextToken());
       	
       	if(N%2 ==0) {
           	dfsA(0,0);
       	}else dfsA(0,N-1);

       	dfsB(N-1,N-1);
       	
       	//System.out.println(lastBy + " " + lastBx);
       	
       	if(!can()) {
       		sb.append(-1 + "\n");
       	}
       	else {
       		sb.append(1 + "\n");
       		for(int i=0; i<N; i++) {
       			for(int j=0; j<N; j++) {
       				sb.append(board[i][j]);
       			}
       			sb.append("\n");
       		}
       	}
       	
       	System.out.println(sb.toString());

    }
}