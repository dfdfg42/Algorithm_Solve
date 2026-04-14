#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;


int N;

deque<int> deck;
vector<int> cmd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    cmd.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cmd[i];
    }
    int now = 1;
    for (int i = N-1; i >=0; i--) {
        int c = cmd[i];

        if (c == 1) {
            deck.push_front(now++);
        }
        else if (c == 2) {

            int temp = deck.front();
            deck.pop_front();

            deck.push_front(now++);
            deck.push_front(temp);

        }
        else if (c == 3) {

            deck.push_back(now++);

        }
    }

    for (auto a : deck) {
        cout << a << ' ';
    }


    return 0;
}