import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine(); // 입력 받기
        String[] tokens = input.split(" ");
        int n = Integer.parseInt(tokens[0]); // N 입력
        int k = Integer.parseInt(tokens[1]); // K 입력

        int count = 0; // 약수의 개수 카운트

        for (int i = 1; i <= n; i++) { // 1부터 N까지 약수를 찾음
            if (n % i == 0) {
                count++; // 약수를 찾으면 카운트 증가
                if (count == k) { // K번째 약수라면 출력 후 종료
                    System.out.println(i);
                    return;
                }
            }
        }

        // 약수의 개수가 K보다 적다면 0 출력
        System.out.println(0);
    }
}
