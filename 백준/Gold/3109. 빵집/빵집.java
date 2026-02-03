import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	
	static int R,C;
	static int[][] maps;
	static int max;
	
	static int[] dr = {-1,0,1};
	static int[] dc = {1,1,1};
	
	static boolean check(int nr, int nc) {
		if(0>nr || nr >=R || 0>nc || nc>=C) {
			return false;
		}
		
		if(maps[nr][nc] != 0) return false;
		
		return true;
	}
	
	static boolean gas(int cr , int cc) {
		
		for(int d=0; d<3; d++) {
			
			int nr = cr + dr[d];
			int nc = cc + dc[d];
			
			if(!check(nr,nc)) continue;
			
			
			if(maps[nr][nc]== 0) {
				if(nc == C-1) {
					return true;
				}
				maps[nr][nc] =2;
				if(gas(nr,nc)) return true;
			}
			
			
		}
		return false;
	}
	
	public static void main(String args[]) throws IOException {
		
		BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		R=Integer.parseInt(st.nextToken());
		C=Integer.parseInt(st.nextToken());
		maps = new int[R][C];
		
		for(int i=0; i<R; i++) {
			String ss = br.readLine();
			char[] cs = ss.toCharArray();
			for(int j=0; j<C; j++) {
				if(cs[j]=='x') {
					maps[i][j] = 1;
				}
			}
		}
		
		max=0;
		for(int i=0; i<R; i++) {
			if(maps[i][0] ==0) {
				if(gas(i,0)) max++;;
			}

		}
		System.out.println(max);
		
	}
}
