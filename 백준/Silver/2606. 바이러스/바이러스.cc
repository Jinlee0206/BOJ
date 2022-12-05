#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, res;
vector<int> adj[104];
int visited[104];

void dfs(int here)
{
	visited[here] = 1;

	for (int there : adj[here])
	{
		if (visited[there]) continue;
		dfs(there);
		res++;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	visited[1] = 1;
	dfs(1);

	cout << res << '\n';

	return 0;
}