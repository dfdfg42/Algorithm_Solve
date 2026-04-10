#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

typedef long long ll;

int N, M, k;
vector<pair<int,int>> cost; //비용 , 친구 번호
vector<int> parent;
vector<int> rnk;

int Find(int x) {

    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = Find(parent[x]);
    }

}

void Union(int a, int b) {

    int A = Find(a);
    int B = Find(b);

    if (A != B) {

        if (rnk[A] > rnk[B]) {

            parent[A] = B;
        }
        else if (rnk[B] < rnk[A]) {

            parent[B] = A;
        }
        else {

            parent[A] = B;
            rnk[B]++;

        }

    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> k;

    parent.resize(N + 1);
    rnk.resize(N + 1, 0);
    cost.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;
        cost[i] = { c,i };
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    sort(cost.begin(), cost.end());

    int ans = 0;
    for (auto p : cost) {

        int c = p.first;
        int now = p.second;

        if (Find(now) != Find(0)) {
            Union(0, now);
            ans += c;
        }

    }


    
    cout << (k < ans ? "Oh no" : to_string(ans)) << '\n';



    return 0;
}