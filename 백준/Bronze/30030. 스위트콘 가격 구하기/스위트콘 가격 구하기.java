
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double n = sc.nextDouble();

        int ans = (int) Math.ceil(n /1.1);  

        System.out.println(ans);
    }
}