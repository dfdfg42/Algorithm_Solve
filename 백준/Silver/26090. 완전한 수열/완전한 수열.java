import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    static int N;
    static int arr[];
    static List<Integer> primes = new ArrayList<>();
    static int MAXLEN = 10_000_000;
    static boolean check[] = new boolean[MAXLEN];
    
    
    public static void eratos() {
    	for(int i=2; i<MAXLEN; i++) {
    		if(check[i] == false) {
    			if(i <=500)primes.add(i);
    			
    			for(int j=i+i; j<MAXLEN; j+=i) {
    				check[j] = true;
    			}
    		}
    	}
    	
    }
    
    public static void main(String args[]) throws IOException {
       	StringTokenizer st = new StringTokenizer(br.readLine());
       	
       	N = Integer.parseInt(st.nextToken());
       	arr = new int[N];
       	
       	check[0] = true;
       	check[1] = true;
       	eratos();
       	int ans = 0;
       	
       	st = new StringTokenizer(br.readLine());
       	for(int i=0; i<N; i++) {
       		arr[i] = Integer.parseInt(st.nextToken());
       	}
       	
       	for(int a : primes) {
       		
       		for(int i=0; i<= N-a; i++) {
       			int sum = 0;
       			for(int j=i; j<i+a; j++) {
       				sum += arr[j];
       			}
       			
       			if(check[sum] == false) {
       				//System.out.println(sum + " " + i + " " + a);
       				ans++;
       			}
       			
       		}
       		
       	}
       	
       	System.out.println(ans);

    }
}