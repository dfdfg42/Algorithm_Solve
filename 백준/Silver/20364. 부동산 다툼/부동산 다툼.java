import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    static int N,Q;
    static boolean tree[];
    
    public static void find(int input) {
    	
    	int now = input;
    	boolean can = true;
    	int wall = 1;
    	
    	while(now >= 1 ) {
    		
    		if(tree[now]== true) {
    			can = false;
    			wall = now;
    			
    		}
    		
    		now = now/2;
    		
    	}
    	
    	if(can) {
    		tree[input] = true;
        	System.out.println(0);
    	}
    	else {
    		System.out.println(wall);
    	}
    	

    	
    	
    }
   
    public static void main(String args[]) throws IOException {
       	StringTokenizer st = new StringTokenizer(br.readLine());
       	
       	N = Integer.parseInt(st.nextToken());
       	Q = Integer.parseInt(st.nextToken());
       	
       	tree = new boolean[N+1];
       	
       	for(int i=0; i<Q; i++) {
       		st = new StringTokenizer(br.readLine());
       		int q = Integer.parseInt(st.nextToken());
       		
       		find(q);
       	}
       	

    }
}