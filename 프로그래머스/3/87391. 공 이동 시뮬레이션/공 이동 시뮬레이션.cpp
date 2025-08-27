#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    
    //끝점에서부터 되돌아가는게 시간복잡도 맞아보임
    //2번쨰 쿼리까지 역행해서
    //마지막 지점에서 벽에 붙는것만 확인
    ll M = m;
    ll N = n;
    
   ll rmin = x, rmax = x;
    ll cmin = y, cmax = y;
    //역순행하기 
    for(int i = queries.size() -1 ; i>=0; i--){
        int cmd = queries[i][0];
        int dx = queries[i][1];
    
        if(cmd == 0){ //열 증가
            if(cmin != 0) cmin += dx;
            cmax = min(cmax+dx, M-1);
            
        }
        else if(cmd == 1){ // 열감소
            if(cmax != M-1) cmax -=dx;
            cmin = max(cmin-dx,0LL);
        }
        else if(cmd == 2){ // 행 증가
            if(rmin != 0) rmin += dx;
            rmax = min(rmax+dx, N-1);
            
        }else if(cmd == 3){ //행 감소
            if(rmax != N-1) rmax -=dx;
            rmin = max(rmin-dx,0LL);
        }
        if (cmin > cmax || rmin > rmax) {
            return 0;
        }
    }
    

    ll row_count = rmax - rmin + 1;
    ll col_count = cmax - cmin + 1;

    return row_count * col_count;
}