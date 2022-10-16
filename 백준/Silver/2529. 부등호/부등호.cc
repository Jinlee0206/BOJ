#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n;
bool visited[10];
vector<char> vec;
vector<string> res;

bool isGood(char x, char y, char op)
{
	if (x < y && op == '<') return true;
	if (x > y && op == '>') return true;
	return false;
}

void dfs(int idx, string num)
{
	if (idx == n + 1)
	{
		res.push_back(num);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i]) continue;
		if (idx == 0 || isGood(num[idx - 1], i + '0', vec[idx - 1]))
		{
			visited[i] = true;
			dfs(idx + 1, num + to_string(i));
			visited[i] = false;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		vec.push_back(a);
	}

	dfs(0, "");
	sort(res.begin(), res.end());
	cout << res[res.size() - 1] << "\n" << res[0] << "\n";

	return 0;
}