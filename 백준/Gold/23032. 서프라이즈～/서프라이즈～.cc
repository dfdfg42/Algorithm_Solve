#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> W(N);
    for (int i = 0; i < N; i++){
        cin >> W[i];
    }

    // 1) 누적합(prefix sum) 배열 P: P[i] = W[0] + ... + W[i-1], (P[0] = 0)
    //    => sum(L, R) = P[R+1] - P[L]
    vector<long long> P(N+1, 0LL);
    for(int i = 0; i < N; i++){
        P[i+1] = P[i] + W[i];
    }

    long long minDiff = LLONG_MAX; // E의 최솟값
    long long bestSum = 0;        // 그때 구간 [L,R]의 총합 (여러 개면 최대)

    // 2) 모든 연속 구간 [L, R], L < R (학생이 최소 2명 있어야 나눌 수 있음)
    for(int L = 0; L < N; L++){
        for(int R = L + 1; R < N; R++){
            // 구간 합 (L ~ R)
            long long total = P[R+1] - P[L];
            
            // 두 그룹의 합의 차를 최소화하려면
            // sum(L,M)이 total/2 근처가 되어야 함.
            // sum(L,M) = P[M+1] - P[L].
            // -> P[M+1] 근처가 P[L] + total/2
            
            double target = (double)P[L] + (double)total / 2.0;

            // prefix sum 구간에서 탐색 범위는 [L+1, R+1] 사이여야 함
            //   - M+1 in [L+1..R], 즉 M in [L..R-1].
            //   - 따라서 우리가 찾는 K = M+1 은 [L+1..R].
            auto beginIt = P.begin() + (L+1); 
            auto endIt   = P.begin() + (R+1); // 실제 C++ 범위는 [beginIt, endIt)

            // 이분 탐색: prefix sum 값 중에서 target에 가장 가까운 위치를 찾는다.
            auto it = std::lower_bound(beginIt, endIt, target);

            // it, it-1, it+1 등을 확인(범위 안에서)해서 
            // 실제로 차(E)가 가장 작은지 판단하면 된다.
            // (lower_bound가 정확히 target을 가리키지 않을 수 있고, 근처를 봐야 함)
            vector<int> candidates;
            if (it != endIt) {
                candidates.push_back((int)distance(P.begin(), it));
            }
            if (it != beginIt) {
                candidates.push_back((int)distance(P.begin(), it - 1));
            }
            if (it != endIt && (it+1) != endIt) {
                candidates.push_back((int)distance(P.begin(), it + 1));
            }

            // candidates에는 "prefix sum 인덱스"가 저장되며,
            // 그 인덱스를 K라 할 때, M = K - 1
            // sum(L,M) = P[K] - P[L].
            for (int k : candidates){
                if (k >= L+1 && k <= R) {
                    int M = k - 1; 
                    long long sumLM = P[M+1] - P[L];     // [L, M] 합
                    long long diff = llabs(sumLM - (total - sumLM)); // 두 그룹 차
                    
                    // 최소 차 갱신
                    if (diff < minDiff) {
                        minDiff = diff;
                        bestSum = total;
                    } 
                    else if (diff == minDiff) {
                        // 구간 합이 더 큰 게 우선
                        if (total > bestSum) {
                            bestSum = total;
                        }
                    }
                }
            }
        }
    }

    // 최종적으로 찾은 "구간의 전체 스테이크 무게 합" 출력
    cout << bestSum << "\n";
    return 0;
}
