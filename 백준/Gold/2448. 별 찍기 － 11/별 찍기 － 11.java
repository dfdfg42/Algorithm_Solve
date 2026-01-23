import java.util.*;
import java.io.*;

public class Main {
    static char[][] star;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        if (input == null) return;
        int n = Integer.parseInt(input);

        star = new char[n][2 * n - 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(star[i], ' ');
        }

        draw(0, n - 1, n);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                sb.append(star[i][j]);
            }
            sb.append('\n');
        }
        System.out.print(sb.toString());
    }

    private static void draw(int r, int c, int n) {
        if (n == 3) {
            star[r][c] = '*';
            star[r + 1][c - 1] = '*';
            star[r + 1][c + 1] = '*';
            for (int j = 0; j < 5; j++) {
                star[r + 2][c - 2 + j] = '*';
            }
        } else {
            int size = n / 2;
            draw(r, c, size);
            draw(r + size, c - size, size);
            draw(r + size, c + size, size);
        }
    }
}