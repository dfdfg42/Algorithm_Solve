
import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.*;




public class Main {
	
	static int N,M;
	static int[] indegree;
	
	static List<List<Integer>> graph;
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		indegree = new int[N+1];
		graph = new ArrayList<>();
		
		for(int i=0; i<=N; i++) {
			
			graph.add(new ArrayList<>());
			
		}
		
		int seq =1;
		int ans[] = new int[N+1];

		for(int i=0; i<M; i++) {
			
			st = new StringTokenizer(br.readLine());
			
			int a= Integer.parseInt(st.nextToken());
			int b= Integer.parseInt(st.nextToken());
			
			graph.get(a).add(b);
			indegree[b]++;
			
			
		}
		
		Queue<Integer> q = new LinkedList<>();
		
		for(int i=1; i<=N; i++) {
			
			if(indegree[i] == 0) {
				
				q.add(i);
				ans[i] = 1;
			}
			
		}
		

		
		while(!q.isEmpty()) {
			
			int now = q.poll();

			boolean find = false;
			for(int a : graph.get(now)) {
				
				indegree[a]--;
				if(indegree[a] == 0) {
					find = true;
					ans[a] = ans[now]+1;
					q.add(a);
				}
				
			}
			

			
		}
		
		
		for(int i=1; i<ans.length; i++) {
			System.out.print(ans[i] + " " );
		}
		
	}
}
