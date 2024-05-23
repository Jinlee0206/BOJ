// BOJ - 2870 :	수학숙제
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

void go(string& tmp)
{
	while (true)
	{
		if (tmp.size() && tmp.front() == '0') tmp.erase(tmp.begin());
		else break;
	}
	if (tmp.size() == 0) tmp = "0";
	v.push_back(tmp);
	tmp = "";
	return;
}

bool cmp(string a, string b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		string tmp = "";
		for (int j = 0; j < str.size(); j++)
		{
			if(isdigit(str[j])) tmp += str[j];
			else if(tmp.size()) go(tmp);
		}
		if (tmp.size()) go(tmp);
	}
	sort(v.begin(), v.end(), cmp);

	for (auto i : v) cout << i << '\n';

	return 0;
}