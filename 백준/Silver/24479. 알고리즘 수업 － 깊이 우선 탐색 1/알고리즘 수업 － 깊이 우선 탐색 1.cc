#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int n, m, r;
vector<int> vec[100001];
bool visited[100001];

int order = 0;
int res[100001];

void dfs(int here)
{
	if (visited[here] == true) return;
	
	visited[here] = true;
	res[here] = ++order;

	//cout << "path : " << here << "\n";

	for (int i = 0; i < vec[here].size(); i++)
	{
		int nxt = vec[here][i];
		dfs(nxt);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << res[i] << "\n";
	}

	return 0;
}