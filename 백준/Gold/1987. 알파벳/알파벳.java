import java.io.*;
import java.util.*;

public class Main {
    static int R, C;
    static char[][] board;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    static int[][] visited; 

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        board = new char[R][C];
        visited = new int[R][C]; 

        for (int i = 0; i < R; i++) {
            board[i] = br.readLine().toCharArray();
        }

        System.out.println(bfs());
    }

    public static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        int startBit = 1 << (board[0][0] - 'A');
        
        // r, c, bit, dist
        q.add(new int[]{0, 0, startBit, 1});
        visited[0][0] = startBit;
        
        int maxDist = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int r = cur[0];
            int c = cur[1];
            int bit = cur[2];
            int dist = cur[3];

            maxDist = Math.max(maxDist, dist);

            for (int i = 0; i < 4; i++) {
                int nr = r + dy[i];
                int nc = c + dx[i];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    int nextCharBit = 1 << (board[nr][nc] - 'A');
                    
                    if ((bit & nextCharBit) == 0) {
                        int nextFullBit = bit | nextCharBit;
                        
                        if (visited[nr][nc] != nextFullBit) {
                            visited[nr][nc] = nextFullBit;
                            q.add(new int[]{nr, nc, nextFullBit, dist + 1});
                        }
                    }
                }
            }
        }
        return maxDist;
    }
}