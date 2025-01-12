import java.util.Scanner;

public class Main {
    // 전역 변수 선언
    static int a, b;
    static int n;
    static boolean[][] paper;

    // 종이를 채우는 메서드
    static void fill() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                // 인덱스가 0부터 시작하므로 260 대신 259를 사용
                // 또한, 종이의 크기가 260이므로 인덱스 범위를 벗어나지 않도록 주의
                int row = 260 - (b + i);
                int col = 260 - (a + j);
                if (row >= 0 && row < 260 && col >= 0 && col < 260) {
                    paper[row][col] = true;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 입력 받기
        n = sc.nextInt();

        // 종이 초기화 (기본값은 false)
        paper = new boolean[260][260];

        // n번 반복하며 종이에 색칠하기
        for (int count = 0; count < n; count++) {
            a = sc.nextInt();
            b = sc.nextInt();
            fill();
        }

        // true인 칸의 개수 세기
        int ans = 0;
        for (int i = 0; i < 260; i++) {
            for (int j = 0; j < 260; j++) {
                if (paper[i][j]) {
                    ans++;
                }
            }
        }

        // 결과 출력
        System.out.println(ans);

        sc.close();
    }
}
