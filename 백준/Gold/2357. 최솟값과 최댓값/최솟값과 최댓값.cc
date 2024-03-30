#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
#include <climits>
using namespace std;

vector<int> arr;
vector<int> treeMin; 
vector<int> treeMax;


// 세그먼트 트리 초기화 함수
int initMin(int start, int end, int index) {
    if (start == end) {
        treeMin[index] = arr[start];
        return treeMin[index];
    }
    int mid = (start + end) / 2;

    treeMin[index] = min( initMin(start, mid, index * 2) , initMin(mid + 1, end, index * 2 + 1));
    return treeMin[index];
}

int findMin(int start, int end, int index, int left, int right) {

    if (left > end || right < start) {
        return INT_MAX;
    }

    if (left <= start && end <= right) {
        return treeMin[index];
    }

    int mid = (start + end) / 2;

    return min(findMin(start, mid, index * 2, left, right) , findMin(mid + 1, end, index * 2 + 1, left, right));
}

int initMax(int start, int end, int index) {
    if (start == end) {
        treeMax[index] = arr[start];
        return treeMax[index];
    }
    int mid = (start + end) / 2;

    treeMax[index] = max(initMax(start, mid, index * 2), initMax(mid + 1, end, index * 2 + 1));
    return treeMax[index];
}

int findMax(int start, int end, int index, int left, int right) {

    if (left > end || right < start) {
        return INT_MIN;
    }

    if (left <= start && end <= right) {
        return treeMax[index];
    }

    int mid = (start + end) / 2;

    return max(findMax(start, mid, index * 2, left, right), findMax(mid + 1, end, index * 2 + 1, left, right));
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N ,M;
    cin >> N;
    cin >> M;
    arr.resize(N+1);
    treeMin.resize(4 * N); 
    treeMax.resize(4 * N);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    initMin(1, N, 1); 
    initMax(1, N, 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << findMin(1, N, 1, a, b) << " " << findMax(1, N, 1, a, b) << "\n";
    }

  

    return 0;
}
