#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <string>
#include <iomanip> 
#include <queue>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    queue<pair<string,long long>> q;

    q.push({ a,1 });

    int ansC = -1;
    while(!q.empty()) {
        string now = q.front().first;

        int c = q.front().second;
        //cout << "now: " << now << " c: " << c << '\n';
        q.pop();

        if (now.length() > b.length()) {
            continue;
        }
        else if(now.length() == b.length()) {
            if (now == b) {
                ansC = c;
                break;
            }
        }
        else if (now.length() > b.length()) {
            continue;
        }


        q.push({ to_string(stol(now) * 2),c + 1 });

        q.push({ now + "1", c + 1 });

    }

    cout << ansC << '\n';

}
