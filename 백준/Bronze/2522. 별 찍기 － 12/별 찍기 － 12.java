import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n-1; i++) {
            for(int j=0; j<n-i-1; j++){
                sb.append(" ");
            }

            for(int j=0; j<i+1; j++){
                sb.append("*");
            }
            sb.append("\n");
            
        }
        for(int i=0; i<n; i++){
            sb.append("*");
        }

        sb.append("\n");

        for (int i = 0; i < n-1; i++) {

             for(int j=0; j<i+1; j++){
                sb.append(" ");
            }
            for(int j=0; j<n-i-1; j++){
                sb.append("*");
            }
            sb.append("\n");


            
        }
        
        System.out.print(sb.toString());
    }
}