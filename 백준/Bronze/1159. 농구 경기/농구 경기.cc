#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int alpabet[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		int a = str[0] - 97;
		alpabet[a]++;
	}

	vector<char> res;
	for (int i = 0; i < 26; i++)
	{
		if (alpabet[i] >= 5) res.push_back(char(i + 97));
	}

	if (!res.empty())
	{
		for (auto i : res) cout << i;
	}
	else cout << "PREDAJA" << "\n";

	return 0;
}