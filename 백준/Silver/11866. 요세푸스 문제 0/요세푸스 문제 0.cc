#include<vector>
#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int index = 1, count = 0;
    bool flag[1001] = { 0, };
    vector<int> ans;

    while (1) {


        if (flag[index] == false) {
            
            count++;

            if (count == K) {
                ans.push_back(index);
                flag[index] = true;
                count = 0;
            }
        }

        if (ans.size() == N) {
            break;
        }

        index++;
        if (index > N) {
            index = 1;
        }

        //cout << "index:" << index << "\n";
    }

    cout << "<";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i] << ">";

        }else cout << ans[i] << ", ";


    }

}

