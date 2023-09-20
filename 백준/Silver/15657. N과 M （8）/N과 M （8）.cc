#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
bool visited[9];
int save[9];
int n,m;


void go(int at, int depth) {
    if (depth == m) {
         
        for (int i = 0; i < m; i++) {
            cout << save[i] << " ";
        }
        cout << "\n";
        return;
    }


    for (int i = at; i < n; i++) {
        save[depth] = arr[i];

        go(i, depth + 1);
       
    }
}

int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    go(0, 0);

    return 0;
}