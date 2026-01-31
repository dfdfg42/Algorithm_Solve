import java.io.*;
import java.util.StringTokenizer;

class Node {
    int r;
    int c;

    public Node(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int board[][];
    static int R,C,T;
    static Node topMachine;
    static Node downMachine;

    // 0 3 6 9
    //0 3 2 1
    //시계방향은 순서대로  , 반시계는 +3 % 4
    static int dy[] = {0,-1,0,1};
    static int dx[] = {1,0,-1,0};

    static boolean check(int y, int x) {
        if(y<0  || y>=R || x<0 || x>=C) return false;

        if(board[y][x] == -1) return false;

        return true;
    }

        static boolean check2(int y, int x) {
        if(y<0  || y>=R || x<0 || x>=C) return false;


        return true;
    }

    //확산 
    static void spread() {

        //배열 복사
        int tempBoard[][] = new int[R][C];


        //각 칸의 확산 처리 

        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {

                if(board[i][j] >0) {

                    int cnt = 0;
                    
                    int consume = board[i][j] / 5;
                    for(int t=0; t<4; t++) {

                        //공기청정기 있거나, 칸 없으면 그쪽으로 확산 안함 
                        if(check(i+dy[t],j +dx[t])) {
                            cnt++;
                            tempBoard[i+dy[t]][j+dx[t]] += consume; 
                        }
                    }

                    tempBoard[i][j] += (board[i][j] - (consume * cnt));

                }
            }
        }

        tempBoard[topMachine.r][topMachine.c] = -1;
        tempBoard[downMachine.r][downMachine.c] = -1;
        board = tempBoard;

    }

    //바람 이동 
    static void wind() {

        int tempBoard[][] = new int[R][C];

        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                tempBoard[i][j] = board[i][j];
            }
        }
        tempBoard[topMachine.r][topMachine.c+1] = 0;
        tempBoard[downMachine.r][downMachine.c+1] = 0;

        //시계방향 바람 
        int y = topMachine.r;
        int x = topMachine.c+1;
        int dir = 0;

        while(board[y][x] != -1) {
            
            y += dy[dir];
            x += dx[dir];
            //System.out.println("y: "+ y + " x: "+ x + " dir: "+ dir);
            //벽에 닿으면 전환
            if(check2(y,x) == false) {
                
                y -= dy[dir];
                x -= dx[dir];
                dir = (dir + 1) % 4;
                continue;
            }

            // 먼지이동
            tempBoard[y][x] = board[y -dy[dir]][x-dx[dir]] ;

        }

        //반시계방향 바람
        y = downMachine.r;
        x = downMachine.c+1;
        dir = 0;

        while(board[y][x] != -1) {

            y += dy[dir];
            x += dx[dir];

            //벽에 닿으면 전환
            if(!check2(y,x)) {

                
                y -= dy[dir];
                x -= dx[dir];
                dir = (dir +3)%4;
                continue;
            }
            // 먼지이동
            tempBoard[y][x] = board[y -dy[dir]][x-dx[dir]] ;
        }

        tempBoard[topMachine.r][topMachine.c] = -1;
        tempBoard[downMachine.r][downMachine.c] = -1;
        board = tempBoard;
    }

    static long sumDust() {

        long sum = 0;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(board[i][j] == -1) continue;
                sum += board[i][j];
            }
        }

        return sum;
    }

    static void showBoard() {
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        board = new int[R][C];
        boolean foundTop = false;
        for(int i=0; i<R; i++) {

            st = new StringTokenizer(br.readLine());
            for(int j=0; j<C; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());

                if(!foundTop && board[i][j] == -1) {
                    topMachine = new Node(i,j);
                    foundTop = true;
                }
                else if(board[i][j] == -1) {
                    downMachine = new Node(i,j);
                }
            }

        }



        for (int i = 0; i < T; i++) {

            spread();
            //showBoard();
            wind();
            //showBoard();

        }

        long ans = sumDust();

        System.out.println(ans);

    }
}