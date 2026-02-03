import java.io.*;
import java.util.StringTokenizer;
import java.util.*;

class Node{
	private int dir;
	private int len;
	
	public Node(int dir2, int val) {
		this.dir =dir2;
		this.len = val;
	}
	public int getDir() {
		return dir;
	}
	public int getLen() {
		return len;
	}
}



public class Main {
	
	static int smallArea,bigArea;

	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	
	static int K;
	static Node nodes[] = new Node[12];

    
    public static void main(String args[]) throws IOException {
        
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	int K = Integer.parseInt(st.nextToken());
    	
    	for(int i=0; i<6; i++) {
    		
    		
    		StringTokenizer st2 = new StringTokenizer(br.readLine());
    		int dir = Integer.parseInt(st2.nextToken());
    		int val = Integer.parseInt(st2.nextToken());
    		
    		nodes[i] = new Node(dir,val);
    		nodes[i+6]= new Node(dir,val);
    	}
    	
    	for(int i=3; i<12; i++) {
    		if(nodes[i-1].getDir() == nodes[i-3].getDir() && nodes[i].getDir() == nodes[i-2].getDir()) {
    			smallArea = nodes[i-1].getLen() * nodes[i-2].getLen();
    			bigArea = nodes[(i+1)].getLen() * nodes[(i+2)].getLen();
    			break;
    		}
    	}
    	
    	//System.out.println(bigArea + " " + smallArea);
    	System.out.println((bigArea - smallArea)*K);
    	
        return;
    }
}