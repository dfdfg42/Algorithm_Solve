#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pii> points(n);
    for(int i=0;i<n;i++) cin >> points[i].first >> points[i].second;
    
    // 정렬하여 이진 탐색을 가능하게 함
    sort(points.begin(), points.end());
    
    // 모든 쌍의 중간점 합을 저장
    // n=3000일 때 최대 약 4.5e6개의 쌍
    vector<pii> p_sums;
    p_sums.reserve((ll)n * (n-1)/2);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            p_sums.emplace_back(points[i].first + points[j].first, points[i].second + points[j].second);
        }
    }
    
    // 중간점 합을 정렬하여 같은 중간점이 연속으로 오게 함
    sort(p_sums.begin(), p_sums.end());
    
    // 점이 집합에 있는지 빠르게 확인하기 위한 람다 함수
    auto point_exists = [&](ll x, ll y) -> bool {
        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(points[mid].first == x){
                // 같은 x를 가진 점들 중 y를 찾음
                // x가 같은 모든 점의 범위를 찾음
                int start = mid;
                while(start > 0 && points[start-1].first == x) start--;
                int end = mid;
                while(end < n-1 && points[end+1].first == x) end++;
                // 이진 탐색을 통해 y를 찾음
                int l = start, r = end;
                while(l <= r){
                    int m = l + (r - l)/2;
                    if(points[m].second == y) return true;
                    else if(points[m].second < y) l = m +1;
                    else r = m -1;
                }
                return false;
            }
            else if(points[mid].first < x) left = mid +1;
            else right = mid -1;
        }
        return false;
    };
    
    ll max_symmetry = 1; // 최소 하나의 점
    
    int total = p_sums.size();
    int i =0;
    while(i < total){
        pii current = p_sums[i];
        int count =1;
        while(i + count < total && p_sums[i + count] == current){
            count++;
        }
        // current = (x_sum, y_sum)
        ll x_sum = current.first;
        ll y_sum = current.second;
        ll symmetry_count = 2 * (ll)count;
        if(x_sum %2 ==0 && y_sum %2 ==0){
            ll p_x = x_sum /2;
            ll p_y = y_sum /2;
            if(point_exists(p_x, p_y)) symmetry_count +=1;
        }
        if(symmetry_count > max_symmetry){
            max_symmetry = symmetry_count;
        }
        i += count;
    }
    
    // Edge case: 모든 대칭점이 없을 경우, 최대 대칭성은 1
    // 이는 이미 초기화 되어 있음
    
    cout << max_symmetry;
}
