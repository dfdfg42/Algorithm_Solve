import java.io.*;
import java.util.*;

class Fish{
	public int distance;
	public int y;
	public int x;
	
	Fish(int distance, int y, int x){
		this.distance = distance;
		this.y = y;
		this.x = x;
	}
	
}

class Shark{
	public int y;
	public int x;
	public int size;
	
	Shark(int y, int x , int size){
		this.y = y;
		this.x = x;
		this.size = size;
	}
}



public class Main {
	
	static int N;
	static int board[][];
	static Shark shark;
	static int dy[] = {-1,0,1,0};
	static int dx[] = {0,1,0,-1};
	static int eatCount =0;
	
	static boolean check(int y, int x) {
		if(0>y || y>=N || x<0 || x>=N) {
			return false;
		}
		return true;
	}
	
	public static List<Fish> findFishes(){
		
		List<Fish> f = new ArrayList<>();
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(board[i][j] < shark.size  && board[i][j]>0) {
					//상어와의거리
					int dist = findRoute(i,j); 

					if(dist != Integer.MAX_VALUE) {
						f.add(new Fish(dist,i,j));
					}

				}
			}
		}
		return f;
		
	}
	
	//bfs로 물고기까지의 거리를  찾기 
	public static int findRoute(int targetY,int targetX) {
		
		int dist[][] = new int[N][N];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				dist[i][j] = Integer.MAX_VALUE;
			}
		}
		
		dist[shark.y][shark.x] = 0;
		
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {shark.y,shark.x});
		
		while(!q.isEmpty()) {
			int [] cur = q.poll();
			int y = cur[0];
			int x = cur[1];
		
			
			for(int i=0; i<4; i++) {
				int ny = y+dy[i];
				int nx = x+dx[i];
				
				if(check(ny,nx) == true && board[ny][nx] <= shark.size  && dist[ny][nx] > dist[y][x]+1) {
					dist[ny][nx] = dist[y][x] + 1;
					q.add(new int[] {ny,nx});
				}
			}
		}
		
		return dist[targetY][targetX];
		
	}

	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    //먹을 수 있는 물고기 목록 확인 -> 상어보다 크기가 작은
    
    //우선순위 큐로 가가운거리 -> Y 낮은순 -> X 낮은 순으로 정렬
    
    //우선순위 높은 물고기 먹을 수 있는지 확인 
    //먹을 수 있으면 이동 ( 같은크기까지는 이동 가능)
   
    public static void main(String args[]) throws IOException {
       	
       	int ans = 0;
       	
       	StringTokenizer st = new StringTokenizer(br.readLine());
       	N = Integer.parseInt(st.nextToken());
       	
       	board = new int[N][N];

       	
       	for(int i=0; i<N; i++) {
       		st = new StringTokenizer(br.readLine());
       		for(int j=0; j<N; j++) {
       			board[i][j] = Integer.parseInt(st.nextToken());
       			if(board[i][j] == 9) {
       		       	shark = new Shark(i,j,2);
       		       	board[i][j]= 0;
       			}
       		}
       	}
       	
       	
       	while(true) {
       		
       		
       		//먹을 수 있는 물고기
       		List<Fish> canEatFishes = findFishes();
       		if(canEatFishes.isEmpty()) break;
       		PriorityQueue<Fish> pq = new PriorityQueue<>((o1, o2) -> {
       		    // 1. 거리 작은 순 
       		    if (o1.distance != o2.distance) {
       		        return o1.distance - o2.distance;
       		    }
       		    // 2. Y좌표 작은 순 
       		    if (o1.y != o2.y) {
       		        return o1.y - o2.y; 
       		    }
       		    // 3. X좌표 작은 순 
       		    return o1.x - o2.x; 
       		});
       		
       		for(Fish f : canEatFishes) {
       			//System.out.println("=== " + f.y + " " + f.x + " " + f.distance);
       			pq.add(f);
       		}
       		
       		Fish target = pq.poll();
       		//System.out.println(target.y +  " "  + target.x + " " + target.distance);
       		//System.out.println("sharkSize: " + shark.size);
       		board[target.y][target.x] = 0;
       		shark.y = target.y;
       		shark.x = target.x;
       		
       		eatCount++;
       		if(eatCount == shark.size) {
       			shark.size +=1;
       			eatCount = 0;
       		}
       		
       		ans+= target.distance;
       		
       		
       	}
       	
       	System.out.println(ans);
       	

    }
}