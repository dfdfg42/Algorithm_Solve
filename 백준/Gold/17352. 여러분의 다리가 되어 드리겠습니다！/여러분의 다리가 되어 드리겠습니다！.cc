#include <iostream>
#include <vector>
using namespace std;
int n, m;
int parent[1000001];

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N - 2; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
       
    }
    for (int i2 = 1; i2 <= N - 1; i2++) {
        int A = i2;
        for (int j = i2 + 1; j <= N; j++) {
            int B = j;
            A = getParent(A);
            B = getParent(B);
            if (A != B) {
                cout << A << " " << B;
                return 0;
            }

        }
    }
    

    return 0;

    
}