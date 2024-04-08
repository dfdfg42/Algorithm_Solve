#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> tmp;
long long saveCount = 0; // 저장 횟수를 카운트할 변수의 이름을 saveCount로 변경
int K;
int answer = -1; // K 번째 저장되는 수, 기본값은 -1

void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, t = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        }
        else {
            tmp[t++] = arr[j++];
        }
        saveCount++; // 저장 횟수 증가
        if (saveCount == K) answer = tmp[t - 1]; // K 번째 저장되는 순간 값을 갱신
    }

    while (i <= mid) {
        tmp[t++] = arr[i++];
        saveCount++; // 저장 횟수 증가
        if (saveCount == K) answer = tmp[t - 1];
    }

    while (j <= right) {
        tmp[t++] = arr[j++];
        saveCount++; // 저장 횟수 증가
        if (saveCount == K) answer = tmp[t - 1];
    }

    for (int k = left; k <= right; k++) {
        arr[k] = tmp[k];
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    int N;
    cin >> N >> K;
    arr.resize(N);
    tmp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    mergeSort(0, N - 1);

    cout << answer << endl; // K 번째 저장되는 수 출력, K보다 저장 횟수가 작으면 -1 출력
    return 0;
}
