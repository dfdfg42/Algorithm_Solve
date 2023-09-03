#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int tc;
int n;
vector<int> p;
vector<int> check;
vector<int>::iterator it;

void Pre()
{
	p.clear();
	check.clear();
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (cin >> n)
	{
		Pre();

		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;

			p.push_back(input);
		}

		for (int i = 0; i < n; i++)
		{
			it = lower_bound(check.begin(), check.end(), p[i]);

			if (it == check.end())
				check.push_back(p[i]);
			else
				(*it) = p[i];
		}

		cout << check.size() << "\n";
	}

	return 0;
}