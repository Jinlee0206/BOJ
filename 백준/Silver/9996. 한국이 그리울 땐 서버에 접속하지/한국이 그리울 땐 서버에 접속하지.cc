// BOJ - 9996 : 한국이 그리울 땐 서버에 접속하지
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string pw, prefix, suffix;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> pw;

	int pos = pw.find('*');
	prefix = pw.substr(0, pos);
	suffix = pw.substr(pos + 1);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (prefix.size() + suffix.size() > str.size())
		{
			cout << "NE\n";
			continue;
		}
		if (prefix == str.substr(0, prefix.size()) && suffix == str.substr(str.size() - suffix.size()))
		{
			cout << "DA\n";
		}
		else cout << "NE\n";
	}

	return 0;
}