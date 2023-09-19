#include <iostream>
#include <algorithm>

using namespace std;

int arr[8];
bool visited[8];
int save[8];
int n,m;

void go(int at) {
    if (at == m) {
        for (int i = 0; i < m; i++) {
            cout << save[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            save[at] = arr[i];
            go(at + 1);
            visited[i] = false;
        }


    }
}

int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    go(0);

    return 0;
}