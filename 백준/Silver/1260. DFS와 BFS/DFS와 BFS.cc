#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
int map[1001][1001];
bool visited[1001];
queue<int> q;

void clr()
{
	fill(visited, visited + 1001, false);
	return;
}

void bfs(int v)
{
	q.push(v);
	visited[v] = true;

	while (q.size())
	{
		int tmp = q.front();
		q.pop();

		cout << tmp << " ";

		for (int i = 1; i <= n; i++)
		{
			if (map[tmp][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}

void dfs(int v)
{
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= n; i++)
	{
		if (map[v][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}
	}
	return;
}

int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	clr();
	dfs(v);

	cout << "\n";

	clr();
	bfs(v);

	return 0;
}