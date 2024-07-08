#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    cout << fixed << setprecision(8);
    
    for (int i = 0; i < T; ++i) {
        int coordType;
        cin >> coordType;
        
        double a, b;
        cin >> a >> b;
        
        if (coordType == 1) {
            // 직교좌표계 (x, y) -> 극좌표계 (r, θ)
            double x = a;
            double y = b;
            double r = sqrt(x * x + y * y);
            double theta = atan2(y, x);
            if (theta < 0) {
                theta += 2 * M_PI;
            }
            cout << r << " " << theta << endl;
        } else if (coordType == 2) {
            // 극좌표계 (r, θ) -> 직교좌표계 (x, y)
            double r = a;
            double theta = b;
            double x = r * cos(theta);
            double y = r * sin(theta);
            cout << x << " " << y << endl;
        }
    }
    
    return 0;
}
