#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 100001
vector<int> tree[MAX];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

 
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);

    }


    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            if (tree[k].size() >= 2) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }

        }
        else if(t==2){
            cout << "yes\n";
        }
    }

    



    return 0;
}