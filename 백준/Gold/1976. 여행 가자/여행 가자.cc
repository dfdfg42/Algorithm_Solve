#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int parent[1'000'001];


int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;

}

bool isUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;

    memset(parent, 0, sizeof(parent));
    for (int i = 0; i <= 1'000'000; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                merge(i, j);
            }
        }
    }

    int root;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (i == 0) root = find(x);
        else {
            if (find(root) != find(x)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;


    return 0;
}
