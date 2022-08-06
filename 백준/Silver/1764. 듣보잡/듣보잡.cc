#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	map<string, bool> m_map;
	vector<string> vec;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		m_map.insert({ str, true });
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (m_map[str])
		{
			vec.push_back(str);
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << "\n";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}


	return 0;
}