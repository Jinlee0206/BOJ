#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <string>

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

	for (int i = 1; i <= n; i++)
	{
		cin >> population[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			adj[i].push_back(a);
			adj[a].push_back(i);
		}
	}

	// 비트마스킹을 통해 모든 경우의 수 체크, 0과 1<<n 은 One-side 이기 때문에 제외
	for (int i = 1; i < (1 << n) - 1; i++)
	{
		// Red, Blue 구역 색칠 초기화
		fill(comp, comp + 11, 0);
		// DFS 방문 지역 초기화
		fill(visited, visited + 11, 0);

		// dfs 시작 지점
		int idx1 = -1, idx2 = -1;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) {
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else idx2 = j + 1;
		}

		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);

		if (comp1.first + comp2.first == n) res = min(res, abs(comp1.second - comp2.second));
	}

	cout << (res == INF ? -1 : res) << "\n";

	return 0;
}