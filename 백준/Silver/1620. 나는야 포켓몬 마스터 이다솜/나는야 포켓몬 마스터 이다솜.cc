#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> mapset;
	vector<string> name;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		name.push_back(str);
		mapset.insert({str, i});
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		int n;
		cin >> str;

		if (isdigit(str[0]))
		{
			n = stoi(str) - 1;
			cout << name[n] << "\n";
		}
		else
		{
			cout << mapset[str] << "\n";
		}
	}

	return 0;
}