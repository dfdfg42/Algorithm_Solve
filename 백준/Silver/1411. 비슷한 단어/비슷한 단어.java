import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int ans = 0;

        String[] arr = new String[n];
        for(int i = 0; i < n; i++){
            arr[i] = br.readLine();
        }
        
        // 모든 쌍을 비교 (i와 j)
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                int[] fromAtoB = new int[26]; 
                int[] fromBtoA = new int[26]; 
                Arrays.fill(fromAtoB, -1);
                Arrays.fill(fromBtoA, -1);

                boolean flag = true; 

                for (int k = 0; k < arr[i].length(); k++) {
                    int charA = arr[i].charAt(k) - 'a';
                    int charB = arr[j].charAt(k) - 'a';

                    if (fromAtoB[charA] != -1 && fromAtoB[charA] != charB) {
                        flag = false;
                        break;
                    }
                    if (fromBtoA[charB] != -1 && fromBtoA[charB] != charA) {
                        flag = false;
                        break;
                    }

                    fromAtoB[charA] = charB;
                    fromBtoA[charB] = charA;
                }


                if(flag) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}