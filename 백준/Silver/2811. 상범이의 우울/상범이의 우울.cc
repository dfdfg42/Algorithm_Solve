#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <tuple>
using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

	vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

	vector<pair<int, int>> point; //스택 , 인덱스

    int f = 0;
    int maxLen = 0;
    int ans = 0;
    int stack = 0;
    vector<bool> fCheck(n + 1, false);
    for (int i = n - 1; i >= 0; i--) {


        if(vec[i] <0) {
            stack++;
        }
        else {
            if (stack > 0) {
                maxLen = max(maxLen, stack);
                
                point.push_back({ stack, i });
                stack = 0;
            }
        }
    }
    if (stack > 0) {
        maxLen = max(maxLen, stack);
        point.push_back({ stack, -1 });
    }
    for (auto a : point) {
		int len = a.first * 2;
		int index = a.second;

		while (len > 0 && index >= 0) {
            if (fCheck[index] == false) {
                fCheck[index] = true;
                ans++;
            }
            len--;
			index--;
		}
    }

    int more = 0;
    for (auto a : point) {
		if (a.first == maxLen) {
            int temp = 0;
			int index = a.second;
            int len = maxLen * 3;
			
            while (len > 0 && index >= 0) {
                if (fCheck[index] == false) {
                    temp++;
                }
                len--;
                index--;
            }
			more = max(more, temp);
		}
    }
    

    cout << ans  + more<< '\n';
    return 0;
}
