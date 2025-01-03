#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, B;
    cin >> N >> M >> B;
    
    // 높이 빈도 배열 (0~256)
    vector<int> height_counts(257, 0);
    int max_height = 0;
    int min_height = 256;
    for(int i = 0; i < N*M; i++){
        int h;
        cin >> h;
        height_counts[h]++;
        if(h > max_height) max_height = h;
        if(h < min_height) min_height = h;
    }
    
    long long min_time = LLONG_MAX;
    int best_height = 0;
    
    // 가능한 높이를 min_height부터 max_height까지 시도
    for(int target = min_height; target <= max_height; target++){
        long long time = 0;
        long long blocks_removed = 0;
        long long blocks_needed = 0;
        
        for(int h = 0; h <= 256; h++){
            if(height_counts[h] == 0) continue;
            if(h > target){
                // 블록을 제거
                time += (long long)(h - target) * 2 * height_counts[h];
                blocks_removed += (h - target) * height_counts[h];
            }
            else if(h < target){
                // 블록을 추가
                time += (long long)(target - h) * height_counts[h];
                blocks_needed += (target - h) * height_counts[h];
            }
        }
        
        // 필요한 블록이 인벤토리 + 제거한 블록보다 작거나 같아야 함
        if(blocks_removed + B >= blocks_needed){
            if(time < min_time){
                min_time = time;
                best_height = target;
            }
            else if(time == min_time && target > best_height){
                best_height = target;
            }
        }
    }
    
    cout << min_time << " " << best_height;
}
