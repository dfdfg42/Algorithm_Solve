import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.*;


class Node implements Comparable<Node>{
	
	int u,v;
	int cost;
	
	public Node(int u,int v,int cost) {
		this.u = u;
		this.v = v;
		this.cost = cost;
	}
	
	@Override
	public int compareTo(Node other){
		return Integer.compare(this.cost, other.cost);
	}
	
}


public class Main {
	
	
	static int M,N;
	static int parent[], rnk[];
	static int sum;
	
	static int Find(int x) {
		if(parent[x] == x) {
			return x;
		}else {
			return parent[x] = Find(parent[x]);
		}
	}

	static void Union(int a, int b) {
		int A  = Find(a);
		int B = Find(b);
		
		if(A==B) {
			return;
		}
		if(rnk[A] > rnk[B]) {
			parent[B] = A; 
		}else if(rnk[B] > rnk[A]) {
			parent[A] = B;
		}
		else {
			parent[A] = B;
			rnk[B]++;
		}
		
	}

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		while(true) {
			
			st = new StringTokenizer(br.readLine());
			
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			sum = 0;
			
			if(M== 0 && N == 0 ) {
				return;
			}
			
			parent = new int[M+1];
			rnk = new int[M+1];
			
			for(int i=0; i<=M; i++) {
				parent[i] = i;
				rnk[i] = 0;
			}
			
			PriorityQueue<Node> pq = new PriorityQueue<>();

			for(int i=0; i<N; i++) {
				st =new StringTokenizer(br.readLine());
				
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				int cost = Integer.parseInt(st.nextToken());
				sum += cost;
				
				pq.add(new Node(u,v,cost));
				
			}
			
			
			int ans = 0;
			while(!pq.isEmpty()) {
				
				Node cur = pq.poll();
				
				int u = cur.u;
				int v = cur.v;
				int cost = cur.cost;
				
				if(Find(u) != Find(v)) {
					
					Union(u,v);
					ans += cost;
					
				}
				
				
			}
			
			System.out.println(sum - ans);
			
		}
		
		
		
	}
}
