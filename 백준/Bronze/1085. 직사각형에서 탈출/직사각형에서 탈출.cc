#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> vec;

	for (int i = 0; i < 2; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back({ a, b });
	}

	int m_min = 2147000000;

	if (vec[1].first - vec[0].first < m_min) m_min = vec[1].first - vec[0].first;
	if (vec[0].first - 0 < m_min) m_min = vec[0].first - 0;
	if (vec[1].second - vec[0].second < m_min) m_min = vec[1].second - vec[0].second;
	if (vec[0].second - 0 < m_min) m_min = vec[0].second - 0;

	cout << m_min << "\n";

	return 0;
}