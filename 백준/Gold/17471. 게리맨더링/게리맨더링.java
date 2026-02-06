import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    static List<List<Integer>> graph = new ArrayList<>();
    static int[] weight;
    static boolean[] visited;
    static int[] area;
    static int N;
    static int ans;

    //dfs 로 A구역 B구역 나눈후에 -> 각 구역이 연결되있는지 확인 후에 -> 각 구역의 무게합 구하기

    //방문하면서 무게합 구하기
    static void dfs(int node){
        visited[node] = true;
        for(int next : graph.get(node)){
            if(!visited[next] && area[next] == area[node]){
                dfs(next);
            }
        }

    }

    static void divdeArea(int idx){
        // A구역 B구역 나누기
        if(idx == N+1){ //구역을 전부 나누면 두 구역이 연결되었는지 확인
            int connectCount =0;
            visited = new boolean[N+1];
            for(int i=1; i<=N; i++){
                //3곳이상 방문하면 세구역으로 나눠져 있는것임
                if(connectCount >=3){
                    return;
                }
                if(visited[i] == false){
                    dfs(i);
                    connectCount++;
                } 
            }

            //두 구역이 연결되어 있으면 무게합 구하기
            if(connectCount == 2){
                int aWeight =0;
                int bWeight =0;
                for(int i=1; i<=N; i++){
                    if(area[i] ==1){
                        aWeight += weight[i];
                    } else if(area[i] ==2){
                        bWeight += weight[i];
                    }
                }
                ans = Math.min(ans, Math.abs(aWeight - bWeight));
            }

            return;
        }

        //A구역
        area[idx] = 1;
        divdeArea(idx+1);
        area[idx] = 0;
        //B구역
        area[idx] = 2;
        divdeArea(idx+1);
        area[idx] = 0;

    }


    public static void main(String args[]) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        weight = new int[N+1];
        area = new int[N+1];
        for (int i = 0; i <= N+1; i++) {
            graph.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            weight[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=1; i<=N; i++){
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            for(int j=0; j<cnt; j++){
                int to = Integer.parseInt(st.nextToken());
                graph.get(i).add(to);
                graph.get(to).add(i); //양방향
            }
        }
        ans = Integer.MAX_VALUE;
        divdeArea(1);
        if(ans == Integer.MAX_VALUE){
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
       
    }
}