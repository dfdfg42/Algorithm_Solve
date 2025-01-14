import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // N 입력 받기
        int N = Integer.parseInt(br.readLine());
        
        // 한 변에 있는 점의 개수를 계산
        long side = (long)Math.pow(2, N) + 1;
        
        // 총 점의 개수 = 한 변 점 개수^2
        long answer = side * side;
        
        // 결과 출력
        System.out.println(answer);
    }
}
