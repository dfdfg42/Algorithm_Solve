#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[10001] = { 0, };
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        arr[input]++;
        
    }

    for (int i = 1; i <= 10000; i++) {
        if (arr[i] != 0) {
            for (int j = 1; j <= arr[i]; j++) {
                cout << i << "\n";
            }
        }
    }
}

