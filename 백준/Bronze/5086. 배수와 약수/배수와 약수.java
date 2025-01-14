import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String input = br.readLine();
            
            // 입력이 끊기거나(null) 공백으로만 이루어져 있으면 종료
            if (input == null || input.trim().isEmpty()) {
                break;
            }

            String[] tokens = input.split(" ");
            int n = Integer.parseInt(tokens[0]);
            int m = Integer.parseInt(tokens[1]);

            // 0 0 이 들어오면 종료
            if (n == 0 && m == 0) {
                break;
            }

            /*
               약수(factor):  m % n == 0
               배수(multiple): n % m == 0
             */
            if (m % n == 0) {
                System.out.println("factor");
            } else if (n % m == 0) {
                System.out.println("multiple");
            } else {
                System.out.println("neither");
            }
        }
    }
}
