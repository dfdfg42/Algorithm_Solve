#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
const int MAX_N = 256;

int N, M;
int dist[MAX_N + 1][MAX_N + 1];

void floydWarshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] && dist[k][j]) {
                    dist[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    // 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 1;
            } else {
                dist[i][j] = 0;
            }
        }
    }

    // 입력 받은 간선 정보 설정
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        dist[A][B] = 1;
    }

    // 플로이드-워셜 알고리즘 실행
    floydWarshall();

    // 각 학생이 설 수 있는 위치 범위 계산
    for (int i = 1; i <= N; i++) {
        int minPos = 1;
        int maxPos = N;

        for (int j = 1; j <= N; j++) {
            if (i != j) {
                if (dist[j][i]) {
                    minPos++;
                }
                if (dist[i][j]) {
                    maxPos--;
                }
            }
        }

        if (minPos > maxPos) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        int minPos = 1;
        int maxPos = N;

        for (int j = 1; j <= N; j++) {
            if (i != j) {
                if (dist[j][i]) {
                    minPos++;
                }
                if (dist[i][j]) {
                    maxPos--;
                }
            }
        }

        cout << minPos << " " << maxPos << endl;
    }

    return 0;
}
