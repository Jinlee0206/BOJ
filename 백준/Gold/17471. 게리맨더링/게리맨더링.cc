// BOJ-17471 : 게리멘더링
#include<bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int n, m, res = INF;
int population[11], comp[11], visited[11];

vector<int> adj[11];

pair<int, int> dfs(int here, int value)
{
	visited[here] = 1;
	pair<int, int> res = { 1, population[here] }; 
	for (int there : adj[here])
	{
		if (comp[there] != value) continue;
		if (visited[there]) continue;
		pair<int, int> _tmp = dfs(there, value);
		res.first += _tmp.first;
		res.second += _tmp.second;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> population[i];

	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int tmp;
			cin >> tmp;
			adj[tmp].push_back(i);
			adj[i].push_back(tmp);
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++)
	{
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);

		int idx1 = -1, idx2 = -1;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else idx2 = j + 1;
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);

		if (comp1.first + comp2.first == n) res = min(res, abs(comp1.second - comp2.second));
	}

	cout << (res == INF ? -1 : res) << '\n';

	return 0;
}