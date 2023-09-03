#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int tc;
int n;
vector<int> p;
vector<int> check;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		p.push_back(input);
	}

	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(check.begin(), check.end(), p[i]);

		if (it == check.end())
			check.push_back(p[i]);
		else
			(*it) = p[i];
	}

	cout << check.size() << "\n";

	return 0;
}