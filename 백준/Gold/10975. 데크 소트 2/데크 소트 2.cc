#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1; return 0;
    }

    vector<pair<int,int>> vec(n); // 값 , 인덱스
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
        vec[i].second = i;
    }

    int ans = 0;

    sort(vec.begin(), vec.end());

    vector<bool> visited(n, false);



    for (int i = 0; i < n; i++) { //총 n 개를 정렬해야함

        // i 번째 입력 으로 들어왔을때 , 정렬했을때 앞 뒤 값이 이미 방문했는지
        for (int j = 0; j < n; j++) {
            if (vec[j].second == i) { //i번째 인덱스
                visited[j] = true;
                if (j == 0) {
                    if (visited[j + 1] == false) ans++;
                }
                else if(j == n-1 ){
                    if (visited[j - 1] == false)  ans++;
   
                }
                else if (visited[j - 1] == true || visited[j + 1] == true) {

                }
                else {// 앞 뒤 값이 조회 안됬으면 중간에 값이 있으니 덱 하나 더 필요함
                    ans++;
                }
            }
        }

    }

    cout << ans << '\n';

    return 0;
}
