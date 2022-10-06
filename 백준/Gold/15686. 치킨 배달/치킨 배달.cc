#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 2147000000;
int m_map[55][55];

vector<pair<int, int>> _home, _chicken;
vector<vector<int>> chickenList;

void combi(int start, vector<int> v)
{
	if (v.size() == m)
	{
		chickenList.push_back(v);
		return;
	}

	for (int i = start + 1; i < _chicken.size(); i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m_map[i][j];
			if (m_map[i][j] == 1) _home.push_back({ i,j });
			if (m_map[i][j] == 2) _chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	combi(-1, v);

	for (vector<int> cList : chickenList)
	{
		int res = 0;
		for (pair<int, int> home : _home)
		{
			int m_min = 2147000000;
			for (int ch : cList)
			{
				int dist = abs(home.first - _chicken[ch].first) + abs(home.second - _chicken[ch].second);
				m_min = min(m_min, dist);
			}
			res += m_min;
		}
		ans = min(ans, res);
	}

	cout << ans << "\n";

	return 0;

}