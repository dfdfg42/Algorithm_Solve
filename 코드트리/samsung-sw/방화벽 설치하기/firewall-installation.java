import java.util.*;

public class Main {

    static int n,m;
    static int[][] board;
    static int nonBurned;
    static int[] dy = {-1,0,1,0};
    static int[] dx = {0,1,0,-1};
    static int answer;
 
    //시뮬레이션 진행 -> 불이 퍼지지 않은 최대 크기 
    public static void bfs(ArrayList<int[]>al ){

        for(int[] a : al){
            board[a[0]][a[1]] = 1;   
        }

        Queue<int[]> q = new LinkedList<>();
        int burned = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 2){
                    q.add(new int[]{i,j});
                }
            }
        }

        int[][] copy = new int[n][m];

        for (int i = 0; i < n; i++) {
            copy[i] = board[i].clone();
        }

        while(!q.isEmpty()){
            int[] now = q.poll();
            int y = now[0];
            int x = now[1];

            for(int d=0; d<4; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];

                if(ny<0 || ny >=n || nx<0 || nx>=m) continue;

                if(copy[ny][nx] == 1 || copy[ny][nx] == 2) continue;

                copy[ny][nx] = 2;
                burned++;
                q.add(new int[]{ny,nx});

            }

        }

        answer = Math.max(answer, nonBurned - burned -3);


        for(int[] a : al){
            board[a[0]][a[1]] = 0;   
        }

    }

    public static void setWall(ArrayList<int[]> al , int index){
        
        if(al.size() == 3){
            
            bfs(al);
            return;
        }

        for(int i = index+1; i<n*m; i++){
            int row = i/m;
            int col = i%m;
            if(board[row][col] == 0){
                al.add(new int[]{row,col});
                setWall(al,i);
                al.remove(al.size() - 1);
            }

        }


    }

    public static void main(String[] args) {

        // 2 불 1 방화벽 0 빈공간
        // n,m <=8
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        nonBurned = 0;
        board = new int[n][m];
        answer = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] = sc.nextInt();
                if(board[i][j] == 0) nonBurned++;
            }
        }
        ArrayList<int[]> al = new ArrayList<>();
        //방화벽 3개 설치
        setWall(al,-1);
        

        System.out.println(answer);

    }
}