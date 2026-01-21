import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String title = sc.next();
            map.put(title, map.getOrDefault(title, 0) + 1);
        }

        String result = "";
        int max = 0;

        for (String title : map.keySet()) {
            int count = map.get(title);

            if (count > max) {
                max = count;
                result = title;
            } else if (count == max) {
                if (title.compareTo(result) < 0) {
                    result = title;
                }
            }
        }

        System.out.println(result);
    }
}