#include <bits/stdc++.h>
using namespace std;

int n, answer;
int t[10001];
int dp[10001];
int numOfancestor[10001];
vector<int> A[10001];

int main(void) {
    queue<int> q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> t[i] >> x;
        dp[i] = t[i];
        numOfancestor[i] = x;
        if (x != 0) {
            for (int j = 0; j < x; j++) {
                int pre;
                cin >> pre;
                A[pre].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (numOfancestor[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < A[now].size(); i++) {
            int next = A[now][i];
            dp[next] = max(dp[next], dp[now] + t[next]);
            numOfancestor[next]--;
            if (numOfancestor[next] == 0)
                q.push(next);
        }
    }
    for (int i = 1; i <= n; i++)
        answer = max(answer, dp[i]);
    cout << answer;
}