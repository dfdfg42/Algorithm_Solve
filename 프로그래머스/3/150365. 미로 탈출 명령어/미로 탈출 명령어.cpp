#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int dy[4] = {1, 0, 0, -1};   
int dx[4] = {0, -1, 1, 0}; 
char dc[4] = {'d', 'l', 'r', 'u'};

string answer;
int g_n;
int g_m;
int g_k;
int g_r;
int g_c;

map<pair<int,pair<int,int>>,string> pathMap;

bool isBoundary(int y ,int  x){
    
    if( y < 0 || y >=g_n || x< 0 || x>= g_m){
        return false;
    }
    
    return true;
    
}

bool isReach(int y, int x, int k) {
    int dist = abs(y - g_r) + abs(x - g_c);
    
    return dist <= k && (k - dist) % 2 == 0;
}



string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    x--;
    y--;
    r--;
    c--;
    
    swap(x,y);
    answer = "";
    g_n = n;
    g_m = m;
    g_k = k;
    g_r = r;
    g_c = c;
    
    
    //도달 할수 있는지 확인
    //도달 할 수 있으면 l r u d 순으로 이동
    
    bool can = true;
    while(k>0 && can){
        bool find = false;
        for(int i=0; i<4; i++){
            
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(isBoundary(ny,nx) && isReach(ny,nx,k-1) ){
                y = ny;
                x = nx;
                answer += dc[i];
                k--;
                find = true;
                break;
            } 
            
        }
        if(!find) can = false;
        
    }

    
    return k > 0 ? "impossible" : answer;
}