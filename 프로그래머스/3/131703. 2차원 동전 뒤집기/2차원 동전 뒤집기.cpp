#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> g_target;
int n,m;
int ans;

//행바꿧을때 전부 같은지 아니면 전부 반전인지 확인
int checkCol(const vector<vector<int>>& b) {
    int flips = 0;
    for (int j = 0; j < m; ++j) {
        bool same = true, rev = true;
        for (int i = 0; i < n; ++i) {
            if (b[i][j] != g_target[i][j]) same = false;
            if (b[i][j] == g_target[i][j]) rev  = false;
        }
        if (!same && !rev) return -1;  
        if (rev)        flips++;  
    }
    return flips;
}

//각 행을 뒤집는 것에 대해서 dfs
void dfs(int index, int count ,vector<vector<int>> & board){
    
    int checkVal = checkCol(board);
    if(checkVal != -1)     ans = min(ans, count + checkVal);
    
    //index행을 뒤집지않음
    if(index + 1 < n) dfs(index + 1 , count ,board);
    
    //index행을 뒤집음
    for(int col = 0; col<m; col++){
        board[index][col] = board[index][col] == 1 ? 0 : 1;
    }
    
    int checkVal2 = checkCol(board);
    if(checkVal2 != -1)     ans = min(ans, count + checkVal2 + 1);
    
    if(index + 1 < n) dfs(index +1 , count + 1 , board);
    
    for (int col = 0; col < m; col++)
    board[index][col] ^= 1;
    
    return;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    g_target = target;
    n = target.size();
    m = target[0].size();
    ans = INT_MAX;
    

    dfs(0,0,beginning);
    
    if(ans== INT_MAX) ans = -1;
    return ans;
}