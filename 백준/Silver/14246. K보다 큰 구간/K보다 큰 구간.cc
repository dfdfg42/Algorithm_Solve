#include<vector>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll N, M;
    vector<ll> cnt;
    cin >> N ;

    for (int i = 0; i < N; i++) {
        ll input;
        cin >> input;
        cnt.push_back(input);

    }
    cnt.push_back(0);

    cin >> M;


    ll count = 0;
    ll start = 0; ll end=0;
    ll sum = cnt[start];

    while (1) {
        //cout << "start:" << start << "end:" << end; 
        if (sum > M) {

            sum -= cnt[start];
            count += N - end;

            
            if (start == end) {
                end++;
                sum += cnt[end];
            }
            start++;

        }
        else if (sum <= M) {

            end++;
            sum += cnt[end];
            
        }
        if (end == N) break;

        //cout << "count:" << count << "\n";
    }

    cout << count;
}

