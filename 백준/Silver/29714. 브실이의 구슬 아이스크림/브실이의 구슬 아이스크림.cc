#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//색깔 , 개수

int main() {
   
    int n;
    cin >> n;

    map<int,int> marble;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        marble[input]++;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {

        int a;
        cin >> a;
        vector<int> arr;
        bool flag = true;
        for (int j = 0; j < a; j++) {
            int input; cin >> input;
            marble[input]--;
            arr.push_back(input);
        }

        int b; cin >> b;
        vector<int> arr2;

        for (int t = 0; t < b; t++) {
            int input; cin >> input;
            arr2.push_back(input);
        }

        for (auto v : arr) {
            if (marble[v] < 0) {
                flag = false;
            }
        }

        if (flag) { //Ai 가 다 있으면 B 넣기
            for (auto a2 : arr2) {
                marble[a2]++;
            }
        }
        else { //없으면 다시 지운거 더해주기
            for (auto v : arr) {
                marble[v]++;
            }
        }
       

    }


    // M을 계산
    long long M = 0;
    for (auto p : marble) {
        M += p.second;
    }

    cout << M << '\n';

    // M이 0이 아닐 때만 구슬 출력
    if (M > 0) {
        bool first = true;
        for (auto p : marble) {
            for (int i = 0; i < p.second; i++) {
                if (!first) cout << ' ';
                cout << p.first;
                first = false;
            }
        }
    }

    return 0;
} 