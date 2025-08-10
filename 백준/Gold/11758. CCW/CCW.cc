#include <iostream>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {

    int crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);


    if (crossProduct > 0) {
        return 1; 
    } else if (crossProduct < 0) {
        return -1; 
    } else {
        return 0; 
    }
}


int main() {

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;


    int result = ccw(x1, y1, x2, y2, x3, y3);

    if (result == 1) {
        cout << 1 << endl;
    } else if (result == -1) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}