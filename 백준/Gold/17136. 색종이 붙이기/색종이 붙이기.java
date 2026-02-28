import java.io.*;
import java.util.*;

public class Main {
	static int[][] oriBoard;
    static int[][] board;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    static int[][] visited; 
    static int ans ;
    
    static boolean check(int y,int x) {
    	if(y <0 || y >=10 || x<0 || x>=10) return false;
    	
    	return true;
    }
    
    static boolean checkPaper(int y, int x , int ny, int nx) {
    	for(int i=y; i<ny; i++) {
    		for(int j=x; j<nx; j++) {
    			if(board[i][j] == 0 || board[i][j] ==2) return false;
    		}
    	}
    	
    	return true;
    }
    
    static void fillPaper(int y,int x ,int ny, int nx) {
    	
    	for(int i=y; i<ny; i++) {
    		for(int j=x; j<nx; j++) {
    			board[i][j] = 2;
    		}
    	}
    	
    }
    
   static void erasePaper(int y,int x ,int ny, int nx) {
    	
    	for(int i=y; i<ny; i++) {
    		for(int j=x; j<nx; j++) {
    			board[i][j] = oriBoard[i][j];
    		}
    	}
    	
    }
   
   
   static boolean isAllcover() {
	   for(int i=0; i<10; i++) {
		   for(int j=0; j<10; j++) {
			   if(board[i][j] == 1) return false;
		   }
	   }
	   
	   return true;
   }
   
   static void showBoard() {
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				System.out.print(board[i][j] + " ");
				
			}
			System.out.println();
		}
   }
    
    
    //브루트 포스로 전체를 확인해버리기
    //(시작할 위치, 사용한 종이 수)
    static void dfs(int y, int x ,int[] paperUseCnt){
    	
    	//System.out.println ("y" + y + " x " + x);
    	int currentSum = 0;
        for (int i = 0; i < 5; i++) currentSum += paperUseCnt[i];
        if (currentSum >= ans) return;
    	
    	
    	
    	for(int i=y; i<10; i++) {
    		int startJ = (i == y) ? x : 0;
    		for(int j=startJ; j<10; j++) {
    			
    			if(board[i][j] == 2) continue;
    			
    			if(board[i][j]==1) {
    				
    				//1~5 크기의 색종이를 씀
        			for(int p=1; p<=5; p++) {
        				if(!check(i+p-1,j+p-1)) continue; 
        				if(!checkPaper(i,j, i+p,j+p)) continue;
        				
        				if(paperUseCnt[p-1] >=5) continue;
        				paperUseCnt[p-1] +=1;
        				//색종이채워줌
        				fillPaper(i,j,i+p,j+p);
        				int nextX = (j + 1 == 10) ? 0 : j + 1;
                        int nextY = (j + 1 == 10) ? i + 1 : i;
                        dfs(nextY, nextX, paperUseCnt);
        				erasePaper(i,j,i+p,j+p);
        				paperUseCnt[p-1] -=1;
        			}
        			
        			return;
    			}
    			

    		}
    	}
    	
    	ans = Math.min(ans, currentSum);

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        board = new int[10][10];
        
        ans = 987654321;
        
        for(int i=0; i<10; i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	for(int j=0; j<10; j++) {
        		
        		board[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        

        oriBoard = new int[10][10];
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                oriBoard[i][j] = board[i][j];
            }
        }
        
        int[] temp  = {0,0,0,0,0};
        dfs(0,0,temp);
        
        if(ans== 987654321) {
        	System.out.println(-1);
        }
        else
        System.out.println(ans);
    }

    
}