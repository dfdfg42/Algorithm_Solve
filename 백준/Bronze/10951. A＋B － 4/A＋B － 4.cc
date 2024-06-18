#include <iostream>
#include <vector>

using namespace std;

bool visited[10];


int main() {

    while (1) {
        int a, b;
        cin >> a >> b;

        if (cin.eof()) {
            break;
        }
        
        cout << a+b <<'\n';
    }

    
    return 0;
}