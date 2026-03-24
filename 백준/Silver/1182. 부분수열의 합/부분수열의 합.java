import java.io.*;
import java.util.*;
public class Main{
	
	static int N,S,ans;
	static int[] arr;
	
	public static void dfs(int depth,int targetDepth ,int index, int val) {
		
		if(depth == targetDepth) {
			
			if(val == S) {
				ans++;
			}

			return;
		}
		
		
		for(int i= index; i< arr.length; i++) {
			
			val += arr[i];
			dfs(depth+1,targetDepth, i+1 , val);
			val -= arr[i];
		}
		
		
		
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		arr = new int[N];
		
		S = Integer.parseInt(st.nextToken());
		ans = 0;
		
		st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=1; i<=N; i++) {
			dfs(0,i,0,0);
		}
		
		//System.out.println(arr.length);
		
		System.out.println(ans);
	}
}