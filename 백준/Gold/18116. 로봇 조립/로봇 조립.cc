#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int parent[1'000'001];
int robots[1'000'001];

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
    robots[x] += robots[y];
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

    memset(parent, 0, sizeof(parent));
    for (int i = 0; i <= 1'000'000; i++) {
        parent[i] = i;
        robots[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        char q;
        cin >> q;
        if (q == 'I') {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        if (q == 'Q') {
            int c;
            cin >> c;
            cout << robots[find(c)] << '\n';
        }

    }

    return 0;
}
