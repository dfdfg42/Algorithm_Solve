#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrN[1000000] = { 0, };

int search(int left, int right, int find) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (find == arrN[mid]) {
            return 1;
        }
        else if (find > arrN[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 0;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arrN[i];
    }
    sort(arrN, arrN + n);

    int m; 
    cin >> m;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        if (search(0,n-1,input) == 1) {
            cout << "1" << "\n";
        }
        else {
            cout << "0" << "\n";
        }
    }

    
    return 0;
}