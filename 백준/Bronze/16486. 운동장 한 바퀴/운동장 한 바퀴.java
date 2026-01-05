import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double d1 = Integer.parseInt(br.readLine());
        double d2 = Integer.parseInt(br.readLine());
        double pi = 3.141592;

        double distance = d1*2 + (d2*2*pi);
        System.out.printf("%.6f\n", distance);

    }
}
