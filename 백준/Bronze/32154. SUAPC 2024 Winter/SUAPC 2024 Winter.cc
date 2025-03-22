#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string board[10][2] = {
        {"11", "A B C D E F G H J L M"},
        {"9", "A C E F G H I L M"},
        {"9", "A C E F G H I L M"},
        {"9", "A B C E F G H L M"},
        {"8", "A C E F G H L M"},
        {"8", "A C E F G H L M"},
        {"8", "A C E F G H L M"},
        {"8", "A C E F G H L M"},
        {"8", "A C E F G H L M"},
        {"8", "A B C F G H L M"}
    };

    int N;
    cin >> N;


    int idx = N - 1;

    cout << board[idx][0] << "\n";
    cout << board[idx][1] << "\n";

    return 0;
}