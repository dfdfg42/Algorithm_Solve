
import java.util.*;
import java.io.FileInputStream;


class Solution
{
    static int N;
    static int[][] graph;
    
    public static int dijkstra(int start){
    
        int[][] dist = new int[N][N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dist[i][j] = 987654321;
            }
        }
        
        dist[start][start] = 0;
        int sumDist = 0;

        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        
        while(!q.isEmpty()){
         	int now = q.poll();
            
            for(int i=0; i<N; i++){
                
                if(graph[now][i] == 1 && dist[start][i] == 987654321){
                    q.add(i);
                    dist[start][i] = dist[start][now]+1;
                    sumDist += dist[start][i];
                }
                
            }
            
        }
        
        return sumDist;
        
    }
    
    
    
	public static void main(String args[]) throws Exception
	{
        
        
		
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
		

            N = sc.nextInt();
            
             graph = new int[N][N];
            
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    graph[i][j] = sc.nextInt();
                }
            }
            
            int cc = 0;
            int minDist= 987654321;
           for(int i=0; i<N; i++){
               
               int temp = dijkstra(i);
               if(temp < minDist){
                   cc= i;
                   minDist = temp;
               }
               
           }
            
            System.out.println("#" + test_case + " " + minDist);

		}
	}
}