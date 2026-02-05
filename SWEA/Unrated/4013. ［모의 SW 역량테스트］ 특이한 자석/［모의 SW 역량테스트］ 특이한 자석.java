import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{



    static int wheel[][];
    static int point[]; // 12시 방향 인덱스
    static boolean visited[];
    static int k;

    static void wheelRotate(int num, int dir){
        //dir 1: 시계 -1: 반시계

        if(num>0 && !visited[num-1]){ //왼쪽
            int leftNum = num-1;
            if(wheel[leftNum][(point[leftNum]+2)%8] != wheel[num][(point[num]+6)%8]){
                visited[leftNum] = true;
                wheelRotate(leftNum, -dir);
            }
        }
        if(num<3 && !visited[num+1]){ //오른쪽
            int rightNum = num+1;
            if(wheel[rightNum][(point[rightNum]+6)%8] != wheel[num][(point[num]+2)%8]){
                visited[rightNum] = true;
                wheelRotate(rightNum, -dir);
            }
        }

        point[num] = (point[num] - dir + 8) % 8;


    }

    public static int getScore(){
        int score = 0;
        for(int i=0; i<4; i++){
            if(wheel[i][point[i]] == 1){
                score += (1 << i);
            }
        }
        return score;
    }
	public static void main(String args[]) throws Exception
	{
		/*
		   아래의 메소드 호출은 앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
		   여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
		   이 코드를 프로그램의 처음 부분에 추가하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
		   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 메소드를 사용하셔도 좋습니다.
		   단, 채점을 위해 코드를 제출하실 때에는 반드시 이 메소드를 지우거나 주석 처리 하셔야 합니다.
		 */
		//System.setIn(new FileInputStream("res/input.txt"));

		/*
		   표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
		 */
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
            
			wheel = new int[4][8];
			point = new int[]{0,0,0,0};
			k = sc.nextInt();

            for(int i=0; i<4; i++){
                for(int j=0; j<8; j++){
                    wheel[i][j] = sc.nextInt();
                }
            }

            int score = 0;
            for(int i=0; i<k; i++){
                int num = sc.nextInt()-1;
                int dir = sc.nextInt();

                //회전 -> 양옆에랑 서로 맞닿는 부분이 다른지 -> 다르면 양옆에도 회전
                visited = new boolean[4];
                visited[num] = true;
                wheelRotate(num, dir);
            }

            System.out.println("#" + test_case + " " + getScore());
		}
	}
}