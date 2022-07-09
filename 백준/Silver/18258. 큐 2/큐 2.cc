#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int a;
			cin >> a;
			q.push(a);
		}
		else if (str == "front")
		{
			if (!q.empty())	cout << q.front() << "\n";
			else cout << "-1" << "\n";
		}
		else if (str == "back")
		{
			if (!q.empty()) cout << q.back() << "\n";
			else cout << "-1" << "\n";
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			if (q.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (str == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << "-1" << "\n";
		}
	}

	
	return 0;
}