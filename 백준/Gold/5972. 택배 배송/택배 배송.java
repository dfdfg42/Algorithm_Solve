import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{

    int v;
    int cost;

    public Node(int v, int cost){
        this.v = v;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.cost, o.cost);
    }
}


public class Main {

    static int INF = 987654321;
    static int N,M;
    static List<List<Node>> graph;
    static int[] dist;

    public static void dijkstra(){

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(1,0));

        while(pq.isEmpty() == false){

            Node now = pq.poll();
            int nowNode = now.v;
            int nowCost = now.cost;

            if(dist[nowNode] < nowCost) continue;

            for(Node e : graph.get(nowNode)){
                
                if(dist[e.v] > dist[nowNode] + e.cost){
                    dist[e.v] = dist[nowNode] + e.cost;
                    pq.add(new Node(e.v,dist[e.v]));
                }
            }

        }




    }
    

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new int[N+1];
        for(int j=0; j<=N; j++){

            dist[j] = INF;
        }
        dist[1] = 0;
        graph =  new ArrayList<>();;

        for(int i=0; i<=N; i++){
            graph.add( new ArrayList<>());
        }

        for(int i=0; i<M; i++){
            int u,v,c;

            st = new StringTokenizer(br.readLine());
            u  = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            graph.get(u).add(new Node(v, c));
            graph.get(v).add(new Node(u, c));
        }

        int ans = INF;


        dijkstra();
        ans = dist[N];

        // for(int i=1; i<=N; i++){
        //     System.out.print(dist[i] + " ");
        // }
        
        if(ans == INF) {
            System.out.println(-1);
        }else
        System.out.println(ans);
    }


}
