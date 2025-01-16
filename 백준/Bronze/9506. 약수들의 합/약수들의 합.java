import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        while (true) {
            // 한 줄을 입력받아 정수로 변환
            int n = Integer.parseInt(br.readLine());
            
            // -1이 입력되면 반복 종료
            if (n == -1) {
                break;
            }
            
            // n의 (자신을 제외한) 약수들의 합을 구함
            int sum = 0;
            ArrayList<Integer> divisors = new ArrayList<>();
            for (int i = 1; i < n; i++) {
                if (n % i == 0) {
                    sum += i;
                    divisors.add(i);
                }
            }
            
            // 약수들의 합이 n과 같으면 완전수 판정
            if (sum == n) {
                // 약수들을 출력 형식에 맞게 나열
                System.out.print(n + " = ");
                for (int i = 0; i < divisors.size(); i++) {
                    System.out.print(divisors.get(i));
                    if (i < divisors.size() - 1) {
                        System.out.print(" + ");
                    }
                }
                System.out.println();
            } else {
                // 완전수가 아닐 경우
                System.out.println(n + " is NOT perfect.");
            }
        }
    }
}
