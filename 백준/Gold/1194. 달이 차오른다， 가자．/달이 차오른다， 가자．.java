import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	
	static int N,M;
	static char board[][];
	static int dist[][];
	
	static int dy[] = {-1,0,1,0};
	static int dx[] = {0,1,0,-1};
	static int INF = 987654321;


	
	static BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
	
	static boolean check(int y, int x) {
		if(y<0 || y>=N || x<0 || x>=M) return false;
		
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int sy = 0;
		int sx = 0;
		
		board = new char[N][M];
		int[][][] dist = new int[N][M][64];
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<M; j++) {
				board[i][j] = s.charAt(j);
				if(board[i][j] == '0') {
					sy = i;
					sx = j;
				}
				for(int b=0; b< 64; b++) {
					dist[i][j][b] = INF;
				}

			}
		}
		
		dist[sy][sx][0] = 0;
		Queue<int[]>  q = new LinkedList<>();
		
		q.add(new int[] {sy,sx,0});
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			int y = cur[0];
			int x = cur[1];
			int keyBit = cur[2];
			
			for(int i=0; i<4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(!check(ny,nx)) continue;
				if(board[ny][nx] == '#') continue;
				
				if (board[ny][nx] >= 'A' && board[ny][nx] <= 'F') { 
				    int doorIdx = board[ny][nx] - 'A'; 
				    if ((keyBit & (1 << doorIdx)) != 0) {
				        if (dist[ny][nx][keyBit] > dist[y][x][keyBit] + 1) {
				            dist[ny][nx][keyBit] = dist[y][x][keyBit] + 1;
				            q.add(new int[]{ny, nx, keyBit});
				        }
				    }

				}else if (board[ny][nx] >= 'a' && board[ny][nx] <= 'f') { 
			        int keyIdx = board[ny][nx] - 'a';
			        int nextKeyBit = keyBit | (1 << keyIdx); 
			        
			        if (dist[ny][nx][nextKeyBit] > dist[y][x][keyBit] + 1) {
			            dist[ny][nx][nextKeyBit] = dist[y][x][keyBit] + 1;
			            q.add(new int[]{ny, nx, nextKeyBit});
			        }
			    }
				else if (dist[ny][nx][keyBit] > dist[y][x][keyBit] + 1) {
		            dist[ny][nx][keyBit] = dist[y][x][keyBit] + 1;
		            q.add(new int[]{ny, nx, keyBit});
		        }
					
			}
		}
		
		int ans = INF;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				
				if(board[i][j] == '1') {
					for(int b=0; b<64; b++) {
						ans = Math.min(dist[i][j][b],ans);
					}
				}
				
			}
		}
		
		if(ans == INF) {
			System.out.println(-1);
		}else
		System.out.println(ans);
		

	}

}
