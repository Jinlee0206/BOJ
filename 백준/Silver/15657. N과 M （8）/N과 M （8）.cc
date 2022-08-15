#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> vec;
vector<int> res;

void Print()
{
	for (int i = 0; i < m; i++)
	{
		cout << res[i] << " ";
	}
	cout << "\n";
	return;
}

void DFS(int lv, int idx)
{
	if (lv == m)
	{
		Print();
		return;
	}
	else
	{
		for (int i = idx; i < n; i++)
		{
			res.push_back(vec[i]);
			DFS(lv + 1, i);
			res.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	DFS(0, 0);

	return 0;
}