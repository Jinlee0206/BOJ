#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, bool> m_map;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cnt = 0;
	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		m_map[str] = true;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (m_map[str]) cnt++;
	}

	cout << cnt << "\n";

	/*for (auto iter = m_map.begin(); iter != m_map.end(); iter++)
	{
		cout << iter->first << " " << iter->second << "\n";
	}
	cout << endl;*/

	return 0;
}