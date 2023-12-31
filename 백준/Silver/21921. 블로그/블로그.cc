#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> visitors(N);
    for (int i = 0; i < N; i++) {
        cin >> visitors[i];
    }

    ll maxVisitor = 0, nowVisitor = 0;
    int count = 0;

    // 초기 윈도우 설정
    for (int i = 0; i < X; i++) {
        nowVisitor += visitors[i];
    }
    maxVisitor = nowVisitor;

    // 슬라이딩 윈도우
    for (int start = 0, end = X - 1; end < N; start++, end++) {
        if (nowVisitor > maxVisitor) {
            maxVisitor = nowVisitor;
            count = 1;
        } else if (nowVisitor == maxVisitor) {
            count++;
        }
        if (end + 1 < N) {
            nowVisitor = nowVisitor - visitors[start] + visitors[end + 1];
        }
    }

    if (maxVisitor == 0) {
        cout << "SAD" << endl;
    } else {
        cout << maxVisitor << endl << count;
    }

    return 0;
}
