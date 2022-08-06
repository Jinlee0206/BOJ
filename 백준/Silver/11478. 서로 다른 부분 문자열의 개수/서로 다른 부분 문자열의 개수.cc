#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string S;
	cin >> S;

	//set<string> _set;
	map<string, bool> list;

	string str;
	for (int i = 0; i < S.size(); i++)
	{
		str = "";
		for (int j = i; j < S.size(); j++)
		{
			str += S[j];
			//_set.insert(str);
			if (!list[str]) list.insert({ str, true });
		}
	}

	//cout << _set.size() << "\n";
	cout << list.size() << "\n";

	return 0;
}