#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> vec;
vector<int> res;
int ch[8] = { false };
set<vector<int>> s;

void EliminateRedundancy()
{
	s.insert(res);
	return;
}

void DFS(int lv, int idx)
{
	if (lv == m)
	{
		EliminateRedundancy();
		return;
	}
	else
	{
		for (int i = idx; i < vec.size(); i++)
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

	for (auto vector : s) {
		for (auto temp : vector)
		{
			cout << temp << " ";
		}
		cout << "\n";
	}

	return 0;
}