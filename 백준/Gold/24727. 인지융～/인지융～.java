import java.io.*;
import java.util.*;

public class Main {
    static int N, C, E;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        board = new int[N][N];

        // 1. 영역 1 채우기 (왼쪽 위부터 대각선 방향으로)
        int count1 = 0;
        outer1:
        for (int sum = 0; sum <= 2 * (N - 1); sum++) {
            for (int i = 0; i < N; i++) {
                int j = sum - i;
                if (j >= 0 && j < N) {
                    board[i][j] = 1;
                    count1++;
                    if (count1 == C) break outer1;
                }
            }
        }

        // 2. 영역 2 채우기 (오른쪽 아래부터 대각선 방향으로)
        int count2 = 0;
        outer2:
        for (int sum = 2 * (N - 1); sum >= 0; sum--) {
            for (int i = N - 1; i >= 0; i--) {
                int j = sum - i;
                if (j >= 0 && j < N) {
                    if (board[i][j] == 1) continue; // 이미 1이 차있으면 건너뜀
                    board[i][j] = 2;
                    count2++;
                    if (count2 == E) break outer2;
                }
            }
        }

        // 3. 인접 여부 검사
        if (isAdjacent()) {
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

    static boolean isAdjacent() {
        int[] dy = {-1, 1, 0, 0};
        int[] dx = {0, 0, -1, 1};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dy[d];
                        int nj = j + dx[d];
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                            if (board[ni][nj] == 2) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}