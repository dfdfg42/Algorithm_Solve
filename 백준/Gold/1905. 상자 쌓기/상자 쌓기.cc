#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

typedef unsigned long long ll;
typedef long double ld;

int Lx, Ly, N;

int top; //가장 높은곳

//각 모서리의 좌표를 저장
struct box {

    //왼쪽아래 , 우측아래 , 왼쪽위 ,우측 위
    int x0, y0, x1, y1, x2, y2, x3, y3;
    int z0, z1;// 맨아래블럭 z 맨위에블럭 z

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> Lx >> Ly >> N;

    top = 0;
    vector<box> boxes;
    //각 박스의 좌표에서 겹치는 박스가 있는지 확인하고
    //겹치면 가장 높은 박스위에 둔다
    for (int i = 0; i < N; i++) {
        int lx, ly, lz, px, py;
        cin >> lx >> ly >> lz >> px >> py;

        box tempBox = { px,py,px + lx,py,px,py + ly,px + lx,py + ly,0,0 };
        int tempZ = 0;
        for (auto& b : boxes) {
            if (!(px + lx <= b.x0 || b.x1 <= px ||
                py + ly <= b.y0 || b.y3 <= py)) {
                tempZ = max(tempZ, b.z1);
            }
        }
        tempBox.z1 = tempZ + lz;
        tempBox.z0 = tempZ;
        top = max(top, tempBox.z1);
        boxes.push_back(tempBox);
    }

    cout << top << '\n';

    return 0;
}