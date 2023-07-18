#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int map[101][101];
int direction = 0; //남(0),서(1),북(2),동(3) 
int N, R, C;
int R_min, R_max, C_min, C_max;
string s;

int main()
{
	cin >> N;
	cin >> s;

	R = C = 50;
	map[R][C] = 1;
	R_min = 50;
	C_min = 50;
	R_max = 50;
	C_max = 50;
	
	for (int i = 0; i < N; i++)
	{
		
		// L,R,F 명령 처리
		if (s[i] == 'L') direction--;
		else if (s[i] == 'R') direction++;
		else if (s[i] == 'F')
		{
			if (direction == 0) R++;
			else if (direction == 1) C--;
			else if (direction == 2) R--;
			else if (direction == 3) C++;
			map[R][C] = 1;
		}

		if (direction < 0) direction += 4;
		else if (direction >= 4) direction -= 4;

		R_min = min(R_min, R);
		C_min = min(C_min, C);
		R_max = max(R_max, R);
		C_max = max(C_max, C);
	}

	for (int i = R_min; i <= R_max; i++)
	{
		for (int j = C_min; j <= C_max; j++)
		{
			cout << (map[i][j]?'.':'#');
		}
		cout << '\n';
	}
}