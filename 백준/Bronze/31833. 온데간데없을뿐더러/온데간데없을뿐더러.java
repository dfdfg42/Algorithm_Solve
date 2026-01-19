import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();


        StringBuilder sbA = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sbA.append(sc.next()); 
        }

        StringBuilder sbB = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sbB.append(sc.next());
        }


        long numA = Long.parseLong(sbA.toString());
        long numB = Long.parseLong(sbB.toString());

        System.out.println(Math.min(numA, numB));
        
        sc.close();
    }
}