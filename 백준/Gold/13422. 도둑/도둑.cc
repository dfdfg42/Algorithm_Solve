#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> homes(N);
        for (int i = 0; i < N; i++) {
            cin >> homes[i];
        }

        int count = 0;
        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += homes[i];
        }

        if (sum < K) count++;

        if (N == M) {
            cout << count << '\n';
            continue;
        }

        for (int i = 0, j = M; i < N-1; i++, j++) {
            sum -= homes[i];
            sum += homes[j % N];

            //cout << "sum :" << sum << endl;
            if (sum < K) count++;
        }

        cout << count << '\n';
    }

    return 0;
}
