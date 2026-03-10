#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int board[500][500];

int blocks[19][4][2] = {

	{{0,0}, {0,1}, {0,2}, {0,3}}, {{0,0}, {1,0}, {2,0}, {3,0}},

	{{0,0}, {0,1}, {1,0}, {1,1}},

	{{0,0}, {1,0}, {2,0}, {2,1}}, {{0,0}, {0,1}, {0,2}, {1,0}},
	{{0,0}, {0,1}, {1,1}, {2,1}}, {{0,0}, {1,0}, {1,-1}, {1,-2}},
	{{0,0}, {1,0}, {2,0}, {2,-1}}, {{0,0}, {0,1}, {0,2}, {1,2}},
	{{0,0}, {0,1}, {1,0}, {2,0}}, {{0,0}, {1,0}, {1,1}, {1,2}},

	{{0,0}, {1,0}, {1,1}, {2,1}}, {{0,0}, {0,1}, {-1,1}, {-1,2}},
	{{0,0}, {1,0}, {1,-1}, {2,-1}}, {{0,0}, {0,1}, {1,1}, {1,2}},

	{{0,0}, {0,1}, {0,2}, {1,1}}, {{0,0}, {1,0}, {2,0}, {1,1}},
	{{0,0}, {0,1}, {0,2}, {-1,1}}, {{0,0}, {1,0}, {2,0}, {1,-1}}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int maxSum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				int currentSum = 0;
				bool isPossible = true;

				for (int dir = 0; dir < 4; dir++) {
					int ny = i + blocks[k][dir][0];
					int nx = j + blocks[k][dir][1];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
						isPossible = false;
						break;
					}
					currentSum += board[ny][nx];
				}

				if (isPossible) {
					maxSum = max(maxSum, currentSum);
				}
			}
		}
	}

	cout << maxSum << endl;

	return 0;
}