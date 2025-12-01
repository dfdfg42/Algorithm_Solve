#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1000001; 
const int INF = 1e9;

// {날짜, 물의 양}
pair<int, ll> dp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i <= N; i++) {
        dp[i] = { INF, INF };
    }


    dp[0] = { 0, 0 };

    for (int i = 0; i < N; i++) {

        if (dp[i].first == INF) continue;

        int days = dp[i].first;
        ll water = dp[i].second;


        if (i + 1 <= N) {
            pair<int, ll> next_val = { days + 1, water + 1 };
            if (next_val < dp[i + 1]) {
                dp[i + 1] = next_val;
            }
        }

        if (i > 0 && i * 3 <= N) {
            pair<int, ll> next_val = { days + 1, water + 3 };
            if (next_val < dp[i * 3]) {
                dp[i * 3] = next_val;
            }
        }

        if (i > 1) {
            ll next_idx = (ll)i * i;
            if (next_idx <= N) {
                pair<int, ll> next_val = { days + 1, water + 5 };
                if (next_val < dp[(int)next_idx]) {
                    dp[(int)next_idx] = next_val;
                }
            }
        }
    }

    cout << dp[N].first << " " << dp[N].second << "\n";

    return 0;
}