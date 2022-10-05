#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m, ans = 2147000000;

int m_map[55][55];

vector<vector<int>> chickenList;
vector<pair<int, int>> _home, _chicken;

// 재귀함수로 조합 
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

void setMap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m_map[i][j];
			if(m_map[i][j] == 1) _home.push_back({ i,j });
			if(m_map[i][j] == 2) _chicken.push_back({ i,j });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	setMap();

	vector<int> v;
	combi(-1, v);

	for (vector<int> cList : chickenList)
	{
		int res = 0;
		for (pair<int, int> home : _home)
		{
			int _min = 2147000000;
			for (int ch : cList)
			{	
				// 집 하나 기준 가장 짧은 거리의 치킨 거리
				int _dist = abs(home.first - _chicken[ch].first) + abs(home.second - _chicken[ch].second);
				_min = min(_min, _dist);
			}
			// 도시의 치킨 거리 - 모든 집의 치킨 거리의 합
			res += _min;
		}

		// 가장 작은 도시의 치킨 거리
		ans = min(ans, res);
	}

	cout << ans << "\n";

	return 0;
}