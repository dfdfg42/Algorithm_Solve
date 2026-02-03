import java.io.*;
import java.util.StringTokenizer;
import java.util.*;



public class Main {
	

	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer(" ");
	
	static int width,height,N;
	static int round;
	
	static int distance(int a, int b) {
		int shop = 0;
		if(a ==1) {
			shop = width*2 + height -b;
		}else if(a ==2) {
			shop = b;
		}else if(a ==3) {
			shop = width*2 + height + b; 
		}else if(a ==4) {
			shop = width+height -b;
		}
		
		return shop;
	}
    
    public static void main(String args[]) throws IOException {
        
    	String s= br.readLine();
    	String[] ss3 = s.split(" ");
    	width = Integer.parseInt(ss3[0]);
    	height = Integer.parseInt(ss3[1]);
    	round = width*2 + height*2;
    	
    	s = br.readLine();
    	N = Integer.parseInt(s);
    	int shops[] = new int[N];
    	int ans = 0;
    	
    	for(int i=0; i<N; i++) {
    		
    		String s1 = br.readLine();
    		String[] ss = s1.split(" ");
    		
    		int a = Integer.parseInt(ss[0]);
    		int b = Integer.parseInt(ss[1]);
    		
    		shops[i] = distance(a,b);
    	}
    	
    	String s2 = br.readLine();
    	String[] ss2 = s2.split(" ");
    	
    	int a1 = Integer.parseInt(ss2[0]);
    	int a2 = Integer.parseInt(ss2[1]);
    	
    	int guard = distance(a1,a2);
    	

    	for(int i=0; i<N; i++) {
    		int temp = Math.abs(shops[i]-guard);
    		ans += Math.min(Math.abs(round - temp), temp );
    		//System.out.println(temp);
    	}
    	
    	System.out.println(ans);
        
        return;
    }
}