import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
  
            for (int j = 0; j < n - 1 - i; j++) {
                sb.append(" ");
            }


            sb.append("*");


            if (i > 0) {
                for (int j = 0; j < 2 * i - 1; j++) {
                    sb.append(" ");
                }

                sb.append("*");
            }

            sb.append("\n");
        }
        
        System.out.print(sb.toString());
    }
}