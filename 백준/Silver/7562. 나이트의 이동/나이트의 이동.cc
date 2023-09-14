#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 2, 1, -1, -2, -2 ,-1,1,2, };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

struct point {
	int x, y;
};

int main() {


	int N; cin >> N;
	while (N--) {
		int I;
		cin >> I;
		point now, target;
		cin >> now.x >> now.y >> target.x >> target.y;

		if (now.x == target.x && now.y == target.y) {
			cout << '0' << endl;
			continue;
		}

		int chessBoard[300][300] = { 0, };

		queue<point> q;
		q.push(now);
		chessBoard[q.front().x][q.front().y] = 0;

		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < I && 0 <= ny && ny < I) {
					if (chessBoard[nx][ny] == 0) {
						q.push({ nx,ny });
						chessBoard[nx][ny] = chessBoard[x][y] + 1;
					}
				}

			}
		}

		cout << chessBoard[target.x][target.y]<< endl;

		
	}






	return 0;
}