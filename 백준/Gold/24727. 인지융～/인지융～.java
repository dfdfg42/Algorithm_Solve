import java.io.*;
import java.util.*;

public class Main {
    static int N, C, E;
    static int[][] board;

    static class Point {
        int r, c;
        Point(int r, int c) { this.r = r; this.c = c; }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String line = br.readLine();
        if (line == null) return;
        N = Integer.parseInt(line);
        
        st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        board = new int[N][N];
        List<Point> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                points.add(new Point(i, j));
            }
        }

        // 1. 영역 1 채우기: i+j가 작은 순서(왼쪽 위 우선)
        Collections.sort(points, (p1, p2) -> {
            if ((p1.r + p1.c) != (p2.r + p2.c)) return (p1.r + p1.c) - (p2.r + p2.c);
            return p1.r - p2.r;
        });
        for (int i = 0; i < C; i++) {
            Point p = points.get(i);
            board[p.r][p.c] = 1;
        }

        // 2. 영역 2 채우기: i+j가 큰 순서(오른쪽 아래 우선)
        Collections.sort(points, (p1, p2) -> {
            if ((p1.r + p1.c) != (p2.r + p2.c)) return (p2.r + p2.c) - (p1.r + p1.c);
            return p2.r - p1.r;
        });
        
        int count2 = 0;
        for (int i = 0; i < points.size(); i++) {
            Point p = points.get(i);
            if (board[p.r][p.c] == 1) continue; // 영역 1이 점유한 곳은 피함
            board[p.r][p.c] = 2;
            count2++;
            if (count2 == E) break;
        }

        // 3. 조건 검사: 개수 부족, 인접 여부, 각각의 연결성
        if (count2 < E || isAdjacent() || !isConnected(1, C) || !isConnected(2, E)) {
            System.out.println("-1");
        } else {
            StringBuilder sb = new StringBuilder();
            sb.append("1\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    sb.append(board[i][j]);
                }
                sb.append("\n");
            }
            System.out.print(sb);
        }
    }

    // 두 영역이 붙어있는지 확인
    static boolean isAdjacent() {
        int[] dr = {0, 0, 1, -1};
        int[] dc = {1, -1, 0, 0};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dr[d], nj = j + dc[d];
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] == 2) return true;
                    }
                }
            }
        }
        return false;
    }

    // 각 영역이 하나로 연결되어 있는지 BFS로 확인
    static boolean isConnected(int type, int targetCount) {
        if (targetCount == 0) return true;
        int sr = -1, sc = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == type) { sr = i; sc = j; break; }
            }
            if (sr != -1) break;
        }
        if (sr == -1) return false;

        boolean[][] visited = new boolean[N][N];
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(sr, sc));
        visited[sr][sc] = true;
        int count = 0;
        int[] dr = {0, 0, 1, -1};
        int[] dc = {1, -1, 0, 0};

        while (!q.isEmpty()) {
            Point curr = q.poll();
            count++;
            for (int d = 0; d < 4; d++) {
                int nr = curr.r + dr[d], nc = curr.c + dc[d];
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc] && board[nr][nc] == type) {
                    visited[nr][nc] = true;
                    q.add(new Point(nr, nc));
                }
            }
        }
        return count == targetCount;
    }
}