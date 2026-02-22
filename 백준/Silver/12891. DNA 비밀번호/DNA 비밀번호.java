
import java.io.*;
import java.util.*;

public class Main {

    static int A,C,G,T, S,P ,a,c,g,t;
    static String s;
    
    static boolean can(){

        if(a>=A && c>= C && g >= G && t>= T){
            return true;
        }

        return false;
    }

    static void dnaPlus(char input){
        if(input == 'A') a++;
        if(input == 'C') c++;
        if(input == 'G') g++;
        if(input == 'T') t++;
    }    
    static void dnaMinus(char input){
        if(input == 'A') a--;
        if(input == 'C') c--;
        if(input == 'G') g--;
        if(input == 'T') t--;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        s = br.readLine();

        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        G = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        int l = 0;
        a=0;
        c=0;
        g=0;
        t=0;
        int ans =0;
        for (int i = 0; i < P; i++) {
            dnaPlus(s.charAt(i));
        }
        if (can()) ans++;


        for (int i = P; i < S; i++) {
            int left = i - P; 
            dnaPlus(s.charAt(i));    
            dnaMinus(s.charAt(left)); 
            
            if (can()) ans++; // 매번 체크
        }

        System.out.println(ans);
    }
}