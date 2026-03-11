import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.*;

class Edge implements Comparable<Edge>{
	
	int v;
	long cost;
	
	public Edge(int v, long dist) {
		this.v = v;
		this.cost = dist;
	}
	
	 @Override
	 public int compareTo(Edge other) {
	        return Long.compare(this.cost, other.cost);
	 }
	
	
}


public class Main {
	
	static final int INF = Integer.MAX_VALUE;
	static int N,E,v1,v2;
	static int dist[];
	
	static long dijkstra(int start, int end) {
		
		
		long[] dist = new long[N+1];
		Arrays.fill(dist,Integer.MAX_VALUE);
		
		dist[start] = 0;
		
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		
		pq.offer(new Edge(start,0));
		
		while(!pq.isEmpty()){
			
			Edge cur = pq.poll();
			int curId = cur.v;
			long cost = cur.cost;
			
			if(dist[curId] < cost) continue;
			
			for(Edge e : graph.get(curId)) {
				int nextNode = e.v;
				long nextCost = e.cost;
				if(dist[nextNode] > dist[curId] + nextCost) {
					dist[nextNode] = dist[curId] + nextCost;
					pq.offer(new Edge(nextNode, dist[nextNode]));
				}
				
			}
			
		}
		
		
		return dist[end];
		
	}

	
	static List<List<Edge>> graph = new ArrayList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		

		N = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		dist = new int[N+1];
		Arrays.fill(dist , INF);
		
		for(int i=0; i<=N; i++) {
			graph.add(new ArrayList<>());
		}
		
		if(E ==0 ) {
			System.out.println(-1);
			return;
		}
		
		for(int i=0; i<E; i++) {
			
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			
			graph.get(u).add(new Edge(v,cost));
			graph.get(v).add(new Edge(u,cost));
			
		}
		
		
		st = new StringTokenizer(br.readLine());
		v1 = Integer.parseInt(st.nextToken());
		v2 = Integer.parseInt(st.nextToken());
		
		//1번에서 N 번으로 이동
		// v1 과 v2 를 통과해야함
		
		// 1 ->v1 -> v2 -> N
		// 1 -> v2 -> v2 -> N
		
		long a = dijkstra(1,v1) + dijkstra(v1,v2) + dijkstra(v2,N);
		long b = dijkstra(1,v2) + dijkstra(v2,v1) + dijkstra(v1,N);
		
		long ans = Math.min(a, b);
		
		if(ans >= Integer.MAX_VALUE) {
			System.out.println(-1);
		}
		else
		System.out.println(ans);
		
		
		
	}
}
