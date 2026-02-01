#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;

struct node {
    int small;
    int big;

};

vector<node> vec;
vector<int> bigVec;
vector<int> smlVec;

int findR(int target) {
    int l = 0, r = N;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (smlVec[mid] <= target) {
            l = mid + 1; 
        }
        else {
            r = mid;
        }
    }
    return l;
}

int findL(int target) {

    int l = 0, r = N;
    int ans = -1;
    while (l < r) {
        int mid = (l + r) / 2;

        if (bigVec[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        vec.push_back({a - b,a+b });
        smlVec.push_back(a-b);
        bigVec.push_back(a+b);
    }

    sort(smlVec.begin(), smlVec.end());
    sort(bigVec.begin(), bigVec.end());


    for (int i = 0; i < N; i++) {

      
        // 가장 높은 인덱스 찾기
        int R = findR(vec[i].big); 
        
        //가장 작은 인덱스 찾기
        int L = findL(vec[i].small);

        cout << L + 1 << ' ' << R  << '\n';
        
    }


    return 0;
}