import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            long n = sc.nextLong();

            // 입력이 0이면 반복 종료
            if (n == 0) {
                break;
            }

            // 1부터 n까지의 합 공식 (등차수열의 합)
            // n * (n + 1) / 2
            long result = (n * (n + 1)) / 2;

            System.out.println(result);
        }
        
        sc.close();
    }
}