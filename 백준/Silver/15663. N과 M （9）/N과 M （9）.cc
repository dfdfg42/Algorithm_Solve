#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
bool visited[9];
int save[9];
int n,m;


void go(int at) {
    if (at == m) {
         
        for (int i = 0; i < m; i++) {
            cout << save[i] << " ";
        }
        cout << "\n";
        return;
    }

    int last = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false && arr[i] != last) {
            
            save[at] = arr[i];
            last = save[at];
            visited[i] = true;
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