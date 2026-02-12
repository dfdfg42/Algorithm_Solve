import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	
	static int K,W,H;
	static int board[][];
	static int dist[][][];// [k사용횟수][y][x]
	
	static int dy[] = {-1,0,1,0};
	static int dx[] = {0,1,0,-1};
	
	static int ky[] = {-1,-2,-2,-1,1,2,2,1};
	static int kx[] = {-2,-1, 1, 2,2,1,-1,-2};

	
	static BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
	
	static boolean check(int y, int x) {
		if(y<0 || y>=H || x<0 || x>=W) return false;
		
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		
		board = new int[H][W];
		dist = new int[K + 1][H][W];
		for(int i=0; i<H; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<W; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				
				for(int t=0; t<=K; t++) {
					dist[t][i][j] = -1;
				}
			}
		}
		
		
		dist[0][0][0] = 0;
		Queue<int[]>  q = new LinkedList<>();
		
		q.add(new int[] {0,0,0});
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			int y = cur[0];
			int x = cur[1];
			int useK = cur[2];
			
			for(int i=0; i<4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(!check(ny,nx)) continue;
				if(board[ny][nx] == 1) continue;
				
				if(dist[useK][ny][nx] == -1 || dist[useK][ny][nx] > dist[useK][y][x] +1) {
					dist[useK][ny][nx] = dist[useK][y][x] +1;
					q.add(new int[] {ny,nx,useK});
				}
			}
			
			if(useK == K) continue;
			
			for(int i=0; i<8; i++) {
				int ny = y + ky[i];
				int nx = x + kx[i];
				
				if(!check(ny,nx)) continue;
				if(board[ny][nx] == 1) continue;
				
				if(dist[useK+1][ny][nx] == -1 || dist[useK+1][ny][nx] > dist[useK][y][x] +1) {
					dist[useK+1][ny][nx] = dist[useK][y][x] +1;
					q.add(new int[] {ny,nx,useK+1});
				}
			}
			
		}
		
		
		int ans  = Integer.MAX_VALUE;
		
		for(int i=0; i<=K; i++) {
			if(dist[i][H-1][W-1] == -1) continue;
			
			ans = Math.min(ans, dist[i][H-1][W-1]);
		}
		
//		for(int i=0; i<H; i++) {
//			for(int j=0; j<W; j++) {
//				System.out.print(dist[0][i][j]);
//			}
//			System.out.println();
//		}
//		
		
		if(ans == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(ans);

	}

}
