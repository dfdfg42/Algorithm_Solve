#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> imosBoard(n+1, vector<int>(m+1,0));
    
    
    for(auto& s : skill){
        
        int type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int degree = s[5];
        
        imosBoard[r1][c1] += type == 1 ? -degree : degree;
        imosBoard[r1][c2+1] += type == 1 ? degree : -degree;
        imosBoard[r2+1][c1] += type == 1 ? degree : -degree;
        imosBoard[r2+1][c2+1] += type == 1 ? -degree : degree;
        
    }
    
    //가로 누적합 
    for(int i=0; i<=n; i++){
        for(int j=1; j<=m; j++){
            imosBoard[i][j] +=  imosBoard[i][j-1];
        }
    }
    
    //세로 누적합
    for(int i=0; i<=m; i++){
        for(int j= 1; j<=n; j++){
            imosBoard[j][i] +=  imosBoard[j-1][i];
        }
    }
    
    //증감량과 합산
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            board[i][j] += imosBoard[i][j];
            if(board[i][j]>0) answer++;
        }
    }

    
    
    return answer;
}