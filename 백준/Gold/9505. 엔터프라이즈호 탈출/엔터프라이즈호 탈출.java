

import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static int T,K,W,H,startY,startX;
	static int[] clinton;
	static int[][] dist;
	static char[][] board;
	static int[] dy = {-1,0,1,0};
	static int[] dx = {0,1,0,-1};
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static class Node implements Comparable<Node>{
		int y;
		int x;
		int cost;
		
		public Node(int y, int x, int cost) {
			this.y = y;
			this.x = x;
			this.cost = cost;
		}
		
		@Override
		public int compareTo(Node o) {
			return Integer.compare(this.cost, o.cost);
		}
		
		
	}
	
	public static int bfs() {
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		dist[startY][startX] = 0;
		pq.offer(new Node(startY,startX,0));
		
		while(!pq.isEmpty()) {
			
			Node cur = pq.poll();
			int y = cur.y;
			int x = cur.x;
			int cost = cur.cost;
			
			if (dist[y][x] < cost) continue;
			
			for(int d=0; d<4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				
				if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
				
				if(dist[ny][nx] > cost + clinton[board[ny][nx] - 'A']) {
					dist[ny][nx] = cost + clinton[board[ny][nx] - 'A'];
					pq.add(new Node(ny,nx,cost+clinton[board[ny][nx] - 'A']));
				}
			}
			
		}
		
		
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < H; i++) {
		    for (int j = 0; j < W; j++) {
		        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
		            ans = Math.min(ans, dist[i][j]);
		        }
		    }
		}
		
		return ans;
		
	}
	
	public static void solve() throws NumberFormatException, IOException {
		
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st2.nextToken());
		W = Integer.parseInt(st2.nextToken());
		H = Integer.parseInt(st2.nextToken());
		
		
		board = new char[H][W];
		dist = new int[H][W];
		clinton = new int[26];
		
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				dist[i][j] = 987654321;
			}
		}
		
		for(int i=0; i<K; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			char a = st.nextToken().charAt(0);
			int b = Integer.parseInt(st.nextToken());
			
			clinton[a-'A'] = b;
		}
		
		for(int i=0; i<H; i++) {
			String s = br.readLine();
			
			for(int j=0; j<W; j++) {
				board[i][j] = s.charAt(j);
				if(board[i][j] == 'E') {
					startY = i;
					startX = j;
				}
			}
		}
		
		int ans = bfs();
		
		System.out.println(ans);
		
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		
		T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			solve();
		}
		
		
	}

}
