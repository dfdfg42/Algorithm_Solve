#include <iostream>
#include <vector>
#include <cmath> // abs()를 위해 포함

using namespace std;

int N, L;


bool is_passable(const vector<int>& line) {
    vector<bool> slope(N, false); 

    for (int i = 0; i < N - 1; ++i) {
        int diff = line[i] - line[i + 1];

        if (abs(diff) > 1) { 
            return false;
        }

        if (diff == 0) { 
            continue;
        }

        if (diff == 1) {         
            for (int j = 1; j <= L; ++j) {             
                if (i + j >= N || line[i + 1] != line[i + j] || slope[i + j]) {
                    return false;
                }
            }   
            for (int j = 1; j <= L; ++j) {
                slope[i + j] = true;
            }
        }
        else if (diff == -1) { 
            for (int j = 0; j < L; ++j) {
                if (i - j < 0 || line[i] != line[i - j] || slope[i - j]) {
                    return false;
                }
            }
            for (int j = 0; j < L; ++j) {
                slope[i - j] = true;
            }
        }
    }
    return true; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    int passable_roads = 0;

    for (int i = 0; i < N; ++i) {
        if (is_passable(board[i])) {
            passable_roads++;
        }
    }


    for (int j = 0; j < N; ++j) {
        vector<int> col_line;

        for (int i = 0; i < N; ++i) {
            col_line.push_back(board[i][j]);
        }
        if (is_passable(col_line)) {
            passable_roads++;
        }
    }

    cout << passable_roads << '\n';

    return 0;
}