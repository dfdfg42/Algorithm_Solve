#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    int minX = 1001, maxX = 0;
    vector<tuple<int,int,int>> buildings;
    for (int i = 0; i < N; i++){
        int L, R, H;
        cin >> L >> R >> H;
        buildings.push_back(make_tuple(L, R, H));
        minX = min(minX, L);
        maxX = max(maxX, R);
    }
    
    int width = maxX - minX; // x좌표: minX ~ maxX-1
    vector<int> skyline(width, 0);
    
    // 각 x 좌표에서 건물이 덮는 최대 높이(스카이라인)를 구한다.
    for(auto &b : buildings){
        int L, R, H;
        tie(L, R, H) = b;
        for (int x = L; x < R; x++){
            skyline[x - minX] = max(skyline[x - minX], H);
        }
    }
    
    int maxH = 0;
    for (int h : skyline)
        maxH = max(maxH, h);
    
    // 둘레 계산: 
    // - 좌우 양쪽 외곽
    // - 인접 열간 높이 차이
    // - 각 열에서 상단 (건물이 있을 경우)
    int perimeter = 0;
    if(width > 0){
        perimeter += skyline[0] + skyline[width-1];
        for (int i = 1; i < width; i++){
            perimeter += abs(skyline[i] - skyline[i-1]);
        }
    }
    for (int i = 0; i < width; i++){
        if(skyline[i] > 0)
            perimeter += 1;
    }
    
    cout << perimeter << "\n";
    
    // 그림 그리기
    // 그림은 총 maxH+1 줄이며, y=1..maxH는 건물의 경계, y=0는 abscissa(모두 '*').
    // 내부 여부 판단: 
    //   - (col, y)가 건물 내부라면 (y <= skyline[col])
    //   - 단, y==0 (abscissa)는 항상 내부로 간주 (경계에 포함하지 않음).
    auto inside = [&](int col, int y) -> bool {
        if(y == 0) return true; // abscissa를 내부로 간주
        return y <= skyline[col];
    };
    
    // 8방향(상하좌우 및 대각선) 좌표 변화
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // y = maxH 부터 1까지(위쪽부터) 출력
    for (int y = maxH; y >= 1; y--){
        for (int col = 0; col < width; col++){
            if (inside(col, y)) {
                bool border = false;
                for (int k = 0; k < 8; k++){
                    int nx = col + dx[k], ny = y + dy[k];
                    // x 범위를 벗어나면 경계로 처리
                    if(nx < 0 || nx >= width){
                        border = true;
                        break;
                    }
                    // y가 0 미만이면 abscissa가 있으므로 내부로 간주
                    if(ny < 0){
                        continue; 
                    }
                    if(!inside(nx, ny)){
                        border = true;
                        break;
                    }
                }
                cout << (border ? '#' : '.');
            } else {
                cout << '.';
            }
        }
        cout << "\n";
    }
    
    // abscissa 줄: 모든 열에 대해 '*'
    for (int col = 0; col < width; col++){
        cout << '*';
    }
    cout << "\n";
    
    return 0;
}
