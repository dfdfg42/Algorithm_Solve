#include<iostream>
using namespace std;
int N, X, P, mxP, tolerance = 1;
long long sum;	// 상금합 정수범위 넘음
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for (int i = 0; i < N; i++) {
		cin >> X >> P;
		if (sum <= X) {	// 1. Sum 이 X 제한보다 작을 때
			sum += P;
			mxP = P > mxP ? P : mxP;
		}
		else if (sum - mxP > X || mxP < P) {	// 2. 제한에 걸릴 때 뛰어넘기
			tolerance--;
		}
		else {	// 3.제한에 걸릴 때 상금 뱉기
			tolerance--;
			sum -= mxP;
			sum += P;
		}
		if (tolerance < 0) {
			cout << "Zzz"; return 0;
		}
	}
	cout << "Kkeo-eok";
	return 0;
}