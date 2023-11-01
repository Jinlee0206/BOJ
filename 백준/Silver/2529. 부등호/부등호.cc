// BOJ-2529 : 부등호
#include<bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int n, max_n = -INF, min_n = INF, visited[10];
char op[10];
vector<string> v;

bool isGood(char x, char y, char oper)
{
	if (x < y && oper == '<') return true;
	else if (x > y && oper == '>') return true;
	else return false;
}

void dfs(int idx, string num)
{
	if (idx == n + 1)
	{
		v.push_back(num);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i]) continue; // 숫자 재사용 불가
		if (idx == 0 || isGood(num[idx - 1], i + '0', op[idx - 1]))
		{
			visited[i] = 1;
			dfs(idx + 1, num + to_string(i));
			visited[i] = 0;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> op[i];
	}

	dfs(0, "");

	sort(v.begin(), v.end());
	cout << v[v.size() - 1] << '\n' << v[0] << '\n';

	return 0;
}