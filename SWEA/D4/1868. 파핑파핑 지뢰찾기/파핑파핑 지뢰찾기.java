import java.util.*;
import java.io.*;

class Solution {
    static int N;
    static char[][] board;
    static int[][] mineCount;
    static boolean[][] visited;
    static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            N = Integer.parseInt(br.readLine());
            board = new char[N][N];
            mineCount = new int[N][N];
            visited = new boolean[N][N];

            for (int i = 0; i < N; i++) {
                board[i] = br.readLine().toCharArray();
            }

            // 1. 각 칸 주변의 지뢰 개수 미리 계산
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == '*') {
                        mineCount[i][j] = -1; // 지뢰는 -1로 표시
                        continue;
                    }
                    int cnt = 0;
                    for (int d = 0; d < 8; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if (ny >= 0 && ny < N && nx >= 0 && nx < N && board[ny][nx] == '*') {
                            cnt++;
                        }
                    }
                    mineCount[i][j] = cnt;
                }
            }

            int ans = 0;

            // 2. 주변 지뢰가 0인 칸부터 클릭 (BFS/DFS로 영역 확장)
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (mineCount[i][j] == 0 && !visited[i][j]) {
                        ans++;
                        click(i, j);
                    }
                }
            }

            // 3. 아직 방문하지 않은 빈 칸(지뢰 제외) 클릭
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == '.' && !visited[i][j]) {
                        ans++;
                    }
                }
            }

            System.out.println("#" + test_case + " " + ans);
        }
    }

    // DFS를 이용한 연쇄 반응 처리
    static void click(int y, int x) {
        visited[y][x] = true;

        // 현재 칸이 0일 때만 주변으로 퍼져나감
        if (mineCount[y][x] == 0) {
            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                    // 지뢰가 아니고 아직 방문하지 않았다면 탐색
                    if (board[ny][nx] == '.' && !visited[ny][nx]) {
                        click(ny, nx);
                    }
                }
            }
        }
    }
}