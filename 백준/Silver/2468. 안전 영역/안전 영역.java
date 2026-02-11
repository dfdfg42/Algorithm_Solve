import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	
	static int N;
	static int maxWaterLevel;
	static int board[][];
	static int ans;
	
	static int dy[] = {-1,0,1,0};
	static int dx[] = {0,1,0,-1};
	
	public static  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	
	//조각들의 개수를 확인
	static int findPieces(int level) {
		
		int pieces = 0;
		
		boolean visited[][] = new boolean[N][N];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				
				//방문 안하고 수위보다 높으면
				if(visited[i][j]==false && board[i][j]>level) {
					pieces++;
					
					Queue<int[]> q = new LinkedList<>();
					q.add(new int[] {i,j});
					visited[i][j] = true;
					
					while(!q.isEmpty()) {
						
						int[] now = q.poll();
						int y = now[0];
						int x = now[1];
						
						for(int t=0; t<4; t++) {
							
							int ny = y + dy[t];
							int nx = x + dx[t];
							
							if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
							if(board[ny][nx] <= level || visited[ny][nx] == true) continue;
							
							visited[ny][nx] = true;
							q.add(new int[] {ny,nx});
							
						}
						
						
						
						
					}
				}
				
			}
		}
		
		//System.out.println(level + " " + pieces);
		return pieces;
		
	}
	

	public static void main(String[] args) throws IOException {
		
		StringTokenizer st;
		
		ans =0;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		board = new int[N][N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				maxWaterLevel = Math.max(maxWaterLevel,board[i][j]);
			}
		}
		
		
		for(int i=0; i<=maxWaterLevel; i++) {
			ans = Math.max(ans,findPieces(i));
		}
		
		System.out.println(ans);

	}

}
