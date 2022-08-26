#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> poketmon;
	vector <string> poketmon_num(n+1);

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		poketmon[str] = i;
		poketmon_num[i] = str;
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		int n;
		cin >> str;

		if (isdigit(str[0]))
		{
			n = stoi(str);
			cout << poketmon_num[n] << "\n";
		}
		else cout << poketmon[str] << "\n";
	}


	return 0;
}