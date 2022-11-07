#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, s[21], a;

void add(int a)
{
	if(s[a] != 1) s[a] = 1;
	else return;
}

void remove(int a)
{
	if (s[a] != 0) s[a] = 0;
	else return;
}

void check(int a)
{
	cout << s[a] << "\n";
	return;
}

void toggle(int a)
{
	if (s[a] != 0) s[a] = 0;
	else s[a] = 1;
	return;
}

void all()
{
	fill(s, s + 21, 1);
}

void empty()
{
	fill(s, s + 21, 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		if (str == "add")
		{
			cin >> a;
			add(a);
		}
		else if (str == "remove")
		{
			cin >> a;
			remove(a);
		}
		else if (str == "check")
		{
			cin >> a;
			check(a);
		}
		else if (str == "toggle")
		{
			cin >> a;
			toggle(a);
		}
		else if (str == "all")
		{
			all();
		}
		else if (str == "empty")
		{
			empty();
		}
	}

	return 0;
}