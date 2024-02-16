#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        vector<int> B(M);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        sort(B.begin(), B.end()); // B 배열 정렬

        long long result = 0;

        for (int i = 0; i < N; i++) {
            // 이진 탐색 시작
            int low = 0, high = M - 1, pos = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (A[i] > B[mid]) {
                    pos = mid + 1; // A[i]가 B[mid]보다 크면, pos 업데이트
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            // 이진 탐색 끝

            result += pos; // pos는 A[i]가 B의 원소들 중 몇 개보다 큰지 나타냄
        }

        cout << result << '\n';
    }
    return 0;
}
