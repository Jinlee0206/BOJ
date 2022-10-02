#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, root;
vector<int> adj[51];

int dfs(int here)
{
	int res = 0, child = 0;

	for (int there : adj[here])
	{
		if (there == k) continue;
		res += dfs(there);
		child++;
	}
	// 자식이 없다면 리프노드
	if (child == 0) return 1;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == -1) root = i;
		else adj[tmp].push_back(i);
	}

	cin >> k;

	// DFS가 here -> there, there 기반 코드
	// root 노드에 대한 반례 필요
	if (k == root) cout << 0 << "\n";
	else cout << dfs(root) << "\n";

	return 0;
}