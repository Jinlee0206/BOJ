#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int _min = 2147000000;

int n, m, h, res = _min;
int ladder[31][31];

bool isManipulated()
{
	for (int i = 1; i <= n; i++)
	{
		int currentNum = i;

		for (int j = 1; j <= h; j++)
		{
			if (ladder[j][currentNum]) currentNum++;
			else if (ladder[j][currentNum - 1]) currentNum--;
		}
		if (currentNum != i) return false;
	}
	return true;
}

void dfs(int idx, int cnt)
{
	if (cnt >= 4 || cnt >= res) return;

	if (isManipulated() == true)
	{
		res = min(cnt, res);
		return;
	}

	for (int i = idx; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;
			ladder[i][j] = 1;
			dfs(i, cnt + 1);
			ladder[i][j] = 0;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> h;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	dfs(1, 0);

	if (res == _min) cout << -1 << "\n";
	else cout << res << "\n";

	return 0;
}