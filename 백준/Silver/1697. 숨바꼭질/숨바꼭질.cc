#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> time(100001, -1); // 배열의 크기를 100001로 하고, 초기 값을 -1로 설정
    queue<int> q;

    q.push(N);
    time[N] = 0; // 시작 위치의 시간을 0으로 설정

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == K) {
            cout << time[now] << "\n";
            break;
        }

        if (now + 1 <= 100000 && time[now + 1] == -1) {
            q.push(now + 1);
            time[now + 1] = time[now] + 1;
        }

        if (now - 1 >= 0 && time[now - 1] == -1) {
            q.push(now - 1);
            time[now - 1] = time[now] + 1;
        }

        if (now * 2 <= 100000 && time[now * 2] == -1) {
            q.push(now * 2);
            time[now * 2] = time[now] + 1;
        }
    }

    return 0;
}
