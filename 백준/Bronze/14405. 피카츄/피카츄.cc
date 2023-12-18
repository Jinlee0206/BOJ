// BOJ-14405 : 피카츄
#include<bits/stdc++.h>
using namespace std;

string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;

	bool flag = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (i < str.size() - 1 && str.substr(i, 2) == "pi" || str.substr(i, 2) == "ka") i += 1;
		else if (i < str.size() - 2 && str.substr(i, 3) == "chu") i += 2;
		else flag = 0;
	}

	if (flag) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}