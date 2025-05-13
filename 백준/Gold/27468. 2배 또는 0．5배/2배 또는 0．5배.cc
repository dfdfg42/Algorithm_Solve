#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    cout << "YES" << "\n";

    if (N % 4 == 2){
        for (int i=0; i<N; i++){
            if (i % 4 == 0) cout << (i + 2);
            if (i % 4 == 1) cout << i;
            if (i % 4 == 2) cout << (i + 1);
            if (i % 4 == 3) cout << (i + 1);
            cout << " ";
        }
    }
    else {
        for (int i=0; i<N; i++){
            if (i % 4 == 0) cout << (i + 1);
            if (i % 4 == 1) cout << (i + 2);
            if (i % 4 == 2) cout << i;
            if (i % 4 == 3) cout << (i + 1);
            cout << " ";
        }
    }
    
    return 0;
}