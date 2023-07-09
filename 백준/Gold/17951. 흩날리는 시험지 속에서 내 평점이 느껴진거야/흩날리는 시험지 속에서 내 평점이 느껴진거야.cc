#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, K; cin >> N  >> K;
	int arr[100000], s=0;
	for(int i=0;i<N;i++){
		cin >> arr[i];
		s += arr[i];
	}
	
	int pl = 0;
	int pr = s;
	while(pl <= pr){
		int mid = (pl + pr) / 2;
		int sum = 0, cnt = 0;
		for(int k=0;k<N;k++){
			sum += arr[k];
			if(sum >= mid){
				cnt++;
				sum = 0;
			}
		}
		
		if(cnt >= K){
			pl = mid + 1;
		}
		else pr = mid - 1;
	}
	
	cout << pr;
	return 0;
}