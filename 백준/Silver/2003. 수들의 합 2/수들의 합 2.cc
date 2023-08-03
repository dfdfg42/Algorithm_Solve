#include<vector>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll N, M;
    vector<ll> cnt;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        ll input;
        cin >> input;
        cnt.push_back(input);

    }
    cnt.push_back(0); //인덱스 때문에 하나 추가



    ll count = 0;
    ll start = 0; ll end=0;
    ll sum = cnt[start];

    while (1) {

        if (sum > M) { //합이 클때

            sum -= cnt[start];

            if (start == end) {
                end++;
                sum += cnt[end];
            }
            start++;

        }
        else if (sum < M) { //합이 적을때

            end++;
            sum += cnt[end];
            
        }
        else if (sum == M) {
            count++;
            sum += cnt[++end];
        }
        if (end == N) break;

    }

    cout << count;
}

