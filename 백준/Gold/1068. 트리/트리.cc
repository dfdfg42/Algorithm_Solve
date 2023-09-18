#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> tree[51];
int check[51];
int leaf = 0;
int wither;
int root;

void findLeaf(int node ) {
    check[node] = true;
    
    if (node == wither) return;

    bool isLeaf = true;

    for (int i = 0; i < tree[node].size(); i++) {
        int nextNode = tree[node][i];
        if (check[nextNode] != true && nextNode != wither) {
            isLeaf = false;
            findLeaf(nextNode);
        }
    }

    if (isLeaf) leaf++;

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;     cin >> n;

    for(int i=0; i<n; i++){
        int input; cin >> input;
        if (input == -1) {
            root = i;
        }
        else {
            tree[input].push_back(i);
        }

    }
    cin >> wither;
    
    findLeaf(root);

    cout << leaf << "\n";


    return 0;
}