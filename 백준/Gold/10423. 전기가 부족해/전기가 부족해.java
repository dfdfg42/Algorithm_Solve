import java.io.*;
import java.util.*;


class Node implements Comparable<Node>{
    int u,v,cost;

    public Node(int u,int v , int cost){
        this.u= u;
        this.v = v;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node other){
        return Integer.compare(this.cost, other.cost);
    }
}

public class Main {

    static int N,M,K;
    static int[] parent;
    static int[] rnk;

    static public int Find(int x){
        if(parent[x] == x) {
            return parent[x];
        }else{
            return parent[x] = Find(parent[x]);
        }
    }

    static public void Union(int a,int b){

        int A = Find(a);
        int B = Find(b);

        if(rnk[A] < rnk[B]){
            parent[A] = B;
        }else if(rnk[A] > rnk[B]){
            parent[B] = A;
        }else{
            parent[A] =B;
            rnk[B]++;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        parent = new int[N+1];
        rnk = new int[N+1];

        for(int i=0; i<=N; i++){
            parent[i] = i;
            rnk[i] = 0;
        }

        //발전소들은 미리 Union 을 해두면 발전소끼리 중복 방문이 없음
        st = new StringTokenizer(br.readLine());
        int[] gens = new int[K];
        for(int i=0; i<K; i++){
            gens[i]= Integer.parseInt(st.nextToken());
        }

        for(int i=1; i<K; i++){
            Union(gens[i],gens[i-1]);
        }

        List<Node> graph = new LinkedList<>();

        for(int i=0; i<M; i++){

            int u,v,c;
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            graph.add(new Node(u,v,c));

        }

        Collections.sort(graph);
        
        int total = 0;
        for(Node node : graph){
            if(Find(node.u) != Find(node.v)){
                Union(node.u,node.v);
                total += node.cost;
            }
        }
        
        System.out.println(total);
        
    }


}
