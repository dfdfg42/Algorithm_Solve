import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long p = sc.nextLong();

        long result = 1;


        for (int i = 1; i <= n; i++) {
            result = (result * i) % p;
        }

        // 결과 출력
        System.out.println(result);

        sc.close();
    }
}