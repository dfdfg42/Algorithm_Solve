import java.io.*;
import java.util.*;


class point{
    int h;
    int y;
    int x;
    int d;

    point(int h,int y,int x,int d){
        this.h = h;
        this.y = y;
        this.x = x;
        this.d = d;
    }

}


public class Main {

    static int INF = 987654321;
    static int[][][] board;
    static int[][][] dist;
    static int maxDay;
    static int N,M,H;
    static int[] dy = {-1,0,1,0};
    static int[] dx = {0,1,0,-1};

    static boolean check(int y, int x){
        if(y<0 || y>=N || x <0 || x>=M){
            return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        maxDay = 0;
        board = new int[H][N][M];
        dist = new int[H][N][M];

        Queue<point> q = new LinkedList<>(); 

        for(int i=0; i<H; i++){
            for(int j=0; j<N; j++){
                st = new StringTokenizer(br.readLine());
                for(int k =0; k<M; k++){
                    board[i][j][k] = Integer.parseInt(st.nextToken());
                    if(board[i][j][k]==1 ){
                        q.add(new point(i,j,k,0));
                    }
                    else{
                        dist[i][j][k] = INF;
                    }
                    
                }   
            }
        }

        //전체 한바퀴씩 돌면서 1인경우에는 상하좌우 위 아래에 전파 시킴

        while(q.isEmpty() == false){

            point now = q.poll();
            int y = now.y;
            int x = now.x;
            int h = now.h;
            int d = now.d;

            if(dist[h][y][x] < d) continue;

            //일단 같은평면에서 상하좌우
            for(int dd=0;dd<4; dd++){
                int ny = y + dy[dd];
                int nx = x + dx[dd];

                if(!check(ny,nx)) continue;
                if(board[h][ny][nx] == -1 || board[h][ny][nx] == 1) continue;
                if(dist[h][ny][nx] > dist[h][y][x]+1){
                    dist[h][ny][nx] = dist[h][y][x]+1;
                    q.add(new point(h,ny,nx,dist[h][ny][nx]));
                    maxDay = Math.max(dist[h][ny][nx], maxDay);
                }

                

            }

            if(h+1 != H){
                
                if(board[h+1][y][x] == 0 && dist[h+1][y][x] > dist[h][y][x]+1){
                    dist[h+1][y][x] = dist[h][y][x]+1;
                    maxDay = Math.max(dist[h+1][y][x], maxDay);
                    q.add(new point(h+1,y,x,dist[h+1][y][x]));
                }

            }

            if(h-1 != -1){
                if(board[h-1][y][x] == 0 && dist[h-1][y][x] > dist[h][y][x]+1){
                    dist[h-1][y][x] = dist[h][y][x]+1;
                    maxDay = Math.max(dist[h-1][y][x], maxDay);
                    q.add(new point(h-1,y,x,dist[h-1][y][x]));
                }
            }         

        }

        for(int i=0; i<H; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    if(dist[i][j][k] == INF && board[i][j][k] == 0){
                        maxDay = -1;
                       // System.out.print("F" + " ");
                    }
                    //System.out.print(dist[i][j][k] + " ");
                }
                //System.out.println();
            }
        }
        

        System.out.println(maxDay);


    }


}
