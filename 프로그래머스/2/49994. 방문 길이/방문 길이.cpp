#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(string dirs) {
    int answer = 0;
    
    vector<vector<bool>> board(22,vector<bool> (22,false));
    board[10][10] = true;
    
    int y = 10;
    int x = 10;
    
    for(char d : dirs){
        
        int ny = y;
        int nx = x;
        
        if(d == 'U'){
            
            ny -=2;
            
            
        }else if(d == 'D'){
            
            ny +=2;
            
        }else if(d == 'R'){
            
            nx +=2;
        }
        else if(d == 'L'){
            
            nx -=2;
            
        }
        
        if(ny<0 || ny >=22 || nx < 0 || nx>=22){
            continue;
        }
        
        if(!board[y][x]) {
            board[y][x] = true;
        }
        if(!board[(y+ny)/2][(x+nx)/2]) {
            board[(y+ny)/2][(x+nx)/2] = true;
            answer++;
        }
        
        y = ny;
        x = nx;
        
        
        
    }
    

    
    return answer;
}