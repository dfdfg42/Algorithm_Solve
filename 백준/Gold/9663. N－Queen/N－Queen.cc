#include <iostream>
#include <vector>
using namespace std;

int N, answer = 0;
vector<int> row; 


bool isPromising(int currentRow) {
    for (int i = 0; i < currentRow; ++i) {
       
        if (row[i] == row[currentRow] || abs(row[currentRow] - row[i]) == abs(currentRow - i)) {
            return false;
        }
    }
    return true;
}


void solve(int currentRow) {
    if (currentRow == N) { 
        ++answer;
    } else {
        for (int i = 0; i < N; ++i) {
            row[currentRow] = i; 
            if (isPromising(currentRow)) { 
                solve(currentRow + 1);
            }
        }
    }
}

int main() {
    cin >> N;
    row.resize(N);
    solve(0); 
    cout << answer;
    return 0;
}
