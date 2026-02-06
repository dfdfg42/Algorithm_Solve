import java.util.Scanner;
import java.io.FileInputStream;



class query {
	private int l;
	private int r;
	private int quantity;
	
	public query(int l, int r, int quantity) {
		this.l = l;
		this.r = r;
		this.quantity = quantity;
	}
	
	public int getL() {
		return l;
	}
	public int getR() {
		return r;
	}
	public int getQuantity() {
		return quantity;
	}
}

class Solution
{
	
	
	static int[] cages;
	static int N,X,M;
	static query qureies[];
	
	
	//현재 우리 수가 조건을 만족하는지 확인
	public static boolean check() {
		
		for(query q : qureies) {
			int l = q.getL();
			int r = q.getR();
			int quantity = q.getQuantity();
			
			int sum = 0;
			//0 base index에 맞춤
			for(int i = l-1; i<=r-1; i++) {
				sum += cages[i];
			}
			if(sum != quantity) {
				return false;
			}
		}
		
		return true;
	}
	
	//dfs 햄스터 하나줄여가면서 조건 만족하는지 확인
	public static boolean dfs(int idx) {
		
		
		if(idx == -1) {
			//쿼리를 만족하는지 체크 
			if(check()) {
				return true;
			}
			return false;
		}
		
		for(int i=0; i<=X; i++) {
			cages[idx] -= i;
			if(dfs(idx-1)) return true;
			cages[idx] += i;
		}
		
		return false;
	}
	
	public static void main(String args[]) throws Exception
	{

		 
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();


		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			X = sc.nextInt();
			M = sc.nextInt();
			
			cages = new int[N];
			qureies = new query[M];
			for(int i=0; i<N; i++) {
				cages[i] = X; //최대로 채움
			}
			
			for(int i=0; i<M; i++) {
				int l = sc.nextInt();
				int r = sc.nextInt();
				int quantity = sc.nextInt();
				
				qureies[i] = new query(l,r,quantity);
			}
			
			boolean can = dfs(N-1);
			System.out.printf("#" + test_case + " ");
			if(can) {

				for(int i=0; i<N; i++) {
					System.out.printf(cages[i] + " ");
				}
				System.out.println();
				
			}else {
				System.out.println(-1);
				
			}
			
			
		}
	}
}