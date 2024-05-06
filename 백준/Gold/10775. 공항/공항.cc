#include <iostream>

using namespace std;

int parent[100001];  

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    a = find(a); b = find(b);

    if (a > b) {
        swap(a, b);
    }

    parent[b] = a;


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int G, P;
    cin >> G >> P;

    for (int i = 1; i <= G; i++) {
        parent[i] = i;
    }

    int count = 0;
    for (int i = 0; i < P; i++) {
        int gi;
        cin >> gi;
        int availableGate = find(gi);
        if (availableGate == 0) {
            break;
        }
        uni(availableGate, availableGate - 1);
        count++;
    }

    cout << count << '\n';

    return 0;
}
