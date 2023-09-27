#include<iostream>
#include<algorithm>
using namespace std;

bool check[9];
int num[9], ans[9];
int N, M;

void dfs(int x, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	int tmp= -1;
	for (int i = x; i < N; i++)
	{
		if (!check[i] && tmp != num[i])
		{
			tmp = num[i];
			ans[cnt] = num[i];
			check[i] = true;
			dfs(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N); // 오름차순 정렬

	dfs(0, 0);
}