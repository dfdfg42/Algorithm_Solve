#include <iostream>
using namespace std;

typedef long long ll;

// 최적화된 삼각형 개수 계산 함수
ll countTriangles(int N) {
    ll count = 0;
    // c는 ceil(N/3)부터 floor((N-1)/2)까지
    int c_min = (N + 2) / 3; // ceil(N/3)
    int c_max = (N - 1) / 2; // floor((N-1)/2)
    
    for(int c = c_min; c <= c_max; c++) {
        // a의 최소값과 최대값 계산
        int a_min = max(1, N - 2 * c);
        int a_max = (N - c) / 2;
        
        if(a_min > a_max)
            continue;
        
        int total = a_max - a_min + 1;
        int equilateral = (3 * c == N) ? 1 : 0;
        int isoceles_a = 0;
        
        // a == b인 경우
        if((N - c) % 2 == 0) {
            int a = (N - c) / 2;
            if(a >= a_min && a <= a_max && a < c)
                isoceles_a = 1;
        }
        
        int isoceles_b = 0;
        // b == c인 경우
        int a = N - 2 * c;
        if(a >= 1 && a <= a_max && a < c)
            isoceles_b = 1;
        
        // 부등변 삼각형의 개수 계산
        int scalene = total - equilateral - isoceles_a - isoceles_b;
        
        // 각 경우에 따른 카운트 업데이트
        count += equilateral + isoceles_a + isoceles_b + 2LL * scalene;
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int P;
    cin >> P;

    while (P--) {
        int N;
        cin >> N;
        cout << countTriangles(N) << "\n";
    }

    return 0;
}
