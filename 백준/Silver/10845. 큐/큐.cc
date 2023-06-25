#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    queue<int> cnt;

    while (n--) {
        string input;
        cin >> input;

        if (input == "push") {
            int input2;
            cin >> input2;
            cnt.push(input2);

        }
        if (input == "pop") {
            if (!cnt.empty()) {
                cout << cnt.front() << "\n";
                cnt.pop();

            }
            else {
                cout << -1 << "\n";
            }

        }
        else if(input == "size"){
            cout << cnt.size()<<"\n";
        }
        else if (input == "empty") {
            if (cnt.empty()) {
                cout << 1 <<"\n";
            }
            else {
                cout << 0<<"\n";
            }

        }
        else if (input == "front") {
            if (!cnt.empty()) {
                cout << cnt.front() <<"\n";
            }
            else {
                cout << -1<<"\n";
            }
        }
        else if (input == "back") {
            if (!cnt.empty()) {
                cout << cnt.back()<<"\n";
            }
            else {
                cout << -1 <<"\n";
            }

        }


    }

    return 0;
}