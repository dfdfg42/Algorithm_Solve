import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        // 빠른 입력을 위한 BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 빠른 출력을 위한 BufferedWriter
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 문자열로 한 줄 읽어와서 정수로 변환
        int lambda = Integer.parseInt(br.readLine());

        // 결과 문자열을 담을 변수
        String color = "";

        // 조건 분기
        if (lambda >= 620 && lambda <= 780) {
            color = "Red";
        } else if (lambda >= 590 && lambda < 620) {
            color = "Orange";
        } else if (lambda >= 570 && lambda < 590) {
            color = "Yellow";
        } else if (lambda >= 495 && lambda < 570) {
            color = "Green";
        } else if (lambda >= 450 && lambda < 495) {
            color = "Blue";
        } else if (lambda >= 425 && lambda < 450) {
            color = "Indigo";
        } else if (lambda >= 380 && lambda < 425) {
            color = "Violet";
        }

        // 버퍼에 기록
        bw.write(color);
        
        // 남아있는 데이터를 모두 출력 (필수)
        bw.flush();
        
        // 스트림 닫기
        bw.close();
        br.close();
    }
}